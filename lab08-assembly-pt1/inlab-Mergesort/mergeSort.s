; REESE ALLEN | rga2uz | mergeSort.s | 10-27-10	

	global _mergeSort
	global _merge

	section .text

; order of parameters ~ Calling Conventions: rdi, rsi, rdx, rcx, r8, r9 ; push rest onto stack in reverse order 
; caller-saved registers are r10, r11, and any registers that parameters are put into

; Parameter 1 is a pointer to the int array, in rdi 			
; Parameter 2 is the left index in the array, in rsi 		int l
; Parameter 3 is the right index in the array, in rdx 		int r
; Return type is void 

_mergeSort:
	
	; pseudocode :
	; int m = (l + r) / 2 	- middle index in array
	; mergeSort(rdi, rsi, m) - sort left half
	; mergeSort(rdi, m, rdx) - sort right half 
	; merge(rdi, rsi, m, rdx) - merge halves 


	; Save caller-saved registers
	; Store local variables


	push r10			; int l 		; move to stack
	push r11  			; int r 
	push r12 			; int m 

	xor rax, rax 		; zero-out return register 

	cmp rsi, rdx 		; does l == r ? 
	je _done			; if so, terminate 
	jmp _sort 			

_sort:
	; MIDDLE
	mov r10, rsi 		; r10: l 					mov register, register ~ both contain same data 
	mov r11, rdx 		; r11: r
	mov r12, r10 		; m = l
	add r12, r11 		; m = m + r
	shr r12, 1 			; shift register right one place ~ r12: m / 2 ; low bit carrying flag ~ round down

	; LEFT 
	mov rsi, r10
	mov rdx, r12  		; set new right index ~ r = m
	call _mergeSort 	; sort left half 

	; RIGHT 
	inc r12 			; r12: m + 1
	mov rsi, r12  		; rsi: r12 ~ set new left index ~ l = m + 1
	mov rdx, r11 		; r = r
	dec r12             ; r12 - 1
	call _mergeSort     ; sort right half


	; MERGE
	mov rsi, r10
	mov rcx, r11 
	mov rdx, r12 
	call _merge 		; merge two halves
	jmp _done


_done:
	pop r12 			; remove from stack 
	pop r11
	pop r10
	ret 				; return rax 	



; Parameter 1 is a pointer to the int array, in rdi
; Parameter 2 is the left index in the array, in rdi
; Parameter 3 is the middle index in the array, in rdx
; Parameter 4 is the right index in the array, in rcx
; Return type is void 

_merge:
	; Save callee-save registers
	; Store local variables 
	push rbx			; int i 	
	push r12			; int j
	push r13			; int k
	push r14			; int n1
	push r15			; int n2
	
	mov r14, rdx			; n1 = mid - left + 1
	sub r14, rsi
	inc r14

	mov r15, rcx			; n2 = right - mid 
	sub r15, rdx

	lea r11, [r14+r15]		; r11 = rsp offset = 4(n1 + n2)
	lea r11, [4*r11]		
	sub rsp, r11			; allocate space for temp arrays

	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	
; Copy elements of arr[] into L[]	
_copyLloop:
	cmp rbx, r14			; is i >= n1?
	jge _copyRloop
					; L[i] = arr[left + i]
	lea r10, [rsi+rbx]		
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[left + i]
	mov DWORD [rsp+4*rbx], r10d	; L[i] = r10
	inc rbx				; i++
	jmp _copyLloop

; Copy elements of arr[] into R[]
_copyRloop:
	cmp r12, r15			; is j >= n2?
	jge _endcopyR
 					; R[j] = arr[mid + 1 + j]
	lea r10, [rdx+r12+1]	
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[mid + 1 + j]
	lea rax, [r12+r14]		
	mov DWORD [rsp+4*rax], r10d	; R[j] = r10
	inc r12				; j++
	jmp _copyRloop

_endcopyR:	
	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	mov r13, rsi			; k = left

; Merge L[] and R[] into arr[]
_mergeLoop:
	cmp rbx, r14			; is i >= n1 or j >= n2?
	jge _loopL
	cmp r12, r15
	jge _loopL
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	; r10d = R[j]
	cmp DWORD [rsp+4*rbx], r10d	; is L[i] <= R[j]?
	jle _if
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]
	inc r12				; j++
	jmp _endif 
_if:
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i] 
	inc rbx				; i++
_endif:	
	inc r13				; k++	
	jmp _mergeLoop
	
; Copy elements of L[] into arr[]
_loopL:				
	cmp rbx, r14			; is i >= n1?
	jge _loopR
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i]
	inc rbx				; i++
	inc r13				; k++
	jmp _loopL

; Copy elements of R[] into arr[]
_loopR:	
	cmp r12, r15			; is j >= n2?
	jge _endR
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]

	inc r12				; j++
	inc r13				; k++
	jmp _loopR
	
_endR:
	; deallocate temp arrays
	; restore callee-save registers
	add rsp, r11	
	pop r15			
	pop r14
	pop r13
	pop r12
	pop rbx
	ret