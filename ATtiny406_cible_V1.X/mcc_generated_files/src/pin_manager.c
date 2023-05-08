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


#include "../include/pin_manager.h"
static void (*PORTB_slow_3_InterruptHandler)(void);
static void (*PORTA_PA2_InterruptHandler)(void);
static void (*PORTB_slow_2_InterruptHandler)(void);
static void (*PORTC_LED_verte_InterruptHandler)(void);
static void (*PORTA_PA1_InterruptHandler)(void);
static void (*PORTA_NRF_CE_InterruptHandler)(void);
static void (*PORTB_slow_4_InterruptHandler)(void);
static void (*PORTA_PA3_InterruptHandler)(void);
static void (*PORTA_NRF_IRQ_InterruptHandler)(void);
static void (*PORTA_NRF_CSN_InterruptHandler)(void);
static void (*PORTC_BTN_NIV_InterruptHandler)(void);
static void (*PORTB_slow_1_InterruptHandler)(void);
static void (*PORTC_LED_jaune_InterruptHandler)(void);
static void (*PORTB_fast_InterruptHandler)(void);
static void (*PORTC_LED_rouge_InterruptHandler)(void);

void PORT_Initialize(void);

void PIN_MANAGER_Initialize()
{
    PORT_Initialize();

    /* DIR Registers Initialization */
    PORTA.DIR = 0x7A;
    PORTB.DIR = 0x00;
    PORTC.DIR = 0x0E;

    /* OUT Registers Initialization */
    PORTA.OUT = 0x20;
    PORTB.OUT = 0x00;
    PORTC.OUT = 0x00;

    /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x00;
    PORTA.PIN1CTRL = 0x00;
    PORTA.PIN2CTRL = 0x00;
    PORTA.PIN3CTRL = 0x00;
    PORTA.PIN4CTRL = 0x00;
    PORTA.PIN5CTRL = 0x00;
    PORTA.PIN6CTRL = 0x00;
    PORTA.PIN7CTRL = 0x00;
    PORTB.PIN0CTRL = 0x02;
    PORTB.PIN1CTRL = 0x02;
    PORTB.PIN2CTRL = 0x02;
    PORTB.PIN3CTRL = 0x02;
    PORTB.PIN4CTRL = 0x02;
    PORTB.PIN5CTRL = 0x00;
    PORTB.PIN6CTRL = 0x00;
    PORTB.PIN7CTRL = 0x00;
    PORTC.PIN0CTRL = 0x03;
    PORTC.PIN1CTRL = 0x00;
    PORTC.PIN2CTRL = 0x00;
    PORTC.PIN3CTRL = 0x00;
    PORTC.PIN4CTRL = 0x00;
    PORTC.PIN5CTRL = 0x00;
    PORTC.PIN6CTRL = 0x00;
    PORTC.PIN7CTRL = 0x00;

    /* PORTMUX Initialization */
    PORTMUX.CTRLA = 0x00;
    PORTMUX.CTRLB = 0x00;
    PORTMUX.CTRLC = 0x00;
    PORTMUX.CTRLD = 0x00;

    // register default ISC callback functions at runtime; use these methods to register a custom function
    PORTB_slow_3_SetInterruptHandler(PORTB_slow_3_DefaultInterruptHandler);
    PORTA_PA2_SetInterruptHandler(PORTA_PA2_DefaultInterruptHandler);
    PORTB_slow_2_SetInterruptHandler(PORTB_slow_2_DefaultInterruptHandler);
    PORTC_LED_verte_SetInterruptHandler(PORTC_LED_verte_DefaultInterruptHandler);
    PORTA_PA1_SetInterruptHandler(PORTA_PA1_DefaultInterruptHandler);
    PORTA_NRF_CE_SetInterruptHandler(PORTA_NRF_CE_DefaultInterruptHandler);
    PORTB_slow_4_SetInterruptHandler(PORTB_slow_4_DefaultInterruptHandler);
    PORTA_PA3_SetInterruptHandler(PORTA_PA3_DefaultInterruptHandler);
    PORTA_NRF_IRQ_SetInterruptHandler(PORTA_NRF_IRQ_DefaultInterruptHandler);
    PORTA_NRF_CSN_SetInterruptHandler(PORTA_NRF_CSN_DefaultInterruptHandler);
    PORTC_BTN_NIV_SetInterruptHandler(PORTC_BTN_NIV_DefaultInterruptHandler);
    PORTB_slow_1_SetInterruptHandler(PORTB_slow_1_DefaultInterruptHandler);
    PORTC_LED_jaune_SetInterruptHandler(PORTC_LED_jaune_DefaultInterruptHandler);
    PORTB_fast_SetInterruptHandler(PORTB_fast_DefaultInterruptHandler);
    PORTC_LED_rouge_SetInterruptHandler(PORTC_LED_rouge_DefaultInterruptHandler);
}

void PORT_Initialize(void)
{
    /* On AVR devices all peripherals are enable from power on reset, this
     * disables all peripherals to save power. Driver shall enable
     * peripheral if used */

    /* Set all pins to low power mode */
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTA + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTB + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTC + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
}

/**
  Allows selecting an interrupt handler for PORTB_slow_3 at application runtime
*/
void PORTB_slow_3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_slow_3_InterruptHandler = interruptHandler;
}

void PORTB_slow_3_DefaultInterruptHandler(void)
{
    // add your PORTB_slow_3 interrupt custom code
    // or set custom function using PORTB_slow_3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA2 at application runtime
*/
void PORTA_PA2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA2_InterruptHandler = interruptHandler;
}

void PORTA_PA2_DefaultInterruptHandler(void)
{
    // add your PORTA_PA2 interrupt custom code
    // or set custom function using PORTA_PA2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_slow_2 at application runtime
*/
void PORTB_slow_2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_slow_2_InterruptHandler = interruptHandler;
}

void PORTB_slow_2_DefaultInterruptHandler(void)
{
    // add your PORTB_slow_2 interrupt custom code
    // or set custom function using PORTB_slow_2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_LED_verte at application runtime
*/
void PORTC_LED_verte_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_LED_verte_InterruptHandler = interruptHandler;
}

void PORTC_LED_verte_DefaultInterruptHandler(void)
{
    // add your PORTC_LED_verte interrupt custom code
    // or set custom function using PORTC_LED_verte_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA1 at application runtime
*/
void PORTA_PA1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA1_InterruptHandler = interruptHandler;
}

void PORTA_PA1_DefaultInterruptHandler(void)
{
    // add your PORTA_PA1 interrupt custom code
    // or set custom function using PORTA_PA1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_NRF_CE at application runtime
*/
void PORTA_NRF_CE_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_NRF_CE_InterruptHandler = interruptHandler;
}

void PORTA_NRF_CE_DefaultInterruptHandler(void)
{
    // add your PORTA_NRF_CE interrupt custom code
    // or set custom function using PORTA_NRF_CE_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_slow_4 at application runtime
*/
void PORTB_slow_4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_slow_4_InterruptHandler = interruptHandler;
}

void PORTB_slow_4_DefaultInterruptHandler(void)
{
    // add your PORTB_slow_4 interrupt custom code
    // or set custom function using PORTB_slow_4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA3 at application runtime
*/
void PORTA_PA3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA3_InterruptHandler = interruptHandler;
}

void PORTA_PA3_DefaultInterruptHandler(void)
{
    // add your PORTA_PA3 interrupt custom code
    // or set custom function using PORTA_PA3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_NRF_IRQ at application runtime
*/
void PORTA_NRF_IRQ_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_NRF_IRQ_InterruptHandler = interruptHandler;
}

void PORTA_NRF_IRQ_DefaultInterruptHandler(void)
{
    // add your PORTA_NRF_IRQ interrupt custom code
    // or set custom function using PORTA_NRF_IRQ_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_NRF_CSN at application runtime
*/
void PORTA_NRF_CSN_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_NRF_CSN_InterruptHandler = interruptHandler;
}

void PORTA_NRF_CSN_DefaultInterruptHandler(void)
{
    // add your PORTA_NRF_CSN interrupt custom code
    // or set custom function using PORTA_NRF_CSN_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_BTN_NIV at application runtime
*/
void PORTC_BTN_NIV_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_BTN_NIV_InterruptHandler = interruptHandler;
}

void PORTC_BTN_NIV_DefaultInterruptHandler(void)
{
    // add your PORTC_BTN_NIV interrupt custom code
    // or set custom function using PORTC_BTN_NIV_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_slow_1 at application runtime
*/
void PORTB_slow_1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_slow_1_InterruptHandler = interruptHandler;
}

void PORTB_slow_1_DefaultInterruptHandler(void)
{
    // add your PORTB_slow_1 interrupt custom code
    // or set custom function using PORTB_slow_1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_LED_jaune at application runtime
*/
void PORTC_LED_jaune_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_LED_jaune_InterruptHandler = interruptHandler;
}

void PORTC_LED_jaune_DefaultInterruptHandler(void)
{
    // add your PORTC_LED_jaune interrupt custom code
    // or set custom function using PORTC_LED_jaune_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_fast at application runtime
*/
void PORTB_fast_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_fast_InterruptHandler = interruptHandler;
}

void PORTB_fast_DefaultInterruptHandler(void)
{
    // add your PORTB_fast interrupt custom code
    // or set custom function using PORTB_fast_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_LED_rouge at application runtime
*/
void PORTC_LED_rouge_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_LED_rouge_InterruptHandler = interruptHandler;
}

void PORTC_LED_rouge_DefaultInterruptHandler(void)
{
    // add your PORTC_LED_rouge interrupt custom code
    // or set custom function using PORTC_LED_rouge_SetInterruptHandler()
}
ISR(PORTB_PORT_vect)
{  
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTB.INTFLAGS & PORT_INT3_bm)
    {
       PORTB_slow_3_InterruptHandler();
    }
    if(VPORTB.INTFLAGS & PORT_INT2_bm)
    {
       PORTB_slow_2_InterruptHandler();
    }
    if(VPORTB.INTFLAGS & PORT_INT4_bm)
    {
       PORTB_slow_4_InterruptHandler();
    }
    if(VPORTB.INTFLAGS & PORT_INT1_bm)
    {
       PORTB_slow_1_InterruptHandler();
    }
    if(VPORTB.INTFLAGS & PORT_INT0_bm)
    {
       PORTB_fast_InterruptHandler();
    }

    /* Clear interrupt flags */
    VPORTB.INTFLAGS = 0xff;
}

ISR(PORTC_PORT_vect)
{  
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTC.INTFLAGS & PORT_INT3_bm)
    {
       PORTC_LED_verte_InterruptHandler();
    }
    if(VPORTC.INTFLAGS & PORT_INT0_bm)
    {
       PORTC_BTN_NIV_InterruptHandler();
    }
    if(VPORTC.INTFLAGS & PORT_INT2_bm)
    {
       PORTC_LED_jaune_InterruptHandler();
    }
    if(VPORTC.INTFLAGS & PORT_INT1_bm)
    {
       PORTC_LED_rouge_InterruptHandler();
    }

    /* Clear interrupt flags */
    VPORTC.INTFLAGS = 0xff;
}

