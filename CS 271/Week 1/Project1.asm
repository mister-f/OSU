TITLE CS271 Program #1     (Project1.asm)

; Author: Andrew Funk
; Course / Project ID:   CS271 / Program #1     
; Date: 01-18-18
; Description: This program prints an introduction and instructions, gets 
; two numbers from the user, calculates the sum, difference, product and 
; quotient/remainder of those numbers. It displays the results and gives a
; goodbye statement.

INCLUDE Irvine32.inc

SCALE_FACTOR = 1000

.data

number_1		DWORD	?
number_2		DWORD	?
sum				DWORD	?
difference		DWORD	?
product			DWORD	?
quotient		DWORD	?
remainder		DWORD	?
beforeDecimal	DWORD	?
afterDecimal	DWORD	?
continue		DWORD	?
intro			BYTE	"Basic Mathematicals by Andrew Funk", 0
instructions	BYTE	"Enter two numbers and I'll return the sum, difference, product, quotient, and remainder.", 0
firstEntry		BYTE	"Enter the first number: ", 0
secondEntry		BYTE	"Enter the second number: ", 0
plus			BYTE	" + ", 0
minus			BYTE	" - ", 0
times			BYTE	" x ", 0
divide			BYTE	" / ", 0
equals			BYTE	" = ", 0
remainderText	BYTE	" remainder ", 0
period			BYTE	".", 0
goodbye			BYTE	"Are you not entertained?!? Bye!", 0
entryProblem	BYTE	"The second number must be less than the first!", 0
startAgain		BYTE	"Would you like to do some mathematicals again? (1 = yes, 0 = no): ", 0
extraCredit1	BYTE	"**EC: Program repeats until user quits", 0
extraCredit2	BYTE	"**EC: Program verifies the second number is less than the first", 0
extraCredit3	BYTE	"**EC: Program displays division result in decimal form", 0

.code
main PROC

; Introduce program, display instructions
	mov		edx, OFFSET intro
	call	WriteString
	call	CrLf
	mov		edx, OFFSET extraCredit1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET extraCredit2
	call	WriteString
	call	CrLf
;	mov		edx, OFFSET extraCredit3
;	call	WriteString
;	call	CrLf

beginning:
	call	CrLf
	mov		edx, OFFSET instructions
	call	WriteString
	call	CrLf
	call	CrLf

; Get data from user
	mov		edx, OFFSET firstEntry
	call	WriteString
	call	ReadInt
	mov		number_1, eax

	mov		edx, OFFSET secondEntry
	call	WriteString
	call	ReadInt
	mov		number_2, eax
	call	CrLf

; *EC* Validate the second number is less than (or equal to) the first
	mov		eax, number_1
	cmp		eax, number_2
	jge		calculation
	mov		edx, OFFSET entryProblem
	call	WriteString
	call	CrLf
	jmp		byebye

calculation:
; Calculate required mathematic results
	; Perform addition
	mov		eax, number_1
	mov		ebx, number_2
	add		eax, ebx
	mov		sum, eax

	; Perform subtraction
	mov		eax, number_1
	mov		ebx, number_2
	sub		eax, ebx
	mov		difference, eax

	; Perform multiplication
	mov		eax, number_1
	mov		ebx, number_2
	mul		ebx
	mov		product, eax

	; Perform division
	mov		eax, number_1
	mov		ebx, number_2
	mov		edx, 0
	div		ebx
	mov		quotient, eax
	mov		remainder, edx

;	; *EC: Calculate decimal portion
;	mov		eax, number_1
;	mov		ebx, SCALE_FACTOR
;	mul		ebx
;	mov		ebx, number_2
;	mov		edx, 0
;	div		ebx
;	mov		ebx, SCALE_FACTOR
;	mov		edx, 0
;	div		ebx
;	mov		beforeDecimal, eax
;	mov		afterDecimal, edx

; Display results to user
	; Display sum
	mov		eax, number_1
	call	WriteDec
	mov		edx, OFFSET plus
	call	WriteString
	mov		eax, number_2
	call	WriteDec
	mov		edx, OFFSET equals
	call	WriteString
	mov		eax, sum
	call	WriteDec
	call	CrLf
	
	; Display difference
	mov		eax, number_1
	call	WriteDec
	mov		edx, OFFSET minus
	call	WriteString
	mov		eax, number_2
	call	WriteDec
	mov		edx, OFFSET equals
	call	WriteString
	mov		eax, difference
	call	WriteDec
	call	CrLf

	; Display product
	mov		eax, number_1
	call	WriteDec
	mov		edx, OFFSET times
	call	WriteString
	mov		eax, number_2
	call	WriteDec
	mov		edx, OFFSET equals
	call	WriteString
	mov		eax, product
	call	WriteDec
	call	CrLf

	; Display remainder/quotient
	mov		eax, number_1
	call	WriteDec
	mov		edx, OFFSET divide
	call	WriteString
	mov		eax, number_2
	call	WriteDec
	mov		edx, OFFSET equals
	call	WriteString
	mov		eax, quotient
	call	WriteDec
	mov		edx, OFFSET remainderText
	call	WriteString
	mov		eax, remainder
	call	WriteDec
	call	CrLf

	; *EC: Display division result in decimal form
;	mov		eax, number_1
;	call	WriteDec
;	mov		edx, OFFSET divide
;	call	WriteString
;	mov		eax, number_2
;	call	WriteDec
;	mov		edx, OFFSET equals
;	call	WriteString
;	mov		eax, beforeDecimal
;	call	WriteDec
;	mov		edx, OFFSET period
;	call	WriteString
;	mov		eax, afterDecimal
;	call	WriteDec
;	call	CrLf

byebye:
; *EC: Check if user wants to continue
	call	CrLf
	mov		edx, OFFSET startAgain
	call	WriteString
	call	ReadInt
	mov		continue, eax
	cmp		continue, 0
	jnz		beginning

; Display goodbye statement
	call	CrLf
	mov		edx, OFFSET goodbye
	call	WriteString
	call	CrLf
	call	CrLf

	exit	; exit to operating system
main ENDP

END main
