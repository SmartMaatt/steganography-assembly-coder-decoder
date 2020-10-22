.CODE


asmSteganographyEncode PROC C ;bmpKey, symbol
	
	push rax
	push rbx
	push rcx
	push rdx
	
	mov RAX, 0h

	mov RBX, RCX		;pobranie adresu tablicy bmp
	mov RCX, RDX		;pobranie znaku tablicy txt

	mov al, [RCX]		;znak z tablicy txt
	mov ah, [RBX]		;znak z tablicy bmp

	;USTAWIENIE BITU NR8------------------------------------------
	or	al, 11111110b
	cmp al, 11111111b	;czy bylo zero?
	je wasOne1

	and ah, 11111110b	;jesli bylo zero, zastap ostatni bit zerem
	jmp continue1

wasOne1:
	or	ah, 00000001b	;jesli bylo jeden, zastap ostatni bit jedynka

continue1:
	mov [RBX], ah		;zaladuj zmiany
	inc RBX				;nastepna wartosc bmp
	mov ah, [RBX]		;zaladuj nastepna wartosc
	mov al, [RCX]		;zaladuj ten sam znak

	;USTAWIENIE BITU NR7----------------------------------------
	or	al, 11111101b
	cmp al, 11111111b	;czy bylo zero?
	je wasOne2

	and ah, 11111110b	;jesli bylo zero, zastap ostatni bit zerem
	jmp continue2

wasOne2:
	or	ah, 00000001b	;jesli bylo jeden, zastap ostatni bit jedynka

continue2:
	mov [RBX], ah		;zaladuj zmiany
	inc RBX				;nastepna wartosc bmp
	mov ah, [RBX]		;zaladuj nastepna wartosc
	mov al, [RCX]		;zaladuj ten sam znak

	;USTAWIENIE BITU NR6----------------------------------------
	or	al, 11111011b
	cmp al, 11111111b	;czy bylo zero?
	je wasOne3

	and ah, 11111110b	;jesli bylo zero, zastap ostatni bit zerem
	jmp continue3

wasOne3:
	or	ah, 00000001b	;jesli bylo jeden, zastap ostatni bit jedynka

continue3:
	mov [RBX], ah		;zaladuj zmiany
	inc RBX				;nastepna wartosc bmp
	mov ah, [RBX]		;zaladuj nastepna wartosc
	mov al, [RCX]		;zaladuj ten sam znak

	;USTAWIENIE BITU NR5----------------------------------------
	or	al, 11110111b
	cmp al, 11111111b	;czy bylo zero?
	je wasOne4

	and ah, 11111110b	;jesli bylo zero, zastap ostatni bit zerem
	jmp continue4

wasOne4:
	or	ah, 00000001b	;jesli bylo jeden, zastap ostatni bit jedynka

continue4:
	mov [RBX], ah		;zaladuj zmiany
	inc RBX				;nastepna wartosc bmp
	mov ah, [RBX]		;zaladuj nastepna wartosc
	mov al, [RCX]		;zaladuj ten sam znak

	;USTAWIENIE BITU NR4----------------------------------------
	or	al, 11101111b
	cmp al, 11111111b	;czy bylo zero?
	je wasOne5

	and ah, 11111110b	;jesli bylo zero, zastap ostatni bit zerem
	jmp continue5

wasOne5:
	or	ah, 00000001b	;jesli bylo jeden, zastap ostatni bit jedynka

continue5:
	mov [RBX], ah		;zaladuj zmiany
	inc RBX				;nastepna wartosc bmp
	mov ah, [RBX]		;zaladuj nastepna wartosc
	mov al, [RCX]		;zaladuj ten sam znak

	;USTAWIENIE BITU NR3----------------------------------------
	or	al, 11011111b
	cmp al, 11111111b	;czy bylo zero?
	je wasOne6

	and ah, 11111110b	;jesli bylo zero, zastap ostatni bit zerem
	jmp continue6

wasOne6:
	or	ah, 00000001b	;jesli bylo jeden, zastap ostatni bit jedynka

continue6:
	mov [RBX], ah		;zaladuj zmiany
	inc RBX				;nastepna wartosc bmp
	mov ah, [RBX]		;zaladuj nastepna wartosc
	mov al, [RCX]		;zaladuj ten sam znak

	;USTAWIENIE BITU NR2----------------------------------------
	or	al, 10111111b
	cmp al, 11111111b	;czy bylo zero?
	je wasOne7

	and ah, 11111110b	;jesli bylo zero, zastap ostatni bit zerem
	jmp continue7

wasOne7:
	or	ah, 00000001b	;jesli bylo jeden, zastap ostatni bit jedynka

continue7:
	mov [RBX], ah		;zaladuj zmiany
	inc RBX				;nastepna wartosc bmp
	mov ah, [RBX]		;zaladuj nastepna wartosc
	mov al, [RCX]		;zaladuj ten sam znak

	;USTAWIENIE BITU NR1----------------------------------------
	or	al, 01111111b
	cmp al, 11111111b
	je wasOne8

	and ah, 11111110b	;jesli bylo zero, zastap ostatni bit zerem
	jmp continue8

wasOne8:
	or	ah, 00000001b	;jesli bylo jeden, zastap ostatni bit jedynka

continue8:
	mov [RBX], ah		;zaladuj zmiany

endProc:

	pop rdx
	pop rcx
	pop rbx
	pop rax
    ret 

asmSteganographyEncode ENDP


;---------------------------------------------------------------------------------------
;---------------------------------------------------------------------------------------
;									DEKODOWANIE TEKSTU
;---------------------------------------------------------------------------------------
;---------------------------------------------------------------------------------------

asmSteganographyDecode PROC C ;bmpKey, symbol

	push rax
	push rbx
	push rcx
	push rdx

	mov RAX, 0h
	mov RBX, RCX		;pobranie adresu tablicy bmp
	mov RCX, RDX		;pobranie adresu znaku tablicy txt

	;USTAWIENIE BITU NR8----------------------------------------
	mov ah, [RBX]			;zaladuj wartosc bmp
	or	ah, 11111110b		;sprawdzenie ostatniego bitu
	cmp ah, 11111111b		;czy ostatni bit to jedynka?
	je wasOne1				;jesli tak to skocz do ustawienia jedynki
	jmp continue1			;jesli nie to idz dalej (juz jest 0 ustawione)

wasOne1:
	or	al, 00000001b		;ustaw jedynke
continue1:
	inc RBX					;przesun wskaznik na nastepna dana
	
	;USTAWIENIE BITU NR7----------------------------------------
	mov ah, [RBX]			;zaladuj wartosc bmp
	or	ah, 11111110b		;sprawdzenie bitu
	cmp ah, 11111111b		;czy ostatni bit to jedynka?
	je wasOne2				;jesli tak to skocz do ustawienia jedynki
	jmp continue2			;jesli nie to idz dalej (juz jest 0 ustawione)

wasOne2:
	or	al, 00000010b		;ustaw jedynke
continue2:
	inc RBX					;przesun wskaznik na nastepna dana

	;USTAWIENIE BITU NR6----------------------------------------
	mov ah, [RBX]			;zaladuj wartosc bmp
	or	ah, 11111110b		;sprawdzenie bitu
	cmp ah, 11111111b		;czy ostatni bit to jedynka?
	je wasOne3				;jesli tak to skocz do ustawienia jedynki
	jmp continue3			;jesli nie to idz dalej (juz jest 0 ustawione)

wasOne3:
	or	al, 00000100b		;ustaw jedynke
continue3:
	inc RBX					;przesun wskaznik na nastepna dana
	
	;USTAWIENIE BITU NR5----------------------------------------
	mov ah, [RBX]			;zaladuj wartosc bmp
	or	ah, 11111110b		;sprawdzenie bitu
	cmp ah, 11111111b		;czy ostatni bit to jedynka?
	je wasOne4				;jesli tak to skocz do ustawienia jedynki
	jmp continue4			;jesli nie to idz dalej (juz jest 0 ustawione)

wasOne4:
	or	al, 00001000b		;ustaw jedynke
continue4:
	inc RBX					;przesun wskaznik na nastepna dana

	;USTAWIENIE BITU NR4----------------------------------------
	mov ah, [RBX]			;zaladuj wartosc bmp
	or	ah, 11111110b		;sprawdzenie bitu
	cmp ah, 11111111b		;czy ostatni bit to jedynka?
	je wasOne5				;jesli tak to skocz do ustawienia jedynki
	jmp continue5			;jesli nie to idz dalej (juz jest 0 ustawione)

wasOne5:
	or	al, 00010000b		;ustaw jedynke
continue5:
	inc RBX					;przesun wskaznik na nastepna dana

	;USTAWIENIE BITU NR3----------------------------------------
	mov ah, [RBX]			;zaladuj wartosc bmp
	or	ah, 11111110b		;sprawdzenie bitu
	cmp ah, 11111111b		;czy ostatni bit to jedynka?
	je wasOne6				;jesli tak to skocz do ustawienia jedynki
	jmp continue6			;jesli nie to idz dalej (juz jest 0 ustawione)

wasOne6:
	or	al, 00100000b		;ustaw jedynke
continue6:
	inc RBX					;przesun wskaznik na nastepna dana

	;USTAWIENIE BITU NR2----------------------------------------
	mov ah, [RBX]			;zaladuj wartosc bmp
	or	ah, 11111110b		;sprawdzenie bitu
	cmp ah, 11111111b		;czy ostatni bit to jedynka?
	je wasOne7				;jesli tak to skocz do ustawienia jedynki
	jmp continue7			;jesli nie to idz dalej (juz jest 0 ustawione)

wasOne7:
	or	al, 01000000b		;ustaw jedynke
continue7:
	inc RBX					;przesun wskaznik na nastepna dana

	;USTAWIENIE BITU NR1----------------------------------------
	mov ah, [RBX]			;zaladuj wartosc bmp
	or	ah, 11111110b		;sprawdzenie bitu
	cmp ah, 11111111b		;czy ostatni bit to jedynka?
	je wasOne8				;jesli tak to skocz do ustawienia jedynki
	jmp endProc				;jesli nie to idz dalej (juz jest 0 ustawione)

wasOne8:
	or	al, 10000000b		;ustaw jedynke

endProc:
	mov [RCX], al

	pop rdx
	pop rcx
	pop rbx
	pop rax
    ret 

asmSteganographyDecode ENDP
END