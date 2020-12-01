; REESE ALLEN | rga2uz | linearSearch.s | 10-29-10	


	global linearSearch 

	section .text


; Parameter 1 is a pointer to an int array, in rdi  			
; Parameter 2 is the size of the array, in rsi 					(int s) 			~ esi 
; Parameter 3 is the target element of the search, in rdx		(int t) 			~ edx


linearSearch:

	; pseudocode:
	; int linearSearch(int arr[], int s, int t)
	; 	int i
	;	for (i = 0; i < n)
	; 		if (arr[i] == x)
	;			return i
	;		return -1


	;xor rax, rax 				; zero out return register  		~ eax
	xor r10, r10 				; r10: i  ~ initially 0

	
loop:
	cmp r10, rsi 				; does i == s?
	jge notFound				; if i > s, terminate
	mov rax, [rdi + r10*4]		; rax: a[i]
	cmp eax, edx 				; does a[i] == t ?
	je end 					; if so, jump to end to return i	
	inc r10 					; i++
	jmp loop 					; loop

notFound:
	; set result to -1
	xor rax, rax 
	dec rax						; rax: 0 -1
	ret 						; return -1

end:
	mov rax, r10				; r10: i
	ret 	 					; return i
