CODE

checkMMXCapability PROC C
	push rbx			; Zapisz RBX
	pushfq				; Wypchnij flagi
	pop rax				; Pobierz je do RAX
	mov rbx, rax		; Zapisz do RBX na pozniej
	xor rax, 200000h	; Przelacz id flagi
	push rax			; Wypchnij przelaczone flagi
	popfq				; Pobierz je z powrotem do flag, zresetowały sie?
	pushfq				; Wypchnij flagi
	pop rax				; Pobierz je z powrotem do RAX
	cmp rax, rbx		; Porownaj aktualne flagi z wczesniej zapisanymi
	jz ThatsABity		; Jesli się zresetowały, nie mozesz uzywać CPUID

	pop rbx				; Przywracam RBX
	mov eax, 1			; Nie zresetowało sie wiec...
	cpuid				; CPUID_0000_0001
	shr rdx, 23			; Shiftuj bit MMX do pozycji najbardziej po prawej
	and rdx, 1			; Wykonuje AND na rdx (jesli bylo 1, pozostanie 1)
	mov rax, rdx		; Przenosze RDX do akumulatora
	ret					; Zwracam 0/1

ThatsABity:
	pop rbx				; Procesor nie obsluguje CPUID lub MMX
	xor rax, rax		; Resetuj akumulator do 0
	ret
CheckMMXCapability ENDP


;RCX - bmpKey, wskaznik na bitmape od momentu w ktorym ma zostac odczytana
;RDX - symbol, znak z tekstu do zakodowania w zdjeciu
;void asmStegonagraphyEncode(char* bmpKey, char* symbol)
asmSteganographyEncode PROC C 
	
	push rax			;zawartosc rejestrow idzie na stos
	push rbx
	push rcx
	push rdx
	
	xor RAX, RAX		;czyszczenie RAX (Schowek na rozbity znak)
	xor RBX, RBX
	mov RBX, RCX

	xor RCX, RCX
	mov CL, 11111110b
	mov CH, 8 

LetterLoop:
	mov AL, [RDX]
	mov AH, [RBX]

	or AL, CL
	cmp AL, 11111111b
	je wasOne

	and AH, 11111110b
	jmp continue

wasOne:
	or ah, 00000001b

continue:
	mov [RBX], AH
	inc RBX
	mov AH, [RBX]
	mov AL, [RDX]
	shl CL, 1
	or CL, 00000001

	dec CH
	cmp CH, 0
	jne LetterLoop

endProc:

	pop rdx
	pop rcx
	pop rbx
	pop rax
    ret 

asmSteganographyEncode ENDP


;RCX - bmpKey, wskaznik na bitmape od momentu w ktorym ma zostac odczytana
;RDX - symbol, znak z tekstu do zakodowania w zdjeciu
;void asmStegonagraphyEncode(char* bmpKey, char* symbol)
asmSteganographyDecode PROC C ;bmpKey, symbol

	push rax			;zawartosc rejestrow idzie na stos
	push rbx
	push rcx
	push rdx
	
	xor RAX, RAX		;czyszczenie RAX (Schowek na rozbity znak)
	xor RBX, RBX
	mov RBX, RCX

	xor RCX, RCX
	mov CL, 00000001b
	mov CH, 8 

LetterLoop:
	mov AH, [RBX]

	or AH, 11111110b
	cmp AH, 11111111b
	je wasOne
	jmp continue

wasOne:
	or AL, CL

continue:
	inc RBX
	shl CL, 1

	dec CH
	cmp CH, 0
	jne LetterLoop

	mov [RDX], AL

endProc:

	pop rdx
	pop rcx
	pop rbx
	pop rax
    ret 

asmSteganographyDecode ENDP
END