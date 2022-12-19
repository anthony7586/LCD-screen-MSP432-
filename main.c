
                             //main.c



/*
 * Engineer: Anthony Ruiz
 * anthony.ruiz.2727@gmail.com
 * California State University, Fullerton
 */

 /////////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////


#include <stdint.h>
#include "SysTickInts.h"
#include "LCD.h"
#include "msp432p401r.h"


uint32_t ADCFix(uint32_t temp);




void main() {

    P1SEL0 &= ~0x01;
    P1SEL1 &= ~0x01;
    P1DIR |= 0x01;

   ADC0_InitSWTriggerCh0();
    LCD_Init();



    LCD_OutChar(0x45);//E
    LCD_OutChar(0x47);//G
    LCD_OutChar(0x43);//C
    LCD_OutChar(0x50);//P
    LCD_OutChar(0x2D);//-
    LCD_OutUDec(450);//450
    LCD_OutChar(0x20);//SPACE
    LCD_OutChar(0x4C);//L
    LCD_OutChar(0x41);//A
    LCD_OutChar(0x42);//B
    LCD_OutChar(0x20);//space

    LCD_OutUDec(6);     //6
    LCD_OutChar(0x2E);  //.
    LCD_OutChar(0x32);   //2

    // Display value
    LCD_OutCmd(0xC0);// Move cursor to the 2nd line

    // Display value

 SysTick_Init(30000);
 while (1){
             uint32_t info = SysTick_Mailbox();
             uint32_t temp = ADCFix(info);
            LCD_OutUFix(temp);//output
            LCD_OutString(" cm"); // display units " cm"
            LCD_OutCmd(0xC0);//second line
            P1OUT ^= 0x01; //XOR LED

            }//end while





}//end main

    uint32_t ADCFix(uint32_t temp) {
        uint32_t n;
        float num = 8.3;
        n = temp/num;
        return n;
        }


