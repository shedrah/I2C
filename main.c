#include <i2c.h>
#include <FS.h>
#include <stdio.h>

const char *sdFile = "Dane/File.txt";
char buf[128];
/*
uint8 usbRX(uint8 *buf2)
{
    uint8 count=0;
    if(USBUART_1_DataIsReady()!=0){
        count=USBUART_1_GetAll(buf2);
        if(count!=0){
            while(USBUART_1_CDCIsReady()==0);
            USBUART_1_PutData(buf2,count);
        }
    }
    return count;
}
*/
int main()
{
    CyGlobalIntEnable;
    I2C_1_Start();
    //UART_1_Start();
    USBUART_1_Start(USBUART_1_CLASS_DEVICE,USBUART_1_5V_OPERATION);
    
    while(!USBUART_1_GetConfiguration());
    USBUART_1_CDC_Init();
    
    accel2_WriteReg(CTRL_REG1, 0b00010000);
    
    accel2_WriteReg(CTRL_REG2, 0b00010000);
    
    uint8 x_MSB, x_LSB, y_MSB, y_LSB, z_MSB, z_LSB, g_x_MSB, g_x_LSB, g_y_MSB, g_y_LSB, g_z_MSB, g_z_LSB;
    
    //uint8 usbRxBufer[1024];
    //uint8 usbTxBufer[1024];
     
    int16_t valX;
    int16_t valY;
    int16_t valZ;
        
    int16_t g_valX;
    int16_t g_valY;
    int16_t g_valZ; 
        
     
    char sdVolName[10];     
    FS_FILE * pFile;
    if(!USBUART_1_GetConfiguration())
    {
    int SD_name=FS_GetVolumeName(0u, &sdVolName[0], 9u);
    FS_Init();
    char plik;
    FS_MkDir ("Dane");
    pFile = FS_FOpen(sdFile, "a");
    }
    
    
    for(;;)
    {
        x_MSB=accel2_ReadReg(OUT_X_MSB);
        x_LSB=accel2_ReadReg(OUT_X_LSB);
        
        y_MSB=accel2_ReadReg(OUT_Y_MSB);
        y_LSB=accel2_ReadReg(OUT_Y_LSB);
        
        z_MSB=accel2_ReadReg(OUT_Z_MSB);
        z_LSB=accel2_ReadReg(OUT_Z_LSB);
        
        g_x_MSB=accel2_ReadReg(GOUT_X_MSB);
        g_x_LSB=accel2_ReadReg(GOUT_X_LSB);
        
        g_y_MSB=accel2_ReadReg(GOUT_Y_MSB);
        g_y_LSB=accel2_ReadReg(GOUT_Y_LSB);
        
        g_z_MSB=accel2_ReadReg(GOUT_Z_MSB);
        g_z_LSB=accel2_ReadReg(GOUT_Z_LSB);
        
       
        valX = (x_MSB << 8) | x_LSB;
        valY = (y_MSB << 8) | y_LSB;
        valZ = (z_MSB << 8) | z_LSB;
         
        g_valX = (g_x_MSB << 8) | g_x_LSB;
        g_valY = (g_y_MSB << 8) | g_y_LSB;
        g_valZ = (g_z_MSB << 8) | g_z_LSB;
        
        sprintf(buf, "%+d, %+d, %+d, %+d, %+d, %+d\n", valX, valY, valZ,g_valX, g_valY, g_valZ);
        CyDelay(100);
        USBUART_1_PutString(buf);
       
   
        /*
        if(pFile)
        {
         FS_Write(pFile, "X: " + valX, 10u);
         FS_Write(pFile, "Y: " + valY, 10u);
         FS_Write(pFile, "Z: " + valZ, 10u);
    
         FS_Write(pFile, "g_X: " + g_valX, 10u);
         FS_Write(pFile, "g_Y: " + g_valY, 10u);  
         FS_Write(pFile, "g_Z: " + g_valZ, 10u);
        }
            */
        
        
        CyDelay(100);
    } 
    
    
    /*
    FS_FClose(pFile);
    FS_CopyFile(sdFile, "\\Dane\\acce2.txt");
    for(;;)
    {
    }
    */
}
