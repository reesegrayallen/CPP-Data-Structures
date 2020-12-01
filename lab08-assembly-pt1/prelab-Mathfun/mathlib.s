; REESE ALLEN | rga2uz | mathlib.s | 10-26-20
; 
; Purpose: This file contains the implementation of the functions (routines) product,
;			which returns the product of two integers, and power, which returns the 
;			result of raising the first integer to the second
;
; Parameter 1 (in rdi) is int x
; Parameter 2 (in rsi) is int y



	global product

	section .text


product:
	
	xor rax, rax		; zero out return register
	xor r10, r10		; zero out counter  ( r10 will be our iterator upwards [because we can only use addition?] )

start: 
 	; want to add x to itself y times [values in rdi and rsi never change]
	cmp r10, rsi 	; does i == y ?
	je done			; if so, done with loop
	add rax, rdi 	; add x (held by rsi) to return value (held by rax)
	inc r10			; i++
	jmp start		; loop to compare

done:
	ret 			; return rax




	global power

	section .text

power:
	xor rax, rax

recurse:
	cmp rsi, 0 	 	; does y = 0 ?
	je one 			; if so, done with loop
	dec rsi 		; y --
	call power		; 
	mov rsi, rax 	; move rax into rsi
	call product	; rdi * rsi
	jmp end

end:
	ret 			; return rax

one:
	mov rax, 1		; n ^ 0 = 1
	ret 
