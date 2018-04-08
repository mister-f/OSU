TITLE CS271 Composite Numbers     (Program4.asm)

; Author: Andrew Funk
; Email: funkand@oregonstate.edu
; Course ID: CS271-400
; Project ID: Program #4
; Assignment Due Date: 02-18-18, 11:59pm
; Date: 02-17-18
; Description: This program prompts the user to enter a number of composite
;			   numbers to generate in the range of 1 to 400. The program then
;			   calculates the specified number of composite numbers and 
;			   displays them 10 per line. The program is separated into several
;			   different procedures.

INCLUDE Irvine32.inc

FALSE = 0
TRUE = 1
TERMS_PER_LINE = 10
LOWER_LIMIT	= 1
UPPER_LIMIT = 400

.data

userEntry		DWORD	?
validNumber		DWORD	0
notPrime		DWORD	?
testNumber		DWORD	3
lineCounter		DWORD	0
progTitle		BYTE	"Composite Numbers", 0
progName		BYTE	"Programmed by Andrew Funk", 0
instructions_1	BYTE	"Please enter the number of composite numbers to list.", 0
instructions_2	BYTE	"The number must be between 1 and 400.", 0
getTerms		BYTE	"Enter a number of composites to list (1-400): ", 0
invalid			BYTE	"Invalid entry. Please try again.", 0
threeSpaces		BYTE	"	", 0
goodbye			BYTE	"Hooray! It worked! Bye!", 0
extraCredit		BYTE	"**EC: This program displays the numbers in aligned columns.", 0

.code
main PROC

	call	introduction
	call	getUserData
	call	showComposites
	call	farewell

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
	mov		edx, OFFSET extraCredit
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
	call	CrLf

	ret
introduction ENDP

;getUserData - Procedure to receive a number from the user.
;receives: none
;returns: Number of composites to display stored in userEntry
;preconditions:  none
;registers changed: eax, edx

getUserData PROC
	; loop to ask user for data
entryStart:
	mov		edx, OFFSET getTerms
	call	WriteString
	call	ReadInt
	mov		userEntry, eax

	; call validate function to see if entry is valid
	call	validate
	cmp		validNumber, 0
	je		entryStart

	ret
getUserData ENDP

;validate - Procedure to make sure entered value is in a valid range.
;receives: userEntry stored as global variable
;returns: validNumber will be 1 (valid entry) or 0 (invalid entry)
;preconditions:  none
;registers changed: eax, edx

validate PROC
	; verify entry is above 0
	cmp		userEntry, LOWER_LIMIT
	jl		badEntry

	; verify entry is below 400
	cmp		userEntry, UPPER_LIMIT
	jg		badEntry

	; set validNumber to true and return if entry in range
	mov		eax, TRUE
	mov		validNumber, eax
	ret

	; display error message if entry is invalid
badEntry:
	mov		edx, OFFSET invalid
	call	WriteString
	call	CrLf
	ret

validate ENDP

;showComposites - Procedure to display composite numbers, 10 per line.
;receives: userEntry, lineCounter, and testNumber, all stored as global 
;		   variables
;returns: none
;preconditions:  userEntry is positive
;registers changed: eax, ebx, ecx, edx

showComposites PROC
	call	CrLf
	mov		ecx, userEntry
	
	; loop through numbers, printing composites
loopStart:
	inc		testNumber
	call	isComposite
	
	; check if number is composite, if not then jump to start of loop
	cmp		notPrime, 0
	je		loopStart
	
	; print number if composite
	mov		eax, testNumber
	call	WriteDec
	mov		edx, OFFSET threeSpaces
	call	WriteString
	
	; use lineCounter to determine if 10 numbers have been printed on a line
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

	ret
showComposites ENDP

;isComposite - Procedure to test whether a number is composite.
;receives: number to test as testNumber, a global variable
;returns: notPrime will be 1 (composite) or 0 (not composite)
;preconditions:  none
;registers changed: eax, ebx, edx

isComposite PROC
	mov		ebx, 2
	
	; divide testNumber with 2 through n-1
testStart:
	mov		eax, testNumber
	cdq
	div		ebx
	cmp		edx, 0
	
	; jump out of loop if number is evenly divisible
	je		trueComposite
	inc		ebx
	
	; check if divisor is equal to dividend, number is prime if true
	cmp		ebx, testNumber
	je		falseComposite
	jmp		testStart

falseComposite:
	mov		eax, FALSE
	mov		notPrime, eax
	ret

trueComposite:
	mov		eax, TRUE
	mov		notPrime, eax
	ret
isComposite ENDP

;farewell - Procedure to display a farewell message.
;receives: none
;returns: none
;preconditions:  none
;registers changed: edx

farewell PROC
	; display farewell message
	call	CrLf
	call	CrLf
	mov		edx, OFFSET goodbye
	call	WriteString
	call	CrLf
	call	CrLf

	ret
farewell ENDP

END main
