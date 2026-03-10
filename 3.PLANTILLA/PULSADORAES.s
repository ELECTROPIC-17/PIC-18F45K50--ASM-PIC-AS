;-------------------------------------------------------------------------------    
; PROGRAMA ENCIENDE Y APAGA LED CON SOLO UN PULSO
;-------------------------------------------------------------------------------     
    PROCESSOR	18F45K50
    #include	<xc.inc>
    #include	"CONFIG.INC"

;-------------------------------------------------------------------------------
;  ZONA DE DATOS O VARIABLES                                                        
;------------------------------------------------------------------------------- 
    PSECT   udata_acs
   Contador:	DS  1
  
;-------------------------------------------------------------------------------
;  ZONA DEFINICION  ETIQUETAS Y CONSTANTES                                                        
;-------------------------------------------------------------------------------   
    #define	P1	PORTA,0,a		
    #define	P2	PORTA,1,a
    #define	P3	PORTA,2,a
    
;-------------------------------------------------------------------------------
;  ZONA DE VECTORES DE CODIGO	                                                                
;-------------------------------------------------------------------------------
    PSECT  resetVect,class=CODE,reloc=2
resetVect:
    goto    Main	;0X00
    
    PSECT  HiInt,class=CODE,reloc=2
    goto   IntHi 
    
    PSECT  LoInt,class=CODE,reloc=2
    goto   IntLo
    
  
;-------------------------------------------------------------------------------
;  ZONA DE CÓNFIGURACION INICIAL DE PUERTOS DEL PIC                          
;-------------------------------------------------------------------------------   
    PSECT  Main,class=CODE,reloc=2 
Main:  
    movlb   15		; BANCO 15
    
    clrf    ANSELA,b	; PINES DIGITALES
    clrf    ANSELC,b	; PINES DIGITALES
    clrf    ANSELD,b	; PINES DIGITALES
    
    movlw   0xFF   
    movwf   TRISA,b	; ENTRADA PUERTO A
    
    clrf    TRISC,b	; SALIDAS
    clrf    TRISD,b	; SALIDAS
    
    clrf    LATC,b	; INICIE APAGADO
    clrf    LATD,b	; INICIE APAGADO
    movlb   0		; BANCO
    
;------------------------------------------------------------------------------;
;  ZONA INICIAL DE PROGRAMA PRINCIPAL                          
;------------------------------------------------------------------------------;  
Loop:
    btfss   P1		; Se pulso P1?
    goto    Prende	; Si se pulso
    goto    Loop	; Vuelve a testear pulsador
    
    
Prende:
    call    Delay_10ms	; tiempo para estabilizar 
    btfss   P1		; sigue pulsado?
    goto    Prende	; Si
    btg	    LATC,0,a	; Conmuta  led    
    goto    Loop	; Vuelve a testear pulsador
    
 IntHi:
 IntLo: 
;------------------------------------------------------------------------------;
;  ZONA DE INCLUDES Y FIN DE PROGRAMA				
;------------------------------------------------------------------------------;
	#include    "RETARDOS.INC"

	END 