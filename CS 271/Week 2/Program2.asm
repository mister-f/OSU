TITLE CS271 Fibonacci Numbers    (Program2.asm)

; Author: Andrew Funk
; Email: funkand@oregonstate.edu
; Course ID: CS271-400
; Project ID: Program #2
; Assignment Due Date: 01-28-18, 11:59pm
; Date: 01-26-18
; Description: This program first gets the user's name as input and greets the 
;			   user. It then gives instructions for further input and asks for
;			   the number of terms in the Fibonacci sequence to display (up to 
;			   a limit of 46). The input is validated as being between 1 and 46
;			   and then the specified number of terms is displayed 5 per line
;			   in aligned columns. It then gives a farwell statement
;			   referencing the user by name.

INCLUDE Irvine32.inc

UPPER_LIMIT = 46
LOWER_LIMIT = 1
TERMS_PER_LINE = 5
TOO_MANY_DIGITS = 35

.data

userName		BYTE	33 DUP(0)
numberTerms		DWORD	?
firstFib		DWORD	0
secondFib		DWORD	1
tempFib			DWORD	?
counter			DWORD	0
progTitle		BYTE	"Fibonacci Numbers", 0
progName		BYTE	"Programmed by Andrew Funk", 0
getName			BYTE	"Howdy partner! What's your name? ", 0
greet			BYTE	"Well I'm just tickled pink to meet you ", 0
instructions_1	BYTE	"I need you to tell me how many Fibonacci numbers y'all want.", 0
instructions_2	BYTE	"Make sure that there number is an integer from 1 to 46.", 0
getTerms		BYTE	"Now, how many terms do y'all want: ", 0
entryError		BYTE	"Gosh darn it! That ain't a number from 1 to 46!", 0
period			BYTE	".", 0
tabSpace		BYTE	"	", 0
goodbye			BYTE	"Well look at all them pretty numbers! Couldn't have done it without you, ", 0
extraCredit		BYTE	"**EC: This program displays the numbers in aligned columns.", 0

.code
main PROC

; (introduction) Display program title and programmer name
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

; Get users name and greet user
	mov		edx, OFFSET getName
	call	WriteString
	mov		edx, OFFSET userName
	mov		ecx, 32
	call	ReadString
	mov		edx, OFFSET greet
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	mov		edx, OFFSET period
	call	WriteString
	call	CrLf	
	call	CrLf

; (userInstructions) Ask for a number of terms to display from user (from 1 to 46)
	mov		edx, OFFSET instructions_1
	call	WriteString
	call	CrLf	
	mov		edx, OFFSET instructions_2
	call	WriteString
	call	CrLf	
	call	CrLf

; (getUserData) Get and validate user input
startInput:
	mov		edx, OFFSET getTerms
	call	WriteString
	call	ReadInt
	mov		numberTerms, eax
	; Check entered numbers, jump to error message if out of range
	cmp		numberTerms, LOWER_LIMIT
	jl		outOfRange
	cmp		numberTerms, UPPER_LIMIT
	jg		outOfRange
	jmp		calculation
outOfRange:
	; Display error message and jump back to get new input
	mov		edx, OFFSET entryError
	call	WriteString
	call	CrLf
	jmp		startInput

; (displayFibs) Calculate and display entered number of terms in Fibonacci sequence
calculation:
	call	CrLf
	mov		ecx, numberTerms					; initialize loop counter
loopStart:
	inc		counter
	mov		eax, secondFib
	call	WriteDec
	mov		edx, OFFSET tabSpace
	call	WriteString
	; Check for large numbers and skip a tab to preserve correct spacing
	mov		eax, counter
	cmp		counter, TOO_MANY_DIGITS
	jg		oneTab
	mov		edx, OFFSET tabSpace
	call	WriteString
oneTab:
	; Perform the calculation for the next number
	mov		eax, secondFib
	mov		ebx, firstFib
	mov		tempFib, eax
	add		eax, ebx
	mov		secondFib, eax
	mov		eax, tempFib
	mov		firstFib, eax
	
	; Check to see if 5 numbers have been printed on one line
	mov		eax, counter
	mov		ebx, TERMS_PER_LINE
	mov		edx, 0
	div		ebx
	cmp		edx, 0
	jnz		noReturn
	call	CrLf
noReturn:
	loop	loopStart

; (farewell) Display goodbye meesage with user's name.
	call	CrLf
	call	CrLf
	mov		edx, OFFSET goodbye
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	mov		edx, OFFSET period
	call	WriteString
	call	CrLf	

	exit	; exit to operating system
main ENDP

END main
