;-------------------------------------------------------------------------------
; Libreria "DELAY48MHZ.INC"
;-------------------------------------------------------------------------------
; RETARDOS PARA FRECUENCIA=48MHZ		PARA 18F
; desde 4micros-10segundos
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
;  ZONA DE VARIABLES O DATOS
;-------------------------------------------------------------------------------
	PSECT   udata_acs	;RESERVO VARIABLES EN ACCES BANK  DESDE 0X00-0X60	
global CounterA,CounterB,CounterC,CounterD

CounterA:   DS	1
CounterB:   DS	1
CounterC:   DS	1
CounterD:   DS	1

;-------------------------------------------------------------------------------
;  Rutina Delays= Delayms - Delayus
;-------------------------------------------------------------------------------
	PSECT   Delay,class=CODE,reloc=2
Delay_2us: 
	movlw	6
	bra	RetardoMicros
Delay_4us:	
	bra	$+2
	movlw	13
	bra	RetardoMicros	
Delay_5us:	
	bra	$+2
	movlw	17
	bra	RetardoMicros	
Delay_10us:
	bra	$+2
	movlw	37
	bra	RetardoMicros
Delay_20us:
	bra	$+2
	movlw	77
	bra	RetardoMicros
Delay_50us:
	bra	$+2
	movlw	197
	bra	RetardoMicros
RetardoMicros:
	movwf	CounterA,a
loop_micros:		
	decfsz	CounterA,F,a
	bra	loop_micros
	retlw	0
;-------------------------------------------------------------------------------
Delay_100us:
	bra	$+2
	movlw	2
	movwf	CounterB,a
	movlw	138
	movwf	CounterA,a
	bra	RetardoMicrosMs	
Delay_200us:
	bra	$+2
	movlw	4
	movwf	CounterB,a
	movlw	24
	movwf	CounterA,a
	bra	RetardoMicrosMs	
Delay_500us:
	bra	$+2
	movlw	8
	movwf	CounterB,a
	movlw	196
	movwf	CounterA,a
	bra	RetardoMicrosMs	
Delay_1ms:
	bra	$+2
	movlw	16
	movwf	CounterB,a
	movlw	140
	movwf	CounterA,a
	bra	RetardoMicrosMs	
Delay_2ms:
	bra	$+2
	movlw	32
	movwf	CounterB,a
	movlw	28
	movwf	CounterA,a
	bra	RetardoMicrosMs	
Delay_5ms:
	bra	$+2
	movlw	78
	movwf	CounterB,a
	movlw	206
	movwf	CounterA,a
	bra	RetardoMicrosMs	
Delay_10ms:
	bra	$+2
	movlw	156
	movwf	CounterB,a
	movlw	160
	movwf	CounterA,a
	bra	RetardoMicrosMs	
RetardoMicrosMs:		
	decfsz	CounterA,F,a
	bra	RetardoMicrosMs
	decfsz	CounterB,F,a
	bra	RetardoMicrosMs
	retlw	0
;-------------------------------------------------------------------------------
Delay_20ms:
	movlw	2
	movwf	CounterC,a
	movlw	56
	movwf	CounterB,a
	movlw	171
	movwf	CounterA,a
	bra	Retardo_ms
Delay_50ms:
	bra	$+2
	movlw	4
	movwf	CounterC,a
	movlw	12
	movwf	CounterB,a
	movlw	49
	movwf	CounterA,a
	bra	Retardo_ms
Delay_100ms:
	nop
	movlw	7
	movwf	CounterC,a
	movlw	23
	movwf	CounterB,a
	movlw	104
	movwf	CounterA,a
	bra	Retardo_ms
Delay_200ms:
	bra	$+2
	movlw	13
	movwf	CounterC,a
	movlw	45
	movwf	CounterB,a
	movlw	213
	movwf	CounterA,a
	bra	Retardo_ms
Delay_500ms:
	nop
	movlw	31
	movwf	CounterC,a
	movlw	113
	movwf	CounterB,a
	movlw	28
	movwf	CounterA,a
	bra	Retardo_ms
Delay_1s:
	movlw	61
	movwf	CounterC,a
	movlw	225
	movwf	CounterB,a
	movlw	62
	movwf	CounterA,a
	bra	Retardo_ms
Delay_2s:
	movlw	122
	movwf	CounterC,a
	movlw	193
	movwf	CounterB,a
	movlw	128
	movwf	CounterA,a
	bra	Retardo_ms
Retardo_ms:	
	decfsz	CounterA,F,a
	bra	Retardo_ms
	decfsz	CounterB,F,a
	bra	Retardo_ms
	decfsz	CounterC,F,a
	bra	Retardo_ms
	retlw	0
;-------------------------------------------------------------------------------
Delay_5s:
	movlw	2
	movwf	CounterD,a
	movlw	49
	movwf	CounterC,a
	movlw	98
	movwf	CounterB,a
	movlw	67
	movwf	CounterA,a
	bra	Retardo_seg
Delay_10s:
	movlw	3
	movwf	CounterD,a
	movlw	97
	movwf	CounterC,a
	movlw	195
	movwf	CounterB,a
	movlw	140
	movwf	CounterA,a
	bra	Retardo_seg
Retardo_seg:	
 	decfsz	CounterA,F,a
	bra	Retardo_seg
	decfsz	CounterB,F,a
	bra	Retardo_seg
	decfsz	CounterC,F,a
	bra	Retardo_seg
	decfsz	CounterD,F,a
	bra	Retardo_seg
	retlw	0
;-------------------------------------------------------------------------------