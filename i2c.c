#include <i2c.h>
 #include <project.h>   
 #include <stdio.h>
   
 uint8 accel2_ReadReg(uint8 Reg)
{ 
        uint8 Write_Buf[1]={0};  
        Write_Buf[0]=Reg; //zapisanie rejestru, z którego odczytujemy dane
        uint8 Read_Buf[1]={0};  //Bufor do trzymania wartości z adresu wyżej
       
        //MasterReadBuf do trzymania wartości dla buforu 'read'
        I2C_1_MasterWriteBuf(ACCEL_ADDR, (uint8 *)Write_Buf, 1 , I2C_1_MODE_NO_STOP);
        while((I2C_1_MasterStatus() & I2C_1_MSTAT_WR_CMPLT)==0){}
        
        I2C_1_MasterReadBuf(ACCEL_ADDR, (uint8 *)Read_Buf,1 ,I2C_1_MODE_REPEAT_START);
        while((I2C_1_MasterStatus() & I2C_1_MSTAT_RD_CMPLT)==0)
        {}
        return Read_Buf[0];
}

 uint8 accel2_WriteReg(uint8 Reg, uint8 value)
{
    uint8 Write_Buf[2]={0};
    Write_Buf[0]=Reg;
    Write_Buf[1]=value;
    
    uint8 ret = I2C_1_MasterWriteBuf(ACCEL_ADDR, (uint8 *)Write_Buf,2 ,I2C_1_MODE_COMPLETE_XFER);
    while((I2C_1_MasterStatus()&I2C_1_MSTAT_WR_CMPLT)==0)
    {}
    return I2C_1_MasterStatus();
}
