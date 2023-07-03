#pragma once

#define VL6180x_SINGLE_DEVICE_DRIVER

bool vl6180x_init();
bool vl6180x_read(uint16_t *pRangeMilliMeter);
