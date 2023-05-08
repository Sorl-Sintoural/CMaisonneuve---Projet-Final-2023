// Olivier De Thoamsis et Louis Tran 2023
// NRF24L01 on ATtiny406
// Receiver mode
// Monitor module
#include "mcc_generated_files/mcc.h"
#include <util/delay.h>
#include <string.h>

// variable NRF24L01
uint8_t data_read;

//Compteur de tirs
uint8_t compteur_t = 1;

// Choix de points
int compte_pts = 0;
char texte_score[21] = {'_                   '};

//Texte à afficher
//Niveau Facile
const char point5F[] = {"_  NIV F : +5 PTS   "};
//Niveau Moyen
const char point5M[] = {"_  NIV M : +5 PTS   "};
//Niveau Difficile
const char point5D[] = {"_  NIV D : +5 PTS   "};
const char point1[] = {"_  OUF... : -1 PTS  "};
const char point0[] = {"_  DOMMAGE :  0 PTS "};
const char point3D[] = {"_  NIV D : -3 PTS   "};
//Fin de jeu
const char FinJ[] = {"_     FIN DE JEU ! "};

//Variable d'I2C
const char buffer1[] = {0x00, 0x39};
const char buffer2[] = {0x14, 0x70, 0x5E, 0x6D, 0x0C, 0x01, 0x06};
const char clear_lcd[] = {0x00, 0x01};
const char switch_line[] = {0x00, 0xC0};

const char slave2write = 0x3C; //3C for BiZ (0x78 shifted over 1 bit)
const char datasend = 0x40; //Commande d'envoie de data

// CUSTOM functions

void itoa_custom(char * txt, int n) {
    char neg;
    if (n < 0) {
        neg = '-';
        n = -n;
    } else {
        neg = ' ';
    }
    char unit = ((n % 10));
    char diz = ((n - unit) % 100) / 10;
    txt[0] = '_';
    txt[6] = ' ';
    txt[7] = 'P';
    txt[8] = 'T';
    txt[9] = 'S';
    txt[10] = ':';
    txt[11] = neg;
    txt[12] = diz + 48;
    txt[13] = unit + 48;
    compteur_t++;
}

void reset(void) {
    LED_JAUNE();
    printing("_  NOUVELLE PARTIE  ", "_     LANCER !      ");
    compteur_t = 1;
    compte_pts = 0;
    LED_OUT();
}

void compte_5(void){
    compte_pts = compte_pts + 5;
}

// LED functions

void LED_OUT(void) {
    LEDs_rouge_SetHigh();
    LED_verte_1_SetHigh();
    LED_verte_2_SetHigh();
    LED_verte_3_SetHigh();
    LED_verte_4_SetHigh();
    LED_verte_5_SetHigh();
}

void LED_ROUGE(void) {
    LEDs_rouge_SetLow();
    LED_verte_1_SetHigh();
    LED_verte_2_SetHigh();
    LED_verte_3_SetHigh();
    LED_verte_4_SetHigh();
    LED_verte_5_SetHigh();
}

void LED_VERTE(void) {
    LEDs_rouge_SetHigh();
    LED_verte_1_SetLow();
    LED_verte_2_SetLow();
    LED_verte_3_SetLow();
    LED_verte_4_SetLow();
    LED_verte_5_SetLow();
}

void LED_JAUNE(void) {
    LEDs_rouge_SetLow();
    LED_verte_1_SetLow();
    LED_verte_2_SetLow();
    LED_verte_3_SetLow();
    LED_verte_4_SetLow();
    LED_verte_5_SetLow();
}

// NRF24L01 functions

void writing(uint8_t *tableau, int nb) {
    NRF_CSN_SetLow();
    while (!(SPI0_OpenConfiguration(0)));
    SPI0_WriteBlock(tableau, nb);
    SPI0_Close();
    NRF_CSN_SetHigh();
}

void writing_2(char char1, char char2) {
    uint8_t tab[] = {char1, char2};
    NRF_CSN_SetLow();
    while (!(SPI0_OpenConfiguration(0)));
    SPI0_WriteBlock(tab, 2);
    SPI0_Close();
    NRF_CSN_SetHigh();
}

void init_nrf(void) {
    // SETUP_RETR
    writing_2(0x24, 0x5F);

    // RF_SETUP
    writing_2(0x26, 0x07);

    // FEATURE 1
    writing_2(0x1D, 0xFF);

    // FEATURE 1.1
    writing_2(0x50, 0x73);

    // FEATURE 2
    writing_2(0x1D, 0xFF);

    // DYNPD
    writing_2(0x3C, 0x00);

    // EN_AA
    writing_2(0x21, 0x3F);

    // EN_RXADDR
    writing_2(0x22, 0x03);

    // RX_PW_P0
    writing_2(0x31, 0x20);

    // RX_PW_P1
    writing_2(0x32, 0x20);

    // RX_PW_P2
    writing_2(0x33, 0x20);

    // RX_PW_P3
    writing_2(0x34, 0x20);

    // RX_PW_P4
    writing_2(0x35, 0x20);

    // RX_PW_P5
    writing_2(0x36, 0x20);

    // SETUP_AW
    writing_2(0x23, 0x03);

    // RF_CH
    writing_2(0x25, 0x4C);

    // STATUS
    writing_2(0x27, 0x70);

    // STATUS 1 
    uint8_t tab221[] = {0xE2};
    writing(tab221, 1);

    // STATUS 2 
    uint8_t tab222[] = {0xE1};
    writing(tab222, 1);

    // CONFIG
    writing_2(0x20, 0x0C);

    // CONFIG 1
    writing_2(0x20, 0xFF);

    // CONFIG 2
    writing_2(0x20, 0x0E);

    // RF_SETUP
    writing_2(0x06, 0xFF);

    // RF_SETUP 1
    writing_2(0x26, 0x03);

    // RX_PW_P0
    writing_2(0x31, 0x01);

    // RX_PW_P1
    writing_2(0x32, 0x01);

    // RX_PW_P2
    writing_2(0x33, 0x01);

    // RX_PW_P3
    writing_2(0x34, 0x01);

    // RX_PW_P4
    writing_2(0x35, 0x01);

    // RX_PW_P5
    writing_2(0x36, 0x01);

    // RX_ADDRESS_P0
    uint8_t tab31[] = {0x2A, 0x01, 0xE0, 0xAC, 0x8F, 0x03};
    writing(tab31, 6);

    // TX_ADDRESS
    uint8_t tab32[] = {0x30, 0x01, 0xE0, 0xAC, 0x8F, 0x03};
    writing(tab32, 6);

    // RX_ADDRESS_P1
    uint8_t tab33[] = {0x2B, 0x00, 0xE0, 0xAC, 0x8F, 0x03};
    writing(tab33, 6);

    // EN_RXADDR_1
    writing_2(0x02, 0xFF);

    // EN_RXADDR_2
    writing_2(0x22, 0x03);

    // RF_CH_1
    writing_2(0x25, 0x38);

    // CONFIG
    writing_2(0x20, 0x0F);

    // STATUS
    writing_2(0x27, 0x70);

    // EN_RXADDR
    writing_2(0x02, 0xFF);

    // EN_RXADDR_1
    writing_2(0x22, 0x02);

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
    writing_2(0x0C, 0xFF);

    // RX_ADDR_P3
    writing_2(0x0D, 0xFF);

    // RX_ADDR_P4
    writing_2(0x0E, 0xFF);

    // RX_ADDR_P5
    writing_2(0x0F, 0xFF);

    // TX_ADDR
    uint8_t tab45[] = {0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,};
    writing(tab45, 6);

    // RX_PW_P0
    //uint8_t tab46[] = {0x11, 0xFF};
    writing_2(0x11, 0xFF);

    // RX_PW_P1
    //uint8_t tab47[] = {0x12, 0xFF};
    writing_2(0x12, 0xFF);

    // RX_PW_P2
    //uint8_t tab48[] = {0x13, 0xFF};
    writing_2(0x13, 0xFF);

    // RX_PW_P3
    //uint8_t tab49[] = {0x14, 0xFF};
    writing_2(0x14, 0xFF);

    // RX_PW_P4
    //uint8_t tab50[] = {0x15, 0xFF};
    writing_2(0x15, 0xFF);

    // RX_PW_P5
    //uint8_t tab51[] = {0x16, 0xFF};
    writing_2(0x16, 0xFF);

    // EN_AA
    //uint8_t tab52[] = {0x01, 0xFF};
    writing_2(0x01, 0xFF);

    // EN_RXADDR
    //uint8_t tab53[] = {0x02, 0xFF};
    writing_2(0x02, 0xFF);

    // RF_CH
    //uint8_t tab54[] = {0x05, 0xFF};
    writing_2(0x05, 0xFF);

    // RF_SETUP
    //uint8_t tab55[] = {0x06, 0xFF};
    writing_2(0x06, 0xFF);

    // CONFIG
    //uint8_t tab56[] = {0x00, 0xFF};
    writing_2(0x00, 0xFF);

    // DYNPD
    //uint8_t tab57[] = {0x1C, 0xFF};
    writing_2(0x1C, 0xFF);

    // FEATURE
    //uint8_t tab58[] = {0x1D, 0xFF};
    writing_2(0x1D, 0xFF);

    // RF_SETUP
    //uint8_t tab59[] = {0x06, 0xFF};
    writing_2(0x06, 0xFF);

    // EN_AA
    //uint8_t tab60[] = {0x01, 0xFF};
    writing_2(0x01, 0xFF);

    // CONFIG
    //uint8_t tab61[] = {0x00, 0xFF};
    writing_2(0x00, 0xFF);

    // RF_SETUP
    writing_2(0x06, 0xFF);

    // OBSERVE_TX
    //uint8_t tab62[] = {0x08, 0xFF};
    writing_2(0x08, 0xFF);

    // RF_CH
    //uint8_t tab63[] = {0x05, 0xFF};
    writing_2(0x05, 0xFF);

    // RF_SETUP
    writing_2(0x06, 0xFF);

    // RF_SETUP
    writing_2(0x06, 0xFF);

    // RF_SETUP
    writing_2(0x06, 0xFF);

    // EN_AA
    writing_2(0x01, 0xFF);

    // CONFI
    writing_2(0x00, 0xFF);

    // SETUP_AW
    //uint8_t tab64[] = {0x03, 0xFF};
    writing_2(0x03, 0xFF);

    // SETUP_RETR
    //uint8_t tab65[] = {0x04, 0xFF};
    writing_2(0x04, 0xFF);

    // OBSERVE_TX 
    writing_2(0x08, 0xFF);

    // FEATURE
    writing_2(0x1D, 0xFF);

    // DYNPD
    writing_2(0x1C, 0xFF);

    // EN_AA
    writing_2(0x01, 0xFF);

    // CONFIG
    writing_2(0x00, 0xFF);

    // TX_ADDR
    writing(tab45, 6);

    // EN_RXADDR
    writing_2(0x02, 0xFF);

    // RX_ADDR_P0  
    writing(tab39, 6);

    // RX_ADDR_P1
    writing(tab40, 6);

    // RX_ADDR_P2
    writing_2(0x0C, 0xFF);

    // RX_ADDR_P3
    writing_2(0x0D, 0xFF);

    // RX_ADDR_P4
    writing_2(0x0E, 0xFF);

    // RX_ADDR_P5
    writing_2(0x0F, 0xFF);

}
//* Receive an hex as payload with command word (Table 19 | Page 48) *//

uint8_t nrf_read(void) {
    uint8_t payload;
    uint8_t commande[] = {0x61, 0xFF};

    NRF_CSN_SetLow();
    while (!(SPI0_OpenConfiguration(0)));
    SPI0_WriteBlock(commande, 2);
    payload = SPI0_ReadByte();
    SPI0_Close();
    NRF_CSN_SetHigh();
    return payload;
}

// I2C functions

void lcd_control(unsigned char cmd, unsigned char *text) {
    I2C0_Open(slave2write);
    if (cmd == 0) {  //affichage du texte
        I2C0_SetBuffer(&datasend, 1); //0x40
        I2C0_MasterWrite();
        _delay_ms(1);
        I2C0_SetBuffer(text, 20); //texte de 20 caractères
        I2C0_MasterWrite();
    } else if (cmd == 1) { //changement de ligne
        I2C0_SetBuffer(switch_line, 2);
        I2C0_MasterWrite();
    } else if (cmd == 2) { //effacer l'écran
        I2C0_SetBuffer(clear_lcd, 2);
        I2C0_MasterWrite();
    }
    I2C0_Close();
}
//Ancienne fonctions pour l'écran

//void affichage(unsigned char *text) {
//
//    I2C0_Open(slave2write);
//    I2C0_SetBuffer(&datasend, 1); //0x40
//    I2C0_MasterWrite();
//    _delay_ms(1);
//    I2C0_SetBuffer(text, 20); //texte de 20 caractères
//    I2C0_MasterWrite();
//    _delay_ms(1);
//    I2C0_Close();
//}
//
//void proch_ligne(void) {
//
//    I2C0_Open(slave2write);
//    I2C0_SetBuffer(switch_line, 2);
//    I2C0_MasterWrite();
//    I2C0_Close();
//}
//
//void clear_LCD(void) {
//
//    I2C0_Open(slave2write);
//    I2C0_SetBuffer(clear_lcd, 2);
//    I2C0_MasterWrite();
//    I2C0_Close();
//}

void printing(unsigned char *texte1, unsigned char *texte2) {
    lcd_control(2, 0);
    _delay_ms(2);
    lcd_control(0, texte1);
    lcd_control(1, 0);
    _delay_ms(2);
    lcd_control(0, texte2);
    _delay_ms(1000);
}

void Ciz_init() {
    I2C0_Open(slave2write);
    I2C0_SetBuffer(buffer1, 2);
    I2C0_MasterWrite();
    I2C0_SetBuffer(buffer2, 7);
    I2C0_MasterWrite();
    I2C0_Close();
    _delay_ms(100);
}

int main(void) {
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();
    _delay_ms(10);
    Ciz_init(); //initialisation de l'écran
    reset();
//    printing("_  NOUVELLE PARTIE  ", "_     LANCER !      ");
    while (1) {
        _delay_ms(2);
        NRF_CE_SetHigh();
        NRF_CSN_SetHigh();
        _delay_ms(10);
        init_nrf();
        NRF_CE_SetHigh();
        data_read = nrf_read();
        // Affichage du nombre de tirs restant
        LED_OUT();
        switch (compteur_t) {
            case 1:
                LED_VERTE();
                break;
            case 2:
                LED_VERTE();
                LED_verte_1_SetHigh();
                break;
            case 3:
                LED_verte_4_SetLow();
                LED_verte_3_SetLow();
                LED_verte_2_SetLow();
                break;
            case 4:
                LED_verte_3_SetLow();
                LED_verte_2_SetLow();
                break;
            case 5:
                LED_verte_2_SetLow();
                break;
        }

        // RESET
        if (BTN_RESET_GetValue()) { //Bouton de reset du jeu apres 5 tirs
            reset();
        }
        if (compteur_t <= 5) { //Temps quon a pas fais 5 tirs le jeu continu
            //Niveau Facile
            if (data_read == 5) {
                LED_VERTE();
                compte_5();
                itoa_custom(texte_score, compte_pts);
                printing(point5F, texte_score);
            } else if (data_read == 1 || data_read == 17) {
                LED_ROUGE();
                itoa_custom(texte_score, compte_pts);
                printing(point0, texte_score);
            }//Niveau Moyen
            else if (data_read == 21) {
                LED_VERTE();
                compte_5();
                itoa_custom(texte_score, compte_pts);
                printing(point5M, texte_score);
            } else if (data_read == 19 || data_read == 33) {
                LED_ROUGE();
                compte_pts = compte_pts - 1;
                itoa_custom(texte_score, compte_pts);
                printing(point1, texte_score);
            }//Niveau Difficile
            else if (data_read == 37) {
                LED_VERTE();
                compte_5();
                itoa_custom(texte_score, compte_pts);
                printing(point5D, texte_score);   
            } else if (data_read == 35) {
                LED_ROUGE();
                compte_pts = compte_pts - 3;
                itoa_custom(texte_score, compte_pts);
                printing(point3D, texte_score); 
            }
            //En attente
        } else {
            printing(FinJ, texte_score);
        }
    }
}





/**
    End of File
 */