#pragma once

// Configuration for SMENETE board

#define RETARGET_I2C_DEV         I2C0
#define RETARGET_I2C_CLOCK       cmuClock_I2C0

#define RETARGET_I2C_SDA_PORT    gpioPortD
#define RETARGET_I2C_SDA_PIN     11
#define RETARGET_I2C_SCL_PORT    gpioPortD
#define RETARGET_I2C_SCL_PIN     10

#define RETARGET_I2C_SDA_LOC     I2C_ROUTELOC0_SDALOC_LOC19
#define RETARGET_I2C_SCL_LOC     I2C_ROUTELOC0_SCLLOC_LOC17
