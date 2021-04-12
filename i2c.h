/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

    #define ACCEL_ADDR      (00110101)
    #define WHO_AM_I        (00001111)
    #define CTRL_REG1       (00010000) //ctrl8_xl dla wlaczenia akcelerometru np.: 00010000
    
    #define OUT_X_LSB       (00101000) //akcelerometr
    #define OUT_X_MSB       (00101001)
    #define OUT_Y_LSB       (00101010)
    #define OUT_Y_MSB       (00101011)
    #define OUT_Z_LSB       (00101100)
    #define OUT_Z_MSB       (00101101)
    
    
    
    uint8 accel_ReadReg(uint8 Reg);
    void accel_WriteReg(uint8 Reg, uint8 value);
/* [] END OF FILE */
