
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"

#include "driver/i2c.h"

#include "vl6180x_api.h"
#include "vl6180x_def.h"
#include "vl6180x_platform.h"

#include "esp_log.h"

#define TAG "VL6180X"

static const uint8_t VL6180x_I2C_ADDRESS_DEFAULT = 0x29;


struct MyDev_t device;
VL6180xDev_t dev;
int32_t TimingBudgetMicroSeconds;

bool vl6180x_init()
{

    dev = &device;

    /* device init */
    dev->i2c_port_num = 0;
    dev->i2c_address = VL6180x_I2C_ADDRESS_DEFAULT;
    
    if (VL6180x_InitData(dev) < 0) {
      ESP_LOGE(TAG, "failed VL6180x_InitData");
      return false;
    }
    if (VL6180x_Prepare(dev) < 0) {
      ESP_LOGE(TAG, "failed VL6180x_Prepare");
      return false;
    }
    return true;
}

bool vl6180x_read(uint16_t *pRangeMilliMeter)
{
    VL6180x_RangeData_t Range;
    int status = VL6180x_RangePollMeasurement(dev, &Range);
    if (status != 0 || Range.errorStatus != 0) {
        //ESP_LOGW(TAG, "i2c status: %d, range status: %s", status,
        //        VL6180x_RangeGetStatusErrString(Range.errorStatus));
        return false;
    }
    *pRangeMilliMeter = Range.range_mm;
    return true;
}


#undef TAG
