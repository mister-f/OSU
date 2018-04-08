TITLE CS271 Integer Accumulator     (template.asm)

; Author: Andrew Funk
; Email: funkand@oregonstate.edu
; Course ID: CS271-400
; Project ID: Program #3
; Assignment Due Date: 02-11-18, 11:59pm
; Date: 02-10-18
; Description: This program greets the user, and then displays instructions to 
;			   enter numbers in the range from -100 to -1. Once the user enters
;			   a number 0 or greater, the total sum of valid numbers entered is
;			   displayed, as well as the average rounded to the nearest integer.
;			   The program then displays a goodbye message.

INCLUDE Irvine32.inc

UPPER_BOUND = -1
LOWER_BOUND = -100

.data

userName		BYTE	33 DUP(0)
userEntry		SDWORD	?
sum				SDWORD	0
average			SDWORD	0
remainder		SDWORD	?
roundFactor		DWORD	2
entryCount		DWORD	0
lineNumber		DWORD	1
progTitle		BYTE	"Integer Accumulator", 0
progName		BYTE	"Programmed by Andrew Funk", 0
getName			BYTE	"Greetings user, what shall I call you? ", 0
greet			BYTE	"It is my pleasure to make your acquaintance, ", 0
instructions_1	BYTE	"Please enter numbers in the range from -100 to -1, inclusive.", 0
instructions_2	BYTE	"When you want to stop, enter a non-negative number", 0
getTerms		BYTE	"| Enter a number: ", 0
entry_1			BYTE	"You entered ", 0
entry_2			BYTE	" valid numbers.", 0
sumDisplay		BYTE	"The sum of valid entries is ", 0
avgDisplay		BYTE	"The rounded average is ", 0
zeroEntries		BYTE	"No valid numbers were entered.", 0
period			BYTE	".", 0
goodbye			BYTE	"We did it. Together. As a team. Thanks, ", 0
extraCredit		BYTE	"**EC: This program displays line numbers during user number input.", 0

.code
main PROC

; Display program title and programmer name
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

; Get user's name and greet user
	mov		edx, OFFSET getName
	call	WriteString
	mov		edx, OFFSET userName
	mov		ecx, SIZEOF userName
	call	ReadString
	mov		edx, OFFSET greet
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	mov		edx, OFFSET period
	call	WriteString
	call	CrLf	
	call	CrLf

; Display instructions to user
	mov		edx, OFFSET instructions_1
	call	WriteString
	call	CrLf	
	mov		edx, OFFSET instructions_2
	call	WriteString
	call	CrLf	
	call	CrLf

; Prompt user to enter valid numbers
enterNumbers:
	mov		eax, lineNumber
	call	WriteDec
	inc		lineNumber
	mov		edx, OFFSET getTerms
	call	WriteString
	call	ReadInt
	mov		userEntry, eax
	cmp		userEntry, LOWER_BOUND			
	jl		invalid						; invalid number if < -100
	cmp		userEntry, UPPER_BOUND
	jg		entryFinish					; done entering if > -1
	jmp		valid
invalid:
	jmp		enterNumbers
valid:
	inc		entryCount					; valid entry, increment count
	mov		eax, userEntry					
	add		sum, eax					; add entered value to running sum
	jmp		enterNumbers				; loop to get another entry

; Calculate the rounded average of valid numbers
entryFinish:
	cmp		entryCount, 0				; skip calculations if no valid entries
	je		noNumbers
	mov		eax, sum
	cdq
	idiv	entryCount					; calculate average
	mov		average, eax
	mov		remainder, edx
	neg		remainder
	mov		eax, remainder
	mul		roundFactor					; multiply remainder of average by 2
	cmp		eax, entryCount				; determine if rounding occurs by 
										; comparing remainder to number of entries
	jle		noRound						
	dec		average						; round average down
noRound:

; Display total number of valid entries, the sum, and the rounded average
	call	CrLf
	mov		edx, OFFSET entry_1
	call	WriteString
	mov		eax, entryCount
	call	WriteDec
	mov		edx, OFFSET entry_2
	call	WriteString
	call	CrLf
	mov		edx, OFFSET sumDisplay
	call	WriteString
	mov		eax, sum
	call	WriteInt
	mov		edx, OFFSET period
	call	WriteString
	call	CrLf
	mov		edx, OFFSET avgDisplay
	call	WriteString
	mov		eax, average
	call	WriteInt
	mov		edx, OFFSET period
	call	WriteString
	call	CrLf
	call	CrLf
	jmp		goodbyeMessage
noNumbers:								; Display special message if no entries
	call	CrLf
	mov		edx, OFFSET zeroEntries
	call	WriteString
	call	CrLf
	call	CrLf

; Display goodbye message
goodbyeMessage:
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