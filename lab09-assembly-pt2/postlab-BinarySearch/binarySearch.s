; REESE ALLEN | rga2uz | binarySearch.s | 11-05-10	


	global binarySearch 

	section .text


; Parameter 1 is a pointer to an int array, in rdi  			
; Parameter 2 is an int representing beginning of the array, in rsi 	(int l)			~ esi 
; Parameter 3 is an int representing ending of the array, in rdx	    (int h)	  		~ edx
; Parameter 3 is an int representing target element to find, in rcx	 	(int x)	  	    ~ ecx

; elements are already sorted / passed in ascending order

	; pseudocode:
	; int binarySearch (int a[], int l, int h, int x)
	; if(h >= l) { int m = l + (h - l) / 2 
	; if(a[m] == x) { return m }
	; if(a[m] > x) { return binarySearch(a, l, m-1, x) }
	; else { return binarySearch(a, m + 1, h, x) } }
	; return -1 


binarySearch:
	xor rax, rax
	xor r10, r10

loop:
	cmp rdx, rsi					; if h >= l, continue 				
	jl notfound  					; else return -1

	mov r10, rdx 					
	sub r10, rsi 
	shr r10, 1 						; m = ( (h - l) / 2 ) - l
	add r10, rsi 				

	cmp [rdi + 4*r10], ecx 			; if a[m] == x
	je end 							; return m + 1
	jl less 						; recurse with m+1 as new l
	jg greater						; recurse with m-1 as new h 


less:		
	inc r10
	mov rsi, r10 				
	jmp loop

greater:
	dec r10
	mov rdx, r10
	jmp loop

end:
	mov rax, r10 
	ret

notfound:
	mov	rax, -1
	ret