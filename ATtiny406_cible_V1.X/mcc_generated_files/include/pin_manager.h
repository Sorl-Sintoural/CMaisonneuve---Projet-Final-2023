/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "port.h"

//get/set slow_3 aliases
#define slow_3_SetHigh() do { PORTB_OUTSET = 0x8; } while(0)
#define slow_3_SetLow() do { PORTB_OUTCLR = 0x8; } while(0)
#define slow_3_Toggle() do { PORTB_OUTTGL = 0x8; } while(0)
#define slow_3_GetValue() (VPORTB.IN & (0x1 << 3))
#define slow_3_SetDigitalInput() do { PORTB_DIRCLR = 0x8; } while(0)
#define slow_3_SetDigitalOutput() do { PORTB_DIRSET = 0x8; } while(0)
#define slow_3_SetPullUp() do { PORTB_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define slow_3_ResetPullUp() do { PORTB_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define slow_3_SetInverted() do { PORTB_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define slow_3_ResetInverted() do { PORTB_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define slow_3_DisableInterruptOnChange() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define slow_3_EnableInterruptForBothEdges() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define slow_3_EnableInterruptForRisingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define slow_3_EnableInterruptForFallingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define slow_3_DisableDigitalInputBuffer() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define slow_3_EnableInterruptForLowLevelSensing() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA2 aliases
#define PA2_SetHigh() do { PORTA_OUTSET = 0x4; } while(0)
#define PA2_SetLow() do { PORTA_OUTCLR = 0x4; } while(0)
#define PA2_Toggle() do { PORTA_OUTTGL = 0x4; } while(0)
#define PA2_GetValue() (VPORTA.IN & (0x1 << 2))
#define PA2_SetDigitalInput() do { PORTA_DIRCLR = 0x4; } while(0)
#define PA2_SetDigitalOutput() do { PORTA_DIRSET = 0x4; } while(0)
#define PA2_SetPullUp() do { PORTA_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA2_ResetPullUp() do { PORTA_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA2_SetInverted() do { PORTA_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define PA2_ResetInverted() do { PORTA_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA2_DisableInterruptOnChange() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA2_EnableInterruptForBothEdges() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA2_EnableInterruptForRisingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA2_EnableInterruptForFallingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA2_DisableDigitalInputBuffer() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA2_EnableInterruptForLowLevelSensing() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set slow_2 aliases
#define slow_2_SetHigh() do { PORTB_OUTSET = 0x4; } while(0)
#define slow_2_SetLow() do { PORTB_OUTCLR = 0x4; } while(0)
#define slow_2_Toggle() do { PORTB_OUTTGL = 0x4; } while(0)
#define slow_2_GetValue() (VPORTB.IN & (0x1 << 2))
#define slow_2_SetDigitalInput() do { PORTB_DIRCLR = 0x4; } while(0)
#define slow_2_SetDigitalOutput() do { PORTB_DIRSET = 0x4; } while(0)
#define slow_2_SetPullUp() do { PORTB_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define slow_2_ResetPullUp() do { PORTB_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define slow_2_SetInverted() do { PORTB_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define slow_2_ResetInverted() do { PORTB_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define slow_2_DisableInterruptOnChange() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define slow_2_EnableInterruptForBothEdges() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define slow_2_EnableInterruptForRisingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define slow_2_EnableInterruptForFallingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define slow_2_DisableDigitalInputBuffer() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define slow_2_EnableInterruptForLowLevelSensing() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set LED_verte aliases
#define LED_verte_SetHigh() do { PORTC_OUTSET = 0x8; } while(0)
#define LED_verte_SetLow() do { PORTC_OUTCLR = 0x8; } while(0)
#define LED_verte_Toggle() do { PORTC_OUTTGL = 0x8; } while(0)
#define LED_verte_GetValue() (VPORTC.IN & (0x1 << 3))
#define LED_verte_SetDigitalInput() do { PORTC_DIRCLR = 0x8; } while(0)
#define LED_verte_SetDigitalOutput() do { PORTC_DIRSET = 0x8; } while(0)
#define LED_verte_SetPullUp() do { PORTC_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LED_verte_ResetPullUp() do { PORTC_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LED_verte_SetInverted() do { PORTC_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define LED_verte_ResetInverted() do { PORTC_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LED_verte_DisableInterruptOnChange() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LED_verte_EnableInterruptForBothEdges() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LED_verte_EnableInterruptForRisingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LED_verte_EnableInterruptForFallingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LED_verte_DisableDigitalInputBuffer() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LED_verte_EnableInterruptForLowLevelSensing() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA1 aliases
#define PA1_SetHigh() do { PORTA_OUTSET = 0x2; } while(0)
#define PA1_SetLow() do { PORTA_OUTCLR = 0x2; } while(0)
#define PA1_Toggle() do { PORTA_OUTTGL = 0x2; } while(0)
#define PA1_GetValue() (VPORTA.IN & (0x1 << 1))
#define PA1_SetDigitalInput() do { PORTA_DIRCLR = 0x2; } while(0)
#define PA1_SetDigitalOutput() do { PORTA_DIRSET = 0x2; } while(0)
#define PA1_SetPullUp() do { PORTA_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA1_ResetPullUp() do { PORTA_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA1_SetInverted() do { PORTA_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define PA1_ResetInverted() do { PORTA_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA1_DisableInterruptOnChange() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA1_EnableInterruptForBothEdges() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA1_EnableInterruptForRisingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA1_EnableInterruptForFallingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA1_DisableDigitalInputBuffer() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA1_EnableInterruptForLowLevelSensing() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set NRF_CE aliases
#define NRF_CE_SetHigh() do { PORTA_OUTSET = 0x10; } while(0)
#define NRF_CE_SetLow() do { PORTA_OUTCLR = 0x10; } while(0)
#define NRF_CE_Toggle() do { PORTA_OUTTGL = 0x10; } while(0)
#define NRF_CE_GetValue() (VPORTA.IN & (0x1 << 4))
#define NRF_CE_SetDigitalInput() do { PORTA_DIRCLR = 0x10; } while(0)
#define NRF_CE_SetDigitalOutput() do { PORTA_DIRSET = 0x10; } while(0)
#define NRF_CE_SetPullUp() do { PORTA_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define NRF_CE_ResetPullUp() do { PORTA_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define NRF_CE_SetInverted() do { PORTA_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define NRF_CE_ResetInverted() do { PORTA_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define NRF_CE_DisableInterruptOnChange() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define NRF_CE_EnableInterruptForBothEdges() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define NRF_CE_EnableInterruptForRisingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define NRF_CE_EnableInterruptForFallingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define NRF_CE_DisableDigitalInputBuffer() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define NRF_CE_EnableInterruptForLowLevelSensing() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set slow_4 aliases
#define slow_4_SetHigh() do { PORTB_OUTSET = 0x10; } while(0)
#define slow_4_SetLow() do { PORTB_OUTCLR = 0x10; } while(0)
#define slow_4_Toggle() do { PORTB_OUTTGL = 0x10; } while(0)
#define slow_4_GetValue() (VPORTB.IN & (0x1 << 4))
#define slow_4_SetDigitalInput() do { PORTB_DIRCLR = 0x10; } while(0)
#define slow_4_SetDigitalOutput() do { PORTB_DIRSET = 0x10; } while(0)
#define slow_4_SetPullUp() do { PORTB_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define slow_4_ResetPullUp() do { PORTB_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define slow_4_SetInverted() do { PORTB_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define slow_4_ResetInverted() do { PORTB_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define slow_4_DisableInterruptOnChange() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define slow_4_EnableInterruptForBothEdges() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define slow_4_EnableInterruptForRisingEdge() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define slow_4_EnableInterruptForFallingEdge() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define slow_4_DisableDigitalInputBuffer() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define slow_4_EnableInterruptForLowLevelSensing() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA3 aliases
#define PA3_SetHigh() do { PORTA_OUTSET = 0x8; } while(0)
#define PA3_SetLow() do { PORTA_OUTCLR = 0x8; } while(0)
#define PA3_Toggle() do { PORTA_OUTTGL = 0x8; } while(0)
#define PA3_GetValue() (VPORTA.IN & (0x1 << 3))
#define PA3_SetDigitalInput() do { PORTA_DIRCLR = 0x8; } while(0)
#define PA3_SetDigitalOutput() do { PORTA_DIRSET = 0x8; } while(0)
#define PA3_SetPullUp() do { PORTA_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA3_ResetPullUp() do { PORTA_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA3_SetInverted() do { PORTA_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define PA3_ResetInverted() do { PORTA_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA3_DisableInterruptOnChange() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA3_EnableInterruptForBothEdges() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA3_EnableInterruptForRisingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA3_EnableInterruptForFallingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA3_DisableDigitalInputBuffer() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA3_EnableInterruptForLowLevelSensing() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set NRF_IRQ aliases
#define NRF_IRQ_SetHigh() do { PORTA_OUTSET = 0x40; } while(0)
#define NRF_IRQ_SetLow() do { PORTA_OUTCLR = 0x40; } while(0)
#define NRF_IRQ_Toggle() do { PORTA_OUTTGL = 0x40; } while(0)
#define NRF_IRQ_GetValue() (VPORTA.IN & (0x1 << 6))
#define NRF_IRQ_SetDigitalInput() do { PORTA_DIRCLR = 0x40; } while(0)
#define NRF_IRQ_SetDigitalOutput() do { PORTA_DIRSET = 0x40; } while(0)
#define NRF_IRQ_SetPullUp() do { PORTA_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define NRF_IRQ_ResetPullUp() do { PORTA_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define NRF_IRQ_SetInverted() do { PORTA_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define NRF_IRQ_ResetInverted() do { PORTA_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define NRF_IRQ_DisableInterruptOnChange() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define NRF_IRQ_EnableInterruptForBothEdges() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define NRF_IRQ_EnableInterruptForRisingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define NRF_IRQ_EnableInterruptForFallingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define NRF_IRQ_DisableDigitalInputBuffer() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define NRF_IRQ_EnableInterruptForLowLevelSensing() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set NRF_CSN aliases
#define NRF_CSN_SetHigh() do { PORTA_OUTSET = 0x20; } while(0)
#define NRF_CSN_SetLow() do { PORTA_OUTCLR = 0x20; } while(0)
#define NRF_CSN_Toggle() do { PORTA_OUTTGL = 0x20; } while(0)
#define NRF_CSN_GetValue() (VPORTA.IN & (0x1 << 5))
#define NRF_CSN_SetDigitalInput() do { PORTA_DIRCLR = 0x20; } while(0)
#define NRF_CSN_SetDigitalOutput() do { PORTA_DIRSET = 0x20; } while(0)
#define NRF_CSN_SetPullUp() do { PORTA_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define NRF_CSN_ResetPullUp() do { PORTA_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define NRF_CSN_SetInverted() do { PORTA_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define NRF_CSN_ResetInverted() do { PORTA_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define NRF_CSN_DisableInterruptOnChange() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define NRF_CSN_EnableInterruptForBothEdges() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define NRF_CSN_EnableInterruptForRisingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define NRF_CSN_EnableInterruptForFallingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define NRF_CSN_DisableDigitalInputBuffer() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define NRF_CSN_EnableInterruptForLowLevelSensing() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set BTN_NIV aliases
#define BTN_NIV_SetHigh() do { PORTC_OUTSET = 0x1; } while(0)
#define BTN_NIV_SetLow() do { PORTC_OUTCLR = 0x1; } while(0)
#define BTN_NIV_Toggle() do { PORTC_OUTTGL = 0x1; } while(0)
#define BTN_NIV_GetValue() (VPORTC.IN & (0x1 << 0))
#define BTN_NIV_SetDigitalInput() do { PORTC_DIRCLR = 0x1; } while(0)
#define BTN_NIV_SetDigitalOutput() do { PORTC_DIRSET = 0x1; } while(0)
#define BTN_NIV_SetPullUp() do { PORTC_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define BTN_NIV_ResetPullUp() do { PORTC_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define BTN_NIV_SetInverted() do { PORTC_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define BTN_NIV_ResetInverted() do { PORTC_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define BTN_NIV_DisableInterruptOnChange() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define BTN_NIV_EnableInterruptForBothEdges() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define BTN_NIV_EnableInterruptForRisingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define BTN_NIV_EnableInterruptForFallingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define BTN_NIV_DisableDigitalInputBuffer() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define BTN_NIV_EnableInterruptForLowLevelSensing() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set slow_1 aliases
#define slow_1_SetHigh() do { PORTB_OUTSET = 0x2; } while(0)
#define slow_1_SetLow() do { PORTB_OUTCLR = 0x2; } while(0)
#define slow_1_Toggle() do { PORTB_OUTTGL = 0x2; } while(0)
#define slow_1_GetValue() (VPORTB.IN & (0x1 << 1))
#define slow_1_SetDigitalInput() do { PORTB_DIRCLR = 0x2; } while(0)
#define slow_1_SetDigitalOutput() do { PORTB_DIRSET = 0x2; } while(0)
#define slow_1_SetPullUp() do { PORTB_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define slow_1_ResetPullUp() do { PORTB_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define slow_1_SetInverted() do { PORTB_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define slow_1_ResetInverted() do { PORTB_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define slow_1_DisableInterruptOnChange() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define slow_1_EnableInterruptForBothEdges() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define slow_1_EnableInterruptForRisingEdge() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define slow_1_EnableInterruptForFallingEdge() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define slow_1_DisableDigitalInputBuffer() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define slow_1_EnableInterruptForLowLevelSensing() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set LED_jaune aliases
#define LED_jaune_SetHigh() do { PORTC_OUTSET = 0x4; } while(0)
#define LED_jaune_SetLow() do { PORTC_OUTCLR = 0x4; } while(0)
#define LED_jaune_Toggle() do { PORTC_OUTTGL = 0x4; } while(0)
#define LED_jaune_GetValue() (VPORTC.IN & (0x1 << 2))
#define LED_jaune_SetDigitalInput() do { PORTC_DIRCLR = 0x4; } while(0)
#define LED_jaune_SetDigitalOutput() do { PORTC_DIRSET = 0x4; } while(0)
#define LED_jaune_SetPullUp() do { PORTC_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LED_jaune_ResetPullUp() do { PORTC_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LED_jaune_SetInverted() do { PORTC_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define LED_jaune_ResetInverted() do { PORTC_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LED_jaune_DisableInterruptOnChange() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LED_jaune_EnableInterruptForBothEdges() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LED_jaune_EnableInterruptForRisingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LED_jaune_EnableInterruptForFallingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LED_jaune_DisableDigitalInputBuffer() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LED_jaune_EnableInterruptForLowLevelSensing() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set fast aliases
#define fast_SetHigh() do { PORTB_OUTSET = 0x1; } while(0)
#define fast_SetLow() do { PORTB_OUTCLR = 0x1; } while(0)
#define fast_Toggle() do { PORTB_OUTTGL = 0x1; } while(0)
#define fast_GetValue() (VPORTB.IN & (0x1 << 0))
#define fast_SetDigitalInput() do { PORTB_DIRCLR = 0x1; } while(0)
#define fast_SetDigitalOutput() do { PORTB_DIRSET = 0x1; } while(0)
#define fast_SetPullUp() do { PORTB_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define fast_ResetPullUp() do { PORTB_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define fast_SetInverted() do { PORTB_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define fast_ResetInverted() do { PORTB_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define fast_DisableInterruptOnChange() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define fast_EnableInterruptForBothEdges() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define fast_EnableInterruptForRisingEdge() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define fast_EnableInterruptForFallingEdge() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define fast_DisableDigitalInputBuffer() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define fast_EnableInterruptForLowLevelSensing() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set LED_rouge aliases
#define LED_rouge_SetHigh() do { PORTC_OUTSET = 0x2; } while(0)
#define LED_rouge_SetLow() do { PORTC_OUTCLR = 0x2; } while(0)
#define LED_rouge_Toggle() do { PORTC_OUTTGL = 0x2; } while(0)
#define LED_rouge_GetValue() (VPORTC.IN & (0x1 << 1))
#define LED_rouge_SetDigitalInput() do { PORTC_DIRCLR = 0x2; } while(0)
#define LED_rouge_SetDigitalOutput() do { PORTC_DIRSET = 0x2; } while(0)
#define LED_rouge_SetPullUp() do { PORTC_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LED_rouge_ResetPullUp() do { PORTC_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LED_rouge_SetInverted() do { PORTC_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define LED_rouge_ResetInverted() do { PORTC_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LED_rouge_DisableInterruptOnChange() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LED_rouge_EnableInterruptForBothEdges() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LED_rouge_EnableInterruptForRisingEdge() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LED_rouge_EnableInterruptForFallingEdge() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LED_rouge_DisableDigitalInputBuffer() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LED_rouge_EnableInterruptForLowLevelSensing() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

void PIN_MANAGER_Initialize();
void PORTB_slow_3_DefaultInterruptHandler(void);
void PORTB_slow_3_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA2_DefaultInterruptHandler(void);
void PORTA_PA2_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_slow_2_DefaultInterruptHandler(void);
void PORTB_slow_2_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_LED_verte_DefaultInterruptHandler(void);
void PORTC_LED_verte_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA1_DefaultInterruptHandler(void);
void PORTA_PA1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_NRF_CE_DefaultInterruptHandler(void);
void PORTA_NRF_CE_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_slow_4_DefaultInterruptHandler(void);
void PORTB_slow_4_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA3_DefaultInterruptHandler(void);
void PORTA_PA3_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_NRF_IRQ_DefaultInterruptHandler(void);
void PORTA_NRF_IRQ_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_NRF_CSN_DefaultInterruptHandler(void);
void PORTA_NRF_CSN_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_BTN_NIV_DefaultInterruptHandler(void);
void PORTC_BTN_NIV_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_slow_1_DefaultInterruptHandler(void);
void PORTB_slow_1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_LED_jaune_DefaultInterruptHandler(void);
void PORTC_LED_jaune_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_fast_DefaultInterruptHandler(void);
void PORTB_fast_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_LED_rouge_DefaultInterruptHandler(void);
void PORTC_LED_rouge_SetInterruptHandler(void (* interruptHandler)(void)) ;
#endif /* PINS_H_INCLUDED */
