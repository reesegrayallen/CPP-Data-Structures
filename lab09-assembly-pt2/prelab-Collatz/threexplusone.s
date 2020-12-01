; REESE ALLEN | rga2uz | threexplusone.cpp | 11-01-20

; Parameter 1 (in rdi) is positive integer to which the Collatz conjecture is applied 

; optimizations:
; using combination of shifts and adds instead of imul for multiplication - had trouble using lea :(
; removed jmp to _odd - tried to eliminate as much branching as possible
; avoided push and pop - reduce memory access
; used test for determining even and odd - less instructions 

; pseudocode:
; int i = 0
; collatz(x){
; if x = 1 {return i}
; if even { x = x / 2; i++; return collatz(x)}
; else {x = 3x + 1; i++; return collatz(x)}


	global _threexplusone

	section .text

_threexplusone:
	cmp	rdi, 1
	je	_zero

	test rdi, 1
	jz	_even
	mov r10, rdi
	shl rdi, 2
	sub rdi, r10
	inc rdi
	call _threexplusone
	jmp _end

_even:
	shr rdi, 1
	call _threexplusone

_end:
	inc rax
	jmp _done

_zero:
	mov	rax, 0
	
_done:
	ret