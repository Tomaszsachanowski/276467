section .data
	tabela TIMES 512 Dq 0 	;8 byte przechowuje wartosci dla kolejnych argumentów
	tabelaX TIMES 512 Dq 0	;8 byte przechowuje kolejne argumenty dla metody sicznych
	tabelaY TIMES 512 Dq 0	;8 byte przechowuje wartosci dla kolejnych argumentów siecznych
section .text

global editWielomian

;TOMASZ SACHANOWSKI
; 276467

; W kompilacji x64 parametry funkcji trafiaja domyslne do rejestrow:
; -rdi - bitmap pointer
; -rsi - BITMAP_W
; -rdx - BITMAP_H
; -xmm0 - constan S
; xmm1 - A
; xmm2 - B
; xmm3 - C
; xmm4 - D


editWielomian:
	push rbp
	mov rbp, rsp

	mov rcx,rdi
	mov R8, rsi     ;R8 = szerokosc
	mov R9,rdx			;R9 = wysokosc
	shr R9,1				;R9= polowa wysokosci


	mov R10,0				;R10 licznik

; R14 rejstr szułacy do porusznaia sie po bit mapie Allegero według jej konwencji
	mov R14, rdx
	add R14, rdx
	add R14, rdx

	imul R9, R14
	sub rcx, R9 ;rcx znajduje sie w połowie bitmapy

petla_osx:

	inc R10
   color_bialy:
		mov BYTE [rcx], 255
		mov BYTE [rcx+1], 255
		mov BYTE [rcx+2], 255

		add rcx,3 						;kolejny punkt w wierszu
	cmp R10,R8 							;sprwwadzam czy nie dostałem się na koniec wiersza
	jb petla_osx

;koniec rysowanie osi X
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	mov R10,0
	mov rcx,rdi
	mov R8, rsi     			;R8 = szerokosc
	mov R9,rdx						;R9 = wysokosc
	shr R8,1							;R8= polowa szerokosci
	imul R8,3							; bo 3 piksele
	add rcx,R8            ;teraz rcx wskazuje na środek bitmapy

petla_osy:
					inc R10					;inkrementacja licznika
					color_turkusowy:
													mov BYTE [rcx], 100
													mov BYTE [rcx+1], 255
													mov BYTE [rcx+2], 255

		sub rcx,R14   		;przechodzimy do kolejnego wiersza
		cmp R10,R9				;sprawdzam czy jestem już na ostatnim wierszu bitmapy
			jb petla_osy

;koniec osi Y
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;dziedzna <-2;2> co daje przedzał 4 4/szerosc to nasza wartosc piksela czyli dx
	mov R10,4								;aby załadaowac 4 do double
	mov R8, rsi							;R8 = szerokosc
	cvtsi2sd xmm9,R10				;laduje do x9 = 4.0
	cvtsi2sd xmm6,R8				;x6= od ile trzeba przesunac argument  aby był rowny jedneu piksel dx
	divsd xmm9,xmm6					; xmm9 o ile przesuwam nasz argument  dziedzna/szerokosc

	mov R11, tabela
	mov R12,0
	mov R10, -2							;pierwszy argument
	cvtsi2sd xmm5,R10 			;x5 licznik

funkcja:
		movsd xmm6,xmm5
		mulsd xmm6,xmm6
		movsd xmm7,xmm6
		mulsd xmm7,xmm2 			;Bx^2

		mulsd xmm6,xmm5
		mulsd xmm6,xmm1;xmm6 	Ax^3

		movsd xmm8,xmm5
		mulsd xmm8,xmm3 		;Cx

		addsd xmm8,xmm4
		addsd xmm8,xmm6
		addsd xmm8, xmm7 	;suma ax^3 +bx^2 +cx +d nasza warotsc w punkcie x8=f(x)


;zbiór wartosci Y=<-8;8>  czyli 16

				mov R10,rdx						;ładuje wysokosc bitmapy
				cvtsi2sd xmm6,R10
				mov R10, 16						;laduje szerokosc zbioru warotsci
				cvtsi2sd xmm7,R10
				divsd xmm6,xmm7  			; wartosc jednego piksela kazda wartosc wymnazam przez to aby było dobre skalowanei dla naszego przedziału

				mulsd xmm8,xmm6       ;mnożenei wartosic przez skale
				mov R10,255
				cvtsi2sd xmm6, R10
				ucomisd xmm8,xmm6  ;czy wartosc funkcj wjeksza od maksymalnego piksela
					ja za_duza_wartosc
				jmp wstaw


za_duza_wartosc:
								mov R10,255
								cvtsi2sd xmm8, R10

wstaw:
		CVTSD2SI r10,xmm8

		mov [r11],r10		;wstawiam do tabeli
		add r11,8     	;kolejny indeks
		addsd xmm5,xmm9	;kolejny argument x1=> x2 czyli x=x+dx
		inc R12        	;inkrementacja licznika
		cmp R12,rsi			; sprawdzam czy doszedłem do ostanitego piksela na naszej szerokosci mapy
		jb funkcja


;wszystkie wartosci wstawione do tabeli
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	mov R10,0
	mov rcx,rdi
	mov R8, rsi     ;R8 = szerokosc
	mov R9,rdx			;R9 = wysokosc
	shr R9,1				;R9	polowa wysokosci

	mov R11, tabela
	mov R12,0



petla_fun:
	mov rcx,rdi
	mov R9,rdx				;wysokosc
	shr R9,1					;polowa wysokosci
	add R9, [R11]			;dodjae wartosc aby byc na odpowiedniej wysokosci bit mapy

	imul R9,R14
	sub rcx,R9
        add rcx,R12 ; ktory piksel w wierszu  R12 przesuwa sie po pikselu
	inc R10
   color_2:
		mov BYTE [rcx], 100
		mov BYTE [rcx+1], 100
		mov BYTE [rcx+2], 255

		add R12,3 			;przechodze do kolejnego punktu
		add R11,8				;przechodze od kolejnego wartosic z tabeli
		cmp R10,R8
			jb petla_fun


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
pochodna:
mov R12, 0 		;licznik
mov R8, tabelaX
mov R9,tabelaY
	mov R10,-2  					;od tego punktu zaczynamy
	cvtsi2sd xmm5,R10			;x5=-2.0
wart_pochodnej:
movsd xmm6,xmm5
mulsd xmm6,xmm6 		;x1^2
movsd xmm7,xmm6 		;x1^2

addsd xmm6,xmm6 		;2x^2
addsd xmm6,xmm7 		;3x^2
mulsd xmm6, xmm1 		;3Ax^2
movsd xmm7, xmm5 		; x
addsd xmm7,xmm7 		;2x
mulsd xmm7,xmm2			;2Bx
addsd xmm6,xmm7 		;3Ax^2+2Bx
addsd xmm6,xmm3 		;F'(x1)
mulsd xmm6,xmm6  		;slope ^2

mov R10, 1
cvtsi2sd xmm7,R10
addsd xmm6,xmm7  	; f'(x1)+1= slope^2 + 1
movsd xmm7, xmm0 	;	xmm7 S^2
divsd xmm7,xmm6  	;dx^2=s^2/slope^2+1
sqrtsd xmm7, xmm7 ;xmm7 to dx

mov R10,rsi 							; szeroksc do skalowania
addsd xmm5, xmm7  				;kolejny punkt X1+DX
cvtsi2sd xmm8, R10
mulsd xmm8, xmm5 					;(x1+dx)*szeroksc
mov R10 ,4								; dlugosc przedzialu <-2;2> =4
cvtsi2sd xmm9, R10
divsd xmm8,xmm9						;czyli teraz x8 odpoiwada wartosci piskela  <-256;256>
CVTSD2SI R10, xmm8 				;konwersja na calkowite
mov [R8], R10 						;w tabeli jest nasz punkt x
add R8,8
sqrtsd xmm6,xmm6					; xmm6=slope^2 => xmm6=slope
mulsd xmm6,xmm7 					;dy= slope*dx

wart_funkcji:
		movsd xmm7,xmm5 			;xmm7 x
		mulsd xmm7,xmm7 			;xmm7 x^2
		movsd xmm8,xmm7 			;xmm8 x^2
		mulsd xmm8,xmm2 			; xmm8 Bx^2

		mulsd xmm7,xmm5
		mulsd xmm7,xmm1 			;xmm7 Ax^3

   	addsd xmm7,xmm8 			;Ax3 +bx2

		movsd xmm8,xmm5
		mulsd xmm8,xmm3 			;Cx

		addsd xmm8,xmm4 			;Cx+D
		addsd xmm8, xmm7 			;suma ax^3 +bx^2 +cx +d jeszcze dy brakuje
		addsd xmm8,xmm6 			;F(x+dx)+dy
				mov R10,rdx				;laduje wysokosc
				cvtsi2sd xmm6,R10
				mov R10, 16				;laduje przedizął wartosci
				cvtsi2sd xmm7,R10
				divsd xmm6,xmm7
				mulsd xmm8,xmm6		; wartosc preskalowana
				mov R10,255
				cvtsi2sd xmm6, R10
				ucomisd xmm8,xmm6  ;czy wartosc funkcj wjeksza od najwiekszego piksela
				ja za_duza_wartosc_dy
				jmp wstaw2


za_duza_wartosc_dy:
								mov R10,255
								cvtsi2sd xmm8, R10

wstaw2:
		CVTSD2SI R10,xmm8

		mov [R9],r10
		add R9,8
		inc R12 	;inkrementacja licznika aby wiedziec ile punktow mamy
		mov R10,2
		cvtsi2sd xmm6, R10
		ucomisd xmm6,xmm5 ;dopóki nie przeorcze 2.0
		ja wart_pochodnej

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	mov R10,0



	mov R13,0



petla_osost:
	mov R11, tabelaY
	add R11,R13
	mov rcx,rdi
	mov R8, rsi     ; szerokosc
	mov R9,rdx			;wysokosc
	shr R9,1				;polowa wysokosci
	shr R8,1				;polowa szerokosci
	add R9, [R11]
	mov R11, tabelaX
	add R11,R13
	imul R9,R14
	sub rcx,R9
		add R8,[R11]
		imul R8,3
        add rcx,R8
	inc R10
   color_3:
		mov BYTE [rcx], 255
		mov BYTE [rcx+1], 255
		mov BYTE [rcx+2], 255


		add R13,8
		cmp R12,R10
	ja petla_osost
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
end:
	mov rsp, rbp
	pop rbp
	ret
