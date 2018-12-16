#pragma once

#define LED_COUNT (16)

extern __code uint8_t text[][128];

void pallette(void);
void displayImage(uint8_t num);
void wheel(uint16_t wheel_pos, uint8_t brightness, uint8_t *data);
