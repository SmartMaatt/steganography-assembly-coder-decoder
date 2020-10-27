.CODE

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
	push r8
	
	xor RAX, RAX		;czyszczenie RAX (Schowek na rozbity znak)
	xor RBX, RBX		;czyszczenie RBX (Schowek na wskaznik na bitmape)
	mov RBX, RCX		;przepisanie zawartosci RCX do RBX
	xor RCX, RCX		;czyszczenie RCX (Schowek na licznik petli)
	xor R8, R8

LetterLoop:
	shl RAX, 8			;przesuniecie wartosci bitu znaku na kolejny bajt
	shl R8, 8			;przesuniecie wartosci bitow do resetu na kolejny bajt
	mov AL, [RDX]		;wprowadzenie bitow znaku na najmniej znaczacy bajt RAX
	mov R8b, 11111110b	;wprowadzenie bitow resetu

	shl AL, CL;			;przesuniecie bitowe w lewo o wartosc iteratora petli
	shr AL, 7;			;powrotne przesuniecie bitu na skrajny punkt po prawej stronie
	inc CL				;inkrementuj CL

	cmp CL, 8			;zakoncz petle gdy wykona 8 powtorzen
	jne LetterLoop		;skok na poczatek petli

	movq mm0, qword ptr[RBX]		;pobranie osmiu bajtow zdjecia do mm0
	movq mm1, RAX					;pobranie rozbitych bitow tekstu do mm1
	movq mm2, R8					;pobranie rejestru resetu bitow do mm2

	pand mm0, mm2					;przypisanie bitow tekstu do najmniej znaczacych w bitmapie
	por mm0, mm1					;wykonanie operacji logicznej OR na obu rejestrach
	movq qword ptr[RBX], mm0		;zmiana danych w bitmapie
	emms							;czyszczenie mmx po wykorzystaniu

	pop r8							;przywrocenie wartosci ze stosu do rejestrow
	pop rbx						
	pop rax
    ret 
asmSteganographyEncode ENDP



;RCX - bmpKey, wskaznik na bitmape od momentu w ktorym ma zostac odczytana
;RDX - symbol, znak z tekstu do zakodowania w zdjeciu
;void asmStegonagraphyDecode(char* bmpKey, char* symbol)
asmSteganographyDecode PROC C
	push rax			;zawartosc rejestrow idzie na stos
	push rbx

	movq mm0, qword ptr[RCX]	;pobranie zawartosci bit mapy
	xor RAX, RAX		;czyszczenie RAX (Schowek na zawartosc linii resetu)
	xor RBX, RBX		;czyszczenie RBX (Schowek na wskaznik na bitmape)
	xor RCX, RCX		;czyszczenie RCX (Schowek na licznik petli)

ResetLoop:
	shl RAX, 8			;przesuniecie bitowe o 8 w lewo
	mov AL, 00000001b	;wprowadzenie bitow resetu
	inc CL				;inkrementuj CL
	cmp CL, 8			;zakoncz petle gdy wykona 8 powtorzen
	jne ResetLoop		;skok na poczatek petli

	movq mm1, RAX		;pobranie linii resetu do mm1
	pand mm0, mm1		;pozostawienie jedynie danych tekstu
	movq RBX, mm0		;pobranie bitow z mm0 do RBX
	emms				;czyszczenie mmx po wykorzystaniu
	xor RAX, RAX		;czyszczenie RAX
	xor RCX, RCX		;czyszczenie RCX

TextLoop:
	inc CL				;zwiekszenie licznika
	or AL, BL			;przypisanie wartosci bitu na odpowiednie miejsce
	shr RBX, 8			;przesuniecie wektora o 8 w prawo
	shl BL, CL			;przesuniecie bitu o iterator w lewo
	cmp CL, 8			;warunek zakonczenia petli
	jne TextLoop

	mov [RDX], AL		;przypisanie odczytanych wartosci do tekstu
	pop rbx				;przywrocenie wartosci ze stosu do rejestrow
	pop rax
    ret 
asmSteganographyDecode ENDP
END