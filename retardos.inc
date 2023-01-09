				   	;RETARDOS
;________________________________________________________________________________
;________________________________________________________________________________
; @file: retardos.inc
; @brief:
;   ; En esta librería se encuentran distintos códigos de intervalos de tiempo
;    ; (retardos) para poder usados en los "Source Files" según se necesite
;    ; alguno de estos en próximos programas.
; @date: 7/01/23
; @author: Gonzales Alvarado Sebastian
; @version: 1.0.0
;_______________________________________________________________________________
;_______________________________________________________________________________
PSECT udata_acs
 
contador_1: DS 1		    ;reserva 1 byte en acces ram
contador_2: DS 1		    ;reserva 1 byte en acces ram
    
PSECT CODE
 
//Delay en microsegundos (uc)

;Delay_10us
Delay_10us:
    MOVLW   1		    ; 1 Tcy -> (k2)
    MOVWF   contador_1,0    ; 1 Tcy
    
;T= (6 + 4k)us
loop_1:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    loop_1	    ; (K1-2) * 2 Tcy
RETURN		    ; 2 Tcy
    
;Delay_25us
Delay_25us:
    MOVLW   5		    ; 1 Tcy -> (k2)
    MOVWF   contador_1,0	    ; 1 Tcy
    
;T= (6 + 4k)us
loop_2:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    loop_2	    ; (K2-2) * 2 Tcy
RETURN		    ; 2 Tcy
 
;Delay_50us    
Delay_50us:
    MOVLW   11		    ; 1 Tcy -> (k2)
    MOVWF   contador_1,0	    ; 1 Tcy
    
;T= (6 + 4k)us
loop_3:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    loop_3	    ; (K1-2) * 2 Tcy
RETURN		    ; 2 Tcy
    
;Delay_100us 
Delay_100us:
    MOVLW   24		    ; 1 Tcy -> (k2)
    MOVWF   contador_1,0	    ; 1 Tcy
    
;T= (6 + 4k)us
loop_4:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    loop_4	    ; (K1-2) * 2 Tcy
RETURN		    ; 2 Tcy
    
;Delay_200us 
Delay_200us:
    MOVLW   49		    ; 1 Tcy -> (k2)
    MOVWF   contador_1,0	    ; 1 Tcy
    
;T= (6 + 4k)us
loop_5:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    loop_5	    ; (K1-2) * 2 Tcy
RETURN

;Delay_250us 
Delay_250us:
    MOVLW   61		    ; 1 Tcy -> (k2)
    MOVWF   contador_1,0	    ; 1 Tcy
    
;T= (6 + 4k)us
loop_6:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    loop_6	    ; (K1-2) * 2 Tcy
RETURN

;Delay_500us 
Delay_500us:
    MOVLW   124		    ; 1 Tcy -> (k2)
    MOVWF   contador_1,0	    ; 1 Tcy
    
;T= (6 + 4k)us
loop_7:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    loop_7	    ; (K1-2) * 2 Tcy
RETURN		    ; 2 Tcy

//Delay's en milisegundos (ms)    
;Delay_1ms    
Delay_1ms:
    MOVLW   1		    ; 1 Tcy -> (k2)
    MOVWF   contador_1,0    ; 1 Tcy
    
;T= (6 + 4k)us
Ext_loop_1:		    ; 2 Tcy -- Call
    MOVLW   249		    ; 1 Tcy -> (k1)
    MOVWF   contador_1,0    ; 1 Tcy
Int_loop_1:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    Int_loop_1	    ; (K2-2) * 2 Tcy
    DECFSZ  contador_2,1,0  ; (k2-1) + 3 Tcy
    GOTO    Ext_loop_1	    ; (k2-1) * 2 Tcy
RETURN		    ; 2 Tcy		    ; 2 Tcy

;Delay_50us
Delay_5ms:
    MOVLW   5		    ; 1 Tcy -> (k2)
    MOVWF   contador_2,0    ; 1 Tcy
    
;T= (6 + 4k)us
Ext_loop_2:		    ; 2 Tcy -- Call
    MOVLW   249		    ; 1 Tcy -> (k1)
    MOVWF   contador_1,0    ; 1 Tcy
Int_loop_2:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    Int_loop_2	    ; (K2-2) * 2 Tcy
    DECFSZ  contador_2,1,0  ; (k2-1) + 3 Tcy
    GOTO    Ext_loop_2	    ; (k2-1) * 2 Tcy
RETURN		    ; 2 Tcy
    
;Delay_10ms
Delay_10ms:
    MOVLW   10		    ; 1 Tcy -> (k2)
    MOVWF   contador_2,0    ; 1 Tcy
    
;T= (6 + 4k)us
Ext_loop_3:		    ; 2 Tcy -- Call
    MOVLW   249		    ; 1 Tcy -> (k1)
    MOVWF   contador_2,0    ; 1 Tcy

Int_loop_3:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    Int_loop_3	    ; (K2-2) * 2 Tcy
    DECFSZ  contador_2,1,0  ; (k2-1) + 3 Tcy
    GOTO    Ext_loop_3	    ; (k2-1) * 2 Tcy
RETURN		    ; 2 Tcy
;Delay_25ms
Delay_25ms:
    MOVLW   25		    ; 1 Tcy -> (k2)
    MOVWF   contador_2,0    ; 1 Tcy
    
;T= (6 + 4k)us
Ext_loop_4:		    ; 2 Tcy -- Call
    MOVLW   249		    ; 1 Tcy -> (k1)
    MOVWF   contador_1,0    ; 1 Tcy
Int_loop_4:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    Int_loop_4	    ; (K2-2) * 2 Tcy
    DECFSZ  contador_2,1,0  ; (k2-1) + 3 Tcy
    GOTO    Ext_loop_4	    ; (k2-1) * 2 Tcy
RETURN		    ; 2 Tcy
    
;Delay_50ms
Delay_50ms:
    MOVLW   50		    ; 1 Tcy -> (k2)
    MOVWF   contador_2,0    ; 1 Tcy
    
;T= (6 + 4k)us
Ext_loop_5:		    ; 2 Tcy -- Call
    MOVLW   249		    ; 1 Tcy -> (k1)
    MOVWF   contador_1,0    ; 1 Tcy
Int_loop_5:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    Int_loop_5	    ; (K2-2) * 2 Tcy
    DECFSZ  contador_2,1,0  ; (k2-1) + 3 Tcy
    GOTO    Ext_loop_5	    ; (k2-1) * 2 Tcy
RETURN		    ; 2 Tcy
    
;Delay_100ms    
Delay_100ms:
    MOVLW   100		    ; 1 Tcy -> (k2)
    MOVWF   contador_2,0    ; 1 Tcy
    
;T= (6 + 4k)us
Ext_loop_6:		    ; 2 Tcy -- Call
    MOVLW   249		    ; 1 Tcy -> (k1)
    MOVWF   contador_1,0    ; 1 Tcy
Int_loop_6:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    Int_loop_6	    ; (K2-2) * 2 Tcy
    DECFSZ  contador_2,1,0  ; (k2-1) + 3 Tcy
    GOTO    Ext_loop_6	    ; (k2-1) * 2 Tcy
RETURN
    
;Delay_200ms
Delay_200ms:
    MOVLW   200		    ; 1 Tcy -> (k2)
    MOVWF   contador_2,0	    ; 1 Tcy
    
;T= (6 + 4k)us
Ext_loop_7:		    ; 2 Tcy -- Call
    MOVLW   249		    ; 1 Tcy -> (k1)
    MOVWF   contador_1,0    ; 1 Tcy
Int_loop_7:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    Int_loop_7	    ; (K2-2) * 2 Tcy
    DECFSZ  contador_2,1,0  ; (k2-1) + 3 Tcy
    GOTO    Ext_loop_7	    ; (k2-1) * 2 Tcy
RETURN		    ; 2 Tcy

;Delay_250ms
 Delay_250ms:
    MOVLW   250		    ; 1 Tcy -> (k2)
    MOVWF   contador_2,0	    ; 1 Tcy
    
;T= (6 + 4k)us
Ext_loop_8:		    ; 2 Tcy -- Call
    MOVLW   249		    ; 1 Tcy -> (k1)
    MOVWF   contador_1,0    ; 1 Tcy
Int_loop_8:
    NOP			    ; (k1 * Tcy)
    DECFSZ  contador_1,1,0  ; (k1-1) + 3 Tcy
    GOTO    Int_loop_8	    ; (K2-2) * 2 Tcy
    DECFSZ  contador_2,1,0  ; (k2-1) + 3 Tcy
    GOTO    Ext_loop_8	    ; (k2-1) * 2 Tcy
RETURN			    ; 2 Tcy