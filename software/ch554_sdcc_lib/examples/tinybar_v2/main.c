// Tinybar V2
// Duan

#include <stdint.h>
#include <ch554.h>
#include <debug.h>
#include <bootloader.h>
#include "bitbang.h"
#include "display.h"

#define BTN_PIN 4
SBIT(BTN, 0x90, BTN_PIN);

#define SSW_PIN 2
SBIT(SSW, 0xB0, SSW_PIN);

void main()
{
    uint8_t text_num = 0;
    CfgFsys();
    mDelaymS(50);
    if (BTN == 0)
    {
        mDelaymS(50);
        if (BTN == 0)
        {
            EA = 0;
            mDelaymS(100);
            bootloader();
            while (1)
                ;
        }
    }

    bitbangSetup();
    pallette();

    while (1)
    {
        if (SSW == 0)
        {
            displayImage(text_num);
        }
        if (BTN == 0)
        {
            mDelaymS(50);
            if (BTN == 0)
            {
                text_num++;
                text_num %= 5;
            }
            while (BTN == 0)
                ;
        }
    }
}
