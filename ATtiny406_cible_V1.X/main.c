// Olivier De Thoamsis et Louis Tran 2023
// NRF24L01 on ATtiny406
// Transmitter mode
// Target module

#include "mcc_generated_files/mcc.h"
#include <avr/delay.h>

//Variables
int niveau = 1;
int compteur_tir = 1;
int total_points = 0;
bool is_fast = false,
        is_slow1 = false,
        is_slow2 = false,
        is_slow3 = false,
        is_slow4 = false;

spi0_configuration_t defaults[] = {
    { 0x31, 0x0}
};
/*   Functions   */

//Fonctions du NRF24L01

void init_nrf(void) {
    // SETUP_RETR
    writing_2(0x24, 0x5F, 2);

    // RF_SETUP
    writing_2(0x26, 0x07, 2);

    // FEATURE 1
    writing_2(0x1D, 0xFF, 2);

    // FEATURE 1.1
    writing_2(0x50, 0x73, 2);

    // FEATURE 2
    writing_2(0x1D, 0xFF, 2);

    // DYNPD
    writing_2(0x3C, 0x00, 2);

    // EN_AA
    writing_2(0x21, 0x3F, 2);

    // EN_RXADDR
    writing_2(0x22, 0x03, 2);

    // RX_PW_P0
    writing_2(0x31, 0x20, 2);

    // RX_PW_P1
    writing_2(0x32, 0x20, 2);

    // RX_PW_P2
    writing_2(0x33, 0x20, 2);

    // RX_PW_P3
    writing_2(0x34, 0x20, 2);

    // RX_PW_P4
    writing_2(0x35, 0x20, 2);

    // RX_PW_P5
    writing_2(0x36, 0x20, 2);

    // SETUP_AW
    writing_2(0x23, 0x03, 2);

    // RF_CH
    writing_2(0x25, 0x4C, 2);

    // STATUS
    writing_2(0x27, 0x70, 2);

    // STATUS 1 
    uint8_t tab221[] = {0xE2};
    writing(tab221, 1);

    // STATUS 2 
    uint8_t tab222[] = {0xE1};
    writing(tab222, 1);

    // CONFIG
    writing_2(0x20, 0x0C, 2);

    // CONFIG 1
    writing_2(0x20, 0xFF, 2);

    // CONFIG 2
    writing_2(0x20, 0x0E, 2);

    // RF_SETUP
    writing_2(0x06, 0xFF, 2);

    // RF_SETUP 1
    writing_2(0x26, 0x03, 2);

    // RX_PW_P0
    writing_2(0x31, 0x01, 2);

    // RX_PW_P1
    writing_2(0x32, 0x01, 2);

    // RX_PW_P2
    writing_2(0x33, 0x01, 2);

    // RX_PW_P3
    writing_2(0x34, 0x01, 2);

    // RX_PW_P4
    writing_2(0x35, 0x01, 2);

    // RX_PW_P5
    writing_2(0x36, 0x01, 2);

    // RX_ADDRESS_P0
    uint8_t tab31[] = {0x2A, 0x00, 0xE0, 0xAC, 0x8F, 0x03};
    writing(tab31, 6);

    // TX_ADDRESS
    uint8_t tab32[] = {0x30, 0x00, 0xE0, 0xAC, 0x8F, 0x03};
    writing(tab32, 6);

    // RX_ADDRESS_P1
    uint8_t tab33[] = {0x2B, 0x01, 0xE0, 0xAC, 0x8F, 0x03};
    writing(tab33, 6);

    // EN_RXADDR_1
    writing_2(0x02, 0xFF, 2);

    // EN_RXADDR_2
    writing_2(0x22, 0x03, 2);

    // RF_CH_1
    writing_2(0x25, 0x38, 2);

    // CONFIG
    writing_2(0x20, 0x0E, 2);

    // EN_RXADDR
    writing_2(0x02, 0xFF, 2);

    // EN_RXADDR_1
    writing_2(0x22, 0x03, 2);

    // EN_RXADDR_1.1
    uint8_t tab3811[] = {0xFF};
    writing(tab3811, 1);

    // RX_ADDR_P0
    uint8_t tab39[] = {0x0A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,};
    writing(tab39, 6);

    // RX_ADDR_P1
    uint8_t tab40[] = {0x0B, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,};
    writing(tab40, 6);

    // RX_ADDR_P2
    writing_2(0x0C, 0xFF, 2);

    // RX_ADDR_P3
    writing_2(0x0D, 0xFF, 2);

    // RX_ADDR_P4
    writing_2(0x0E, 0xFF, 2);

    // RX_ADDR_P5
    writing_2(0x0F, 0xFF, 2);

    // TX_ADDR
    uint8_t tab45[] = {0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,};
    writing(tab45, 6);

    // RX_PW_P0
    //uint8_t tab46[] = {0x11, 0xFF};
    writing_2(0x11, 0xFF, 2);

    // RX_PW_P1
    //uint8_t tab47[] = {0x12, 0xFF};
    writing_2(0x12, 0xFF, 2);

    // RX_PW_P2
    //uint8_t tab48[] = {0x13, 0xFF};
    writing_2(0x13, 0xFF, 2);

    // RX_PW_P3
    //uint8_t tab49[] = {0x14, 0xFF};
    writing_2(0x14, 0xFF, 2);

    // RX_PW_P4
    //uint8_t tab50[] = {0x15, 0xFF};
    writing_2(0x15, 0xFF, 2);

    // RX_PW_P5
    //uint8_t tab51[] = {0x16, 0xFF};
    writing_2(0x16, 0xFF, 2);

    // EN_AA
    //uint8_t tab52[] = {0x01, 0xFF};
    writing_2(0x01, 0xFF, 2);

    // EN_RXADDR
    //uint8_t tab53[] = {0x02, 0xFF};
    writing_2(0x02, 0xFF, 2);

    // RF_CH
    //uint8_t tab54[] = {0x05, 0xFF};
    writing_2(0x05, 0xFF, 2);

    // RF_SETUP
    //uint8_t tab55[] = {0x06, 0xFF};
    writing_2(0x06, 0xFF, 2);

    // CONFIG
    //uint8_t tab56[] = {0x00, 0xFF};
    writing_2(0x00, 0xFF, 2);

    // DYNPD
    //uint8_t tab57[] = {0x1C, 0xFF};
    writing_2(0x1C, 0xFF, 2);

    // FEATURE
    //uint8_t tab58[] = {0x1D, 0xFF};
    writing_2(0x1D, 0xFF, 2);

    // RF_SETUP
    //uint8_t tab59[] = {0x06, 0xFF};
    writing_2(0x06, 0xFF, 2);

    // EN_AA
    //uint8_t tab60[] = {0x01, 0xFF};
    writing_2(0x01, 0xFF, 2);

    // CONFIG
    //uint8_t tab61[] = {0x00, 0xFF};
    writing_2(0x00, 0xFF, 2);

    // RF_SETUP
    writing_2(0x06, 0xFF, 2);

    // OBSERVE_TX
    //uint8_t tab62[] = {0x08, 0xFF};
    writing_2(0x08, 0xFF, 2);

    // RF_CH
    //uint8_t tab63[] = {0x05, 0xFF};
    writing_2(0x05, 0xFF, 2);

    // RF_SETUP
    writing_2(0x06, 0xFF, 2);

    // RF_SETUP
    writing_2(0x06, 0xFF, 2);

    // RF_SETUP
    writing_2(0x06, 0xFF, 2);

    // EN_AA
    writing_2(0x01, 0xFF, 2);

    // CONFI
    writing_2(0x00, 0xFF, 2);

    // SETUP_AW
    //uint8_t tab64[] = {0x03, 0xFF};
    writing_2(0x03, 0xFF, 2);

    // SETUP_RETR
    //uint8_t tab65[] = {0x04, 0xFF};
    writing_2(0x04, 0xFF, 2);

    // OBSERVE_TX 
    writing_2(0x08, 0xFF, 2);

    // FEATURE
    writing_2(0x1D, 0xFF, 2);

    // DYNPD
    writing_2(0x1C, 0xFF, 2);

    // EN_AA
    writing_2(0x01, 0xFF, 2);

    // CONFIG
    writing_2(0x00, 0xFF, 2);

    // TX_ADDR
    writing(tab45, 6);

    // EN_RXADDR
    writing_2(0x02, 0xFF, 2);

    // RX_ADDR_P0  
    writing(tab39, 6);

    // RX_ADDR_P1
    writing(tab40, 6);

    // RX_ADDR_P2
    writing_2(0x0C, 0xFF, 2);

    // RX_ADDR_P3
    writing_2(0x0D, 0xFF, 2);

    // RX_ADDR_P4
    writing_2(0x0E, 0xFF, 2);

    // RX_ADDR_P5
    writing_2(0x0F, 0xFF, 2);
}

void writing(uint8_t *tableau, int nb) {
    NRF_CSN_SetLow();
    while (!(SPI0_OpenConfiguration(0)));
    SPI0_WriteBlock(tableau, nb);
    SPI0_Close();
    NRF_CSN_SetHigh();
}

void writing_2(char char1, char char2, int nb) {
    uint8_t tab[] = {char1, char2};
    NRF_CSN_SetLow();
    while (!(SPI0_OpenConfiguration(0)));
    SPI0_WriteBlock(tab, nb);
    SPI0_Close();
    NRF_CSN_SetHigh();
}

// Autres fonctions

void set_level(void) {
    //choix de niveau de difficulté
    niveau++;
    if (niveau > 3) {
        niveau = 1;
    }
    _delay_ms(150);
}

void send_slow1(void) {
    is_slow1 = true;
}

void send_slow2(void) {
    is_slow2 = true;
}

void send_slow3(void) {
    is_slow3 = true;
}

void send_slow4(void) {
    is_slow4 = true;
}

void confirm_fast(void) {
    is_fast = true;
    _delay_ms(50);
}

void turn_false(void) {
    is_slow1 = false;
    is_slow2 = false;
    is_slow3 = false;
    is_slow4 = false;
    is_fast = false;
    _delay_ms(1000);
}

int main(void) {
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();
    Enable_global_interrupt();
    LED_verte_SetLow();
    LED_jaune_SetLow();
    LED_rouge_SetLow();
    _delay_ms(20);
    NRF_CE_SetHigh();
    NRF_CSN_SetHigh();
    _delay_ms(10);

    init_nrf();
    NRF_CE_SetHigh();
    _delay_ms(1);

    PORTB_slow_1_SetInterruptHandler(send_slow1);
    PORTB_slow_2_SetInterruptHandler(send_slow2);
    PORTB_slow_3_SetInterruptHandler(send_slow3);
    PORTB_slow_4_SetInterruptHandler(send_slow4);
    PORTB_fast_SetInterruptHandler(confirm_fast);
    PORTC_BTN_NIV_SetInterruptHandler(set_level);
    turn_false();

    while (1) {

        // Sleep mode ?

        switch (niveau) {
                _delay_ms(100);
            case 1:
                LED_verte_SetHigh();
                LED_jaune_SetLow();
                LED_rouge_SetLow();
                //5 points
                if (is_slow1 || is_slow2 || is_slow3 || is_slow4) {
                    writing_2(0xA0, 0x05, 2); //envoi 5
                    turn_false();
                }//0 points
                else if (is_fast &&!is_slow1 &&!is_slow2 &&!is_slow3 &&!is_slow4) {
                    writing_2(0xA0, 0x01, 2); //envoi 1
                    turn_false();
                }// attente	
                else if (!is_fast &&!is_slow1 &&!is_slow2 &&!is_slow3 &&!is_slow4) {
                    writing_2(0xA0, 0x00, 2); //envoi 0
                    turn_false();
                }
                break;
                //niveau moyen
            case 2:
                LED_verte_SetLow();
                LED_jaune_SetHigh();
                LED_rouge_SetLow();
                //5 points
                if ((is_slow1 || is_slow3) && !(is_slow2 && is_slow4)) {
                    writing_2(0xA0, 0x15, 2); //envoi 21
                    turn_false();
                }//0 points
                else if ((is_slow2 || is_slow4) && !(is_slow1 && is_slow3)) {
                    writing_2(0xA0, 0x11, 2); //envoi 17
                    turn_false();
                }// -1 point
                else if (is_fast &&!is_slow1 &&!is_slow2 &&!is_slow3 &&!is_slow4) {
                    writing_2(0xA0, 0x13, 2); //envoi 19
                    turn_false();
                } else if (!is_fast &&!is_slow1 &&!is_slow2 &&!is_slow3 &&!is_slow4) {
                    writing_2(0xA0, 0x00, 2); //envoi 0
                    turn_false();
                }
                break;

                //niveau difficile    
            case 3:
                LED_verte_SetLow();
                LED_jaune_SetLow();
                LED_rouge_SetHigh();
                //5 points
                if (is_slow1 || is_slow3) {
                    writing_2(0xA0, 0x25, 2); //envoi 37
                    turn_false();
                }//-1 points
                else if (is_slow2 || is_slow4) {
                    writing_2(0xA0, 0x21, 2); //envoi 33
                    turn_false();
                }// -3 point
                else if (is_fast &&!is_slow1 &&!is_slow2 &&!is_slow3 &&!is_slow4) {
                    writing_2(0xA0, 0x23, 2); //envoi 35
                    turn_false();
                } else if (!is_fast &&!is_slow1 &&!is_slow2 &&!is_slow3 &&!is_slow4) {
                    writing_2(0xA0, 0x00, 2); //envoi 0
                    turn_false();
                }
                break;
        }
    }
}

/**
    End of File
 */