#include <stdint.h>
#include <ch554.h>
#include <debug.h>
#include "../../include/ch554.h"
#include "bitbang.h"
#include "display.h"

uint16_t wheel_pos;

__xdata uint8_t led_data[LED_COUNT * 3];

void displayImage(uint8_t num)
{
    uint16_t temp;
    uint8_t i, j, k;
    mDelaymS(50);
    for (i = 0; i < 64; i++)
    {
        temp = (text[num][i * 2 + 1] << 8) + text[num][i * 2];
        wheel_pos++;
        for (j = 0; j < 16; j++)
        {
            if (temp & 0x0001)
            {
                wheel(wheel_pos, 0x9f, led_data + ((16 - j) * 3 + 0)); //lower brightness.
            }
            else
            {
                wheel(wheel_pos, 0x00, led_data + ((16 - j) * 3 + 0)); //for same interval.
            }
            temp = temp >> 1;
        }
        bitbangWs2812(LED_COUNT, led_data);
        mDelayuS(100);
    }
    for (k = 0; k < 16; k++)
    {
        led_data[k * 3 + 0] = 0x00;
        led_data[k * 3 + 1] = 0x00;
        led_data[k * 3 + 2] = 0x00;
    }
    bitbangWs2812(LED_COUNT, led_data);
}

void wheel(uint16_t wheel_pos, uint8_t brightness, uint8_t *data)
{
    uint8_t index = (wheel_pos >> 8) & 0xff;
    uint8_t color = wheel_pos & brightness;
    switch (index % 3)
    {
    case 0:
        data[0] = color;
        data[1] = brightness - color;
        data[2] = 0;
        break;
    case 1:
        data[0] = brightness - color;
        data[1] = 0;
        data[2] = color;
        break;
    case 2:
        data[0] = 0;
        data[1] = color;
        data[2] = brightness - color;
        break;
    default:
        break;
    }
}

void pallette()
{
    uint8_t i;
    mDelaymS(200);
    for (i = 0; i < LED_COUNT; i++)
    {
        led_data[3 * i + 0] = 0x0f;
        led_data[3 * i + 1] = 0x00;
        led_data[3 * i + 2] = 0x00;
    }
    bitbangWs2812(LED_COUNT, led_data);
    mDelaymS(200);
    for (i = 0; i < LED_COUNT; i++)
    {
        led_data[3 * i + 0] = 0x00;
        led_data[3 * i + 1] = 0x0f;
        led_data[3 * i + 2] = 0x00;
    }
    bitbangWs2812(LED_COUNT, led_data);
    mDelaymS(200);
    for (i = 0; i < LED_COUNT; i++)
    {
        led_data[3 * i + 0] = 0x00;
        led_data[3 * i + 1] = 0x00;
        led_data[3 * i + 2] = 0x0f;
    }
    bitbangWs2812(LED_COUNT, led_data);
    mDelaymS(200);
    for (i = 0; i < LED_COUNT; i++)
    {
        led_data[3 * i + 0] = 0x00;
        led_data[3 * i + 1] = 0x00;
        led_data[3 * i + 2] = 0x00;
    }
    bitbangWs2812(LED_COUNT, led_data);
}
