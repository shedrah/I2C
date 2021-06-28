#include <project.h>

    #define WHO_AM_I        (0b00001111)

    #define ACCEL_ADDR      (0b01101011) // adres akcelerometru i gyroskopu ze strony https://botland.store/9dof-imu-sensors/5528-minimu-9-v5-9dof-accelerometer-gyroscope-and-magnetometer-i2c-pololu-2738.html
    #define CTRL_REG1       (0b00010000) // CTRL1_XL    
    
    #define GYRO_ADDR       (0b01101011) // adres akcelerometru i gyroskopu
    #define CTRL_REG2       (0b00010001) // wlaczenie gyroskopu CTRL2_G z noty
    

    #define OUT_X_LSB       (0b00101000) //akcelerometr
    #define OUT_X_MSB       (0b00101001)
    #define OUT_Y_LSB       (0b00101010)
    #define OUT_Y_MSB       (0b00101011)
    #define OUT_Z_LSB       (0b00101100)
    #define OUT_Z_MSB       (0b00101101)
    
    #define GOUT_X_LSB       (0b00100010) //gyroskop
    #define GOUT_X_MSB       (0b00100011)
    #define GOUT_Y_LSB       (0b00100100)
    #define GOUT_Y_MSB       (0b00100101)
    #define GOUT_Z_LSB       (0b00100110)
    #define GOUT_Z_MSB       (0b00100111)
    
    uint8 accel2_ReadReg(uint8 Reg); 
    uint8 accel2_WriteReg(uint8 Reg, uint8 value);
