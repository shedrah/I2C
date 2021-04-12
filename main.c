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
#include <i2c.c>
int main()
{
   

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    I2C_1_Start();
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //test
    uint8 deviceID;
    uint8 CtrlReg1_beforeWrite;
    uint8 CtrlReg1_afterWrite;
    uint8 x_MSB, x_LSB, y_MSB, y_LSB, z_MSB, z_LSB;
    
    
    CtrlReg1_beforeWrite=accel_ReadReg(CTRL_REG1);
    
    accel_WriteReg(CTRL_REG1,00010000);
    
    CtrlReg1_afterWrite=accel_ReadReg(CTRL_REG1);
    
    // koniec testu
    for(;;)
    {
        deviceID=accel_ReadReg(WHO_AM_I);
        
        x_MSB=accel_ReadReg(OUT_X_MSB);
        x_LSB=accel_ReadReg(OUT_X_LSB);
        
        y_MSB=accel_ReadReg(OUT_Y_MSB);
        y_LSB=accel_ReadReg(OUT_Y_LSB);
        
        z_MSB=accel_ReadReg(OUT_Z_MSB);
        z_LSB=accel_ReadReg(OUT_Z_LSB);
    }
}

/* [] END OF FILE */
