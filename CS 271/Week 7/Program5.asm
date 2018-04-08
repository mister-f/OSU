TITLE Random Integer Array Sorting    (Program 5.asm)

; Author: Andrew Funk
; Email: funkand@oregonstate.edu
; Course ID: CS271-400
; Project ID: Program #5
; Assignment Due Date: 03-04-18, 11:59pm
; Date: 02-26-18
; Description: This program asks the user for an amount of numbers and that 
;			   amount of numbers is randomly generated and filled into an 
;			   array. The contents of the array are displayed, the array is
;			   sorted, and then the sorted array is displayed. Random numbers 
;			   are generated in the range of 100-999.

INCLUDE Irvine32.inc

MIN = 10
MAX = 200
LO = 100
HI = 999
FALSE = 0
TRUE = 1
TERMS_PER_LINE = 10

.data

request			DWORD	?
validNumber		DWORD	0
randArray		DWORD	MAX DUP(?)
progTitle		BYTE	"Random Integer Array Sorting", 0
progName		BYTE	"Programmed by Andrew Funk", 0
instructions_1	BYTE	"This program fills an array with the amount of random numbers", 0
instructions_2	BYTE	"requested, displays the array, sorts the array, displays the", 0
instructions_3	BYTE	"median, and then finally the sorted array.", 0
getTerms		BYTE	"Enter an amount of numbers to generate (10-200): ", 0
invalid			BYTE	"Invalid entry. Please try again.", 0
unsortedTitle	BYTE	"The unsorted numbers:", 0
sortedTitle		BYTE	"The sorted numbers:", 0
medianText		BYTE	"The median is ", 0
period			BYTE	".", 0

.code
main PROC

	call	Randomize

	call	introduction

	push	OFFSET validNumber
	push	OFFSET request
	call	getData

	push	request
	push	OFFSET randArray
	call	fillArray

	push	OFFSET unsortedTitle
	push	OFFSET randArray
	push	request
	call	displayList

	push	OFFSET randArray
	push	request
	call	sortList
	
	push	OFFSET randArray
	push	request
	call	displayMedian

	push	OFFSET sortedTitle
	push	OFFSET randArray
	push	request
	call	displayList

	exit	; exit to operating system
main ENDP

;introduction - Procedure to introduce the program and display instructions.
;receives: none
;returns: none
;preconditions:  none
;registers changed: edx
introduction PROC
	; display intro
	mov		edx, OFFSET progTitle
	call	WriteString
	call	CrLf
	mov		edx, OFFSET progName
	call	WriteString
	call	CrLf
	call	CrLf

	; display instructions
	mov		edx, OFFSET instructions_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instructions_2
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instructions_3
	call	WriteString
	call	CrLf
	call	CrLf

	ret
introduction ENDP

;getData - Procedure to receive a number from the user.
;receives: addresses of validation flag and number on stack, in that order
;returns: validated user input value for request
;preconditions: none
;registers changed: eax, ebx, edx, edi
getData PROC
	
	push	ebp						
	mov		ebp, esp				; setup stack
	mov		edi, [ebp+8]			; edi = user's number
	mov		ebx, [ebp+12]			; ebx = validation flag

	; loop to ask user for data
entryStart:
	mov		edx, OFFSET getTerms
	call	WriteString
	call	ReadInt
	mov		[edi], eax				; indirect addressing to save variable

	; call validate function to see if entry is valid
	push	edi
	push	ebx
	call	validate
	mov		eax, FALSE				
	cmp		[ebx], eax				; check validation flag status
	je		entryStart				; get new number if entry invaid

	pop	ebp
	ret 8							; clean stack
getData ENDP

;validate - Procedure to make sure entered value is in a valid range.
;receives: addresses of a number and a validation flag in that order
;returns:  validation flag will be 1 (valid entry) or 0 (invalid entry)
;preconditions:  none
;registers changed: eax, ecx, edx, esi

validate PROC
	push	ebp
	mov		ebp, esp
	mov		esi, [ebp+12]			; esi = user's number
	mov		ecx, [ebp+8]			; ecx = validation flag

	; verify entry is above MIN
	mov		eax, MIN
	cmp		[esi], eax
	jl		badEntry

	; verify entry is below MAX
	mov		eax, MAX
	cmp		[esi], eax
	jg		badEntry

	; set ecx indirect address to true and return if entry in range
	mov		eax, TRUE
	mov		[ecx], eax
	pop		ebp
	ret		8						; clean stack

	; display error message if entry is invalid
badEntry:
	mov		edx, OFFSET invalid
	call	WriteString
	call	CrLf
	
	pop		ebp
	ret		8						; clean stack
validate ENDP

;fillArray - Fills an array with random number in range [LO...HI]
;receives: an array size and address of an array in that order
;returns: array will be filled with an amount of numbers equal to size
;preconditions:  array size is less than MAX
;registers changed: eax, ecx, edi
fillArray PROC
	; set up stack
	push	ebp
	mov		ebp, esp
	mov		edi, [ebp+8]			; edi = array address
	mov		ecx, [ebp+12]			; ecx = number of elements

addAnother:
	; use RandomRange to generate a random number from LO to HI in eax
	mov		eax, HI
	sub		eax, LO
	inc		eax
	call	RandomRange
	add		eax, LO

	; put random number into array
	mov		[edi], eax
	add		edi, 4
	loop	addAnother

	;clean stack
	pop		ebp
	ret		8
fillArray ENDP

lineCounter	EQU	DWORD PTR [ebp-4]	; local variable symbol

;displayList - Displays an array of numbers along with a title
;receives: address of array title, address of an array and array size, in that order
;returns: none
;preconditions:  none
;registers changed: eax, ebx, ecx, edx, esi
displayList PROC
	; set up stack
	push	ebp
	mov		ebp, esp
	
	; create space on stack for a line counter
	sub		esp, 4
	mov		lineCounter, 0
	
	mov		esi, [ebp+12]			; esi = array address
	mov		edx, [ebp+16]			; edx = title to display
	mov		ecx, [ebp+8]			; ecx = arrazy size

	; display array title
	call	CrLf
	call	WriteString
	call	CrLf

loopStart:
	; display array element and a tab space
	mov		eax, [esi]
	call	WriteDec
	mov		al, '	'
	call	WriteChar
	add		esi, 4

	; determine if 10 numbers have been printed on a line
	inc		lineCounter
	mov		eax, lineCounter
	mov		ebx, TERMS_PER_LINE
	mov		edx, 0
	div		ebx
	cmp		edx, 0
	jne		noReturn
	call	CrLf

noReturn:
	loop	loopStart

	call	CrLf
	call	CrLf

	; clean up stack
	mov		esp, ebp
	pop		ebp
	ret		12
displayList ENDP

;sortList - Sorts an array of integers in descending order (using selection sort)
;receives: address of array and array size pushed on stack
;returns: a sorted array at the array memory location
;preconditions: array must have elements
;registers changed: ebx, ecx, edx, edi, esi
sortList PROC
	push	ebp
	mov		ebp, esp

	mov		ecx, [ebp+8]
	mov		esi, [ebp+12]
	
	dec		ecx
	
outerLoop:
	mov		edi, esi				; save array start address
	push	esi						; push array address to stack
	push	ecx						; save counter on stack
indexLoop:
	; move edi to array address holding last unsorted element
	add		edi, 4					
	loop	indexLoop
	mov		esi, edi				; save last unsorted address in esi
	pop		ecx						; restore counter
	mov		ebx, edi				; save last unsorted address in ebx
	push	ecx						; save outer loop counter on stack

innerLoop:
	; compare last unsorted value to each value prior to it in the array
	; saving the highest value into edi each time, after inner loop edi
	; will hold the address of the highest current unsorted value
	sub		ebx, 4 
	mov		edx, [ebx]
	cmp		edx, [edi]
	jge		noUpdate
	mov		edi, ebx
noUpdate:
	loop	innerLoop

	pop		ecx						; restore outer loop counter

	; push the highest unsorted element and last unosrted element
	; addresses onto stack and swap them
	push	edi						
	push	esi
	call	swapElement
	pop		esi						; restore esi to point to start of array
	loop	outerLoop

	pop		ebp
	ret		8
sortList ENDP

;displayMedian - Calculates the median of an array of integers and displays it.
;receives: address of array and array size pushed on stack
;returns: outputs median value of array to screen.
;preconditions: array must have elements in it
;registers changed: eax, ebx, edx, esi
displayMedian PROC
	push	ebp
	mov		ebp, esp

	mov		esi, [ebp+12]
	mov		eax, [ebp+8]
	mov		ebx, 2

	; determine if number of elements is even or odd
	cdq
	div		ebx
	cmp		edx, 0
	je		evenNumber

	; if odd, move middle value of array to eax
	mov		ebx, 4
	mul		ebx
	add		esi, eax
	mov		eax, [esi]
	jmp		output

evenNumber:
	; if even, calculate average of middle two values
	mov		ebx, 4
	mul		ebx
	add		esi, eax
	mov		eax, [esi]			; get one middle value into eax
	sub		esi, 4
	mov		ebx, [esi]			; get other middle value into ebx
	add		eax, ebx
	cdq		
	mov		ebx, 2	
	div		ebx					; get average of values
	add		eax, edx			; add remainder to round value if necessary

output:
	; display value to screen with text
	mov		edx, OFFSET medianText
	call	WriteString
	call	WriteDec
	mov		edx, OFFSET period
	call	WriteString
	call	CrLf

	pop		ebp
	ret		8
displayMedian ENDP

;swapElement - Swaps values stored in two memory locations
;receives: two memory addresses passed on stack
;returns: values stored at addresses will be swapped
;preconditions:  none
;registers changed: eax, edx
swapElement PROC
	push	ebp
	mov		ebp, esp
	push	ebx					; save value of ebx register

	mov		eax, [ebp+8]
	mov		edx, [ebp+12]

	; use ebx register to temporarily hold value to swap
	mov		ebx, [eax]
	xchg	ebx, [edx]
	mov		[eax], ebx

	pop		ebx					; restore ebx
	pop		ebp
	ret		8
swapElement ENDP

END main
