TITLE Combinatoric Quizzer     (Project6b.asm)

; Author: Andrew Funk
; Email: funkand@oregonstate.edu
; Course ID: CS271-400
; Project ID: Program #6B
; Assignment Due Date: 03-18-18, 11:59pm
; Date: 03-12-18
; Description: This program displays a combinatorics problem and prompts the user to
;			   answer it. The program reports whether the answer is correct or not and 
;			   then asks the user if they would like another problem. This continues 
;			   until the user chooses to quit. Combinatorics answers are calculated 
;			   recursively and all user input is validated.

INCLUDE Irvine32.inc

mWrite		MACRO buffer
	push	edx   
	mov		edx, OFFSET buffer
	call	WriteString
	pop		edx
ENDM

mWriteRet	MACRO buffer
	push	edx   
	mov		edx, OFFSET buffer
	call	WriteString
	call	CrLf
	pop		edx
ENDM

mWriteChar	MACRO character
	push	eax
	mov		eax, character
	call	WriteChar
	pop		eax
ENDM

mFact		MACRO buffer, value
	push	buffer
	push	value
	call	factorial
ENDM

MIN_N = 3
MAX_N = 12
MIN_R = 1

.data

nVar			DWORD	?
rVar			DWORD	?
nFact			DWORD	?
rFact			DWORD	?
nrFact			DWORD	?
answer			DWORD	?
result			DWORD	?
continueFlag	DWORD	1
userEntry		BYTE	20 DUP(0)
progTitle		BYTE	"Are You Smarter Than A Combinatoric?", 0
progName		BYTE	"Programmed by Andrew Funk", 0
instructions_1	BYTE	"You're going to be shown a combinations problem. Answer how", 0
instructions_2	BYTE	"many combinations can be made with the given number of elements", 0
instructions_3	BYTE	"and subset size. I'll report if you answered correctly.", 0
problem			BYTE	"Problem:", 0
allElements		BYTE	"Number of elements in set: ", 0
subElements		BYTE	"Number of elements to choose from set: ", 0
comboText		BYTE	"How many combinations can be made? ", 0
invalidEntry	BYTE	"Invalid entry! Please try again.", 0
resultText_1	BYTE	"There are ", 0
resultText_1_1	BYTE	"There is ", 0
resultText_2	BYTE	" combinations of ", 0
resultText_2_1	BYTE	" combination of ", 0
resultText_3	BYTE	" from a set of ", 0
rightAnswer		BYTE	"You got it! Look at the big brain on you!", 0
wrongAnswer		BYTE	"You're wrong. Maybe you need to retake CS225?", 0
continueText	BYTE	"Would you like another problem? (y/n): ", 0
goodbye			BYTE	"Goodbye!", 0

.code
main PROC

	call		Randomize

	call		introduction

startNew:	
	push		OFFSET nVar
	push		OFFSET rVar
	call		showProblem

	mov			answer, 0					; initialize variable

	push		OFFSET answer
	push		OFFSET userEntry
	push		SIZEOF userEntry
	call		getData

	mov			nFact, 1					; initialize factorial variables
	mov			rFact, 1
	mov			nrFact, 1

	push		nVar
	push		rVar
	push		OFFSET nFact
	push		OFFSET rFact
	push		OFFSET nrFact
	push		OFFSET result
	call		combinations

	push		nVar
	push		rVar
	push		answer
	push		result
	call		showResults

	push		OFFSET continueFlag
	call		continue

	cmp			continueFlag, 1
	je			startNew

	mWriteRet	goodbye

	exit	; exit to operating system
main ENDP

;introduction - Procedure to introduce the program and display instructions.
;receives: none
;returns: none
;preconditions:  none
;registers changed: none
introduction PROC
	
	; display intro
	mWriteRet	progTitle
	mWriteRet	progName
	call		CrLf

	; display instructions
	mWriteRet	instructions_1
	mWriteRet	instructions_2
	mWriteRet	instructions_3

	ret
introduction ENDP

;showProblem - Calculates random n and r values and displays the combination problem
;receives: addresses of n and r variables
;returns: values of n and r saved in memory
;preconditions:  random number generator should be seeded
;registers changed: none
showProblem PROC
	; set up stack frame and save registers
	push		ebp
	mov			ebp, esp
	push		eax
	push		edi
	push		esi

	mov			edi, [ebp+12]			; put address of n in edi

	; use RandomRange to generate a random number from MIN_N to MAX_N in eax
	mov			eax, MAX_N
	sub			eax, MIN_N
	inc			eax
	call		RandomRange
	add			eax, MIN_N
	mov			[edi], eax				; put random number in n

	mov			edi, [ebp+8]			; put address of r in edi

	; use RandomRange to generate a random number from MIN_R to n in eax
	sub			eax, MIN_R
	inc			eax
	call		RandomRange
	add			eax, MIN_R
	mov			[edi], eax				; put random number in r

	; display problem to user
	call		CrLf
	mWriteRet	problem
	mWrite		allElements
	mov			esi, [ebp+12]
	mov			eax, [esi]
	call		WriteDec
	call		CrLf
	mWrite		subElements
	mov			esi, [ebp+8]
	mov			eax, [esi]
	call		WriteDec
	call		CrLf

	; restore registers and stack
	pop			esi
	pop			edi
	pop			eax
	pop			ebp
	ret			8
showProblem	ENDP

;getData - Receives and validates input from user until valid input received
;receives: addresses of answer and userEntry variables and size of userEntry buffer
;returns: value of answer returned in memory
;preconditions: none
;registers changed: none
getData PROC
	; set up stack frame and save registers
	push		ebp
	mov			ebp, esp
	pushad

	mov			edi, [ebp+16]

entryStart:
	mWrite		comboText
	
	; Read in an entry as a string
	mov			edx, [ebp+12]
	mov			ecx, [ebp+8]
	call		ReadString
	mov			ecx, eax					; save length in ecx
	mov			esi, [ebp+12]
	cmp			ecx, 11						; invalidate entries longer than 11 chars
	jge			badEntry

	; Validate each character
validationStart:
	mov			eax, [edi]					; setup base multiplier
	cdq
	imul		eax, 10
	mov			[edi], eax
	xor			eax, eax
	cld
	lodsb									; load a character
	cmp			al, 48						; check if character is in number range
	jl			badEntry
	cmp			al, 57
	jg			badEntry
	jmp			saveNumber

	; Get a new entry if invaid, clear anything saved as answer so far
badEntry:
	mWriteRet	invalidEntry
	mov			ecx, 0
	mov			[edi], ecx
	jmp			entryStart

	; Add value to running total stored at address in edi
saveNumber:
	sub			al, 48
	add			[edi], eax
	loop		validationStart

	; restore registers and stack
	popad
	pop			ebp
	ret			12
getData	ENDP

;combinations - Calculates the combinations based on n and r values
;receives: values of n and r, addresses of result and n, r, n-r factorials
;returns: value of result returned in memory
;preconditions: n and r must be less than or equal to 12
;registers changed: none
combinations	PROC
	; set up stack frame and save registers
	push		ebp
	mov			ebp, esp
	pushad

	mFact		[ebp+20], [ebp+28]			; calculate n!

	mFact		[ebp+16], [ebp+24]			; calculate r!

	mov			eax, [ebp+28]
	sub			eax, [ebp+24]
	mFact		[ebp+12], eax				; calculate (n-r)!

	; calculate r! x (n-r)! and save result in ebx
	mov			ebx, [ebp+16]
	mov			eax, [ebx]
	mov			ebx, [ebp+12]
	mov			ecx, [ebx]
	mul			ecx
	mov			ebx, eax

	; calculate n! / result of above in ebx
	mov			ecx, [ebp+20]
	mov			eax, [ecx]
	cdq
	div			ebx

	; save answer in address that was passed to procedure
	mov			edi, [ebp+8]
	mov			[edi], eax

	; restore registers and stack
	popad
	pop			ebp
	ret			24
combinations	ENDP

;factorial - Recursively calculates the factorial of a number
;receives: value of number and address to save factorial
;returns: value of factorial returned in memory
;preconditions: number must be <= 12 and >= 0
;registers changed: none
factorial  PROC
	; set up stack frame and save registers
	push		ebp
	mov			ebp, esp
	push		eax
	push		ebx
	push		edi

	mov			eax, [ebp+8]		; eax = number for factorial
	mov			edi, [ebp+12]		; @answer in edi

	cmp			eax, 0				; base case: number = 0
	je			quit
	
	; multiply running total in edi by eax value
	push		eax
	mov			ebx, [edi]
	mul			ebx					; multiply current value of factorial and number
	mov			[edi], eax
	pop			eax					; restore eax

	dec			eax					; decrement eax on each recursion
	push		edi
	push		eax
	call		factorial

	; restore registers and stack
quit:
	pop			edi
	pop			ebx
	pop			eax
	pop			ebp
	ret			8
factorial  ENDP

;showResults - Displays the result of the combination and the user's outcome
;receives: values of n, r, user's answer, and actual result
;returns: outputs results to screen
;preconditions: none
;registers changed: none
showResults  PROC
	; set up stack frame and save registers
	push		ebp
	mov			ebp, esp
	pushad

	; check if there is only one solution
	mov			eax, [ebp+8]
	cmp			eax, 1
	je			oneSolution

	; output result to screen (>1 solution)
	call		CrLf
	mWrite		resultText_1

	mov			eax, [ebp+8]
	call		WriteDec

	mWrite		resultText_2
	jmp			remainingText

	; output result to screen (1 solution)
oneSolution:
	call		CrLf
	mWrite		resultText_1_1

	mov			eax, [ebp+8]
	call		WriteDec

	mWrite		resultText_2_1

	; finish result output
remainingText:
	mov			eax, [ebp+16]
	call		WriteDec

	mWrite		resultText_3

	mov			eax, [ebp+20]
	call		WriteDec
	mWriteChar	'.'
	call		CrLf

	; check user's answer against solution, display appropriate result
	mov			eax, [ebp+8]
	cmp			eax, [ebp+12]
	jne			incorrect

	mWriteRet	rightAnswer
	jmp			displayDone

incorrect:
	mWriteRet	wrongAnswer

displayDone:
	; restore registers and stack
	call		CrLf
	popad
	pop			ebp
	ret			16
showResults  ENDP

;continue - Checks to see if the user wishes to continue getting problems
;receives: address of a continue flag
;returns: 1 or 0 in the continue flag depending on user choice
;preconditions: none
;registers changed: none
continue  PROC
	; set up stack frame and save registers
	push		ebp
	mov			ebp, esp
	push		edi
	push		eax
	
	mov			edi, [ebp+8]

continueStart:
	mWrite		continueText

	; read in a character
	call		ReadChar
	call		CrLf

	; check if character is y or n
	cmp			al, 'y'
	je			ySuccess
	cmp			al, 'Y'
	je			ySuccess
	cmp			al, 'n'
	je			nSuccess
	cmp			al, 'N'
	je			nSuccess
	
	; get new entry if not y or n
	mWriteRet	invalidEntry
	jmp			continueStart

	; set flag for y or n entry
ySuccess:
	mov			eax, 1
	mov			[edi], eax
	jmp			finish

nSuccess:
	mov			eax, 0
	mov			[edi], eax

finish:
	; restore registers and stack
	pop			eax
	pop			edi
	pop			ebp
	ret			4
continue  ENDP

END main