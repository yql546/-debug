#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include "TIMER.h"
#include "KEY.h"
/*oled和led测试*/
//int main(void)
//{
//	OLED_Init();
//	LED_Init();
//	OLED_Printf(0, 0, OLED_8X16,"Hello World!");
//	OLED_Printf(0, 16, OLED_6X8, "Hello World!");
//	OLED_Update() ;
//	
//	while (1)
//	{
//		LED_ON();
//		Delay_ms(500);
//		LED_OFF();
//		Delay_ms(500);
//	
//	}
//}

/*timer	和按键测试*/


//uint16_t  count;

//uint8_t Num,Num2;

//int main(void)
//{	OLED_Init();
//	Key_Init();
//	Timer_Init();
//	
//	
//    while (1)
//    {
//        
//		
//		Num=Key_GetNum();
//		
//		if(Num==1)//如果==,
//			//=是赋值，Num=1，永远为真
//		{
//			Num2+=1;
//		}
//		if(Num==2)
//		{
//			Num2+=2;
//		}if(Num==3)
//		{
//			Num2-=1;
//		}if(Num==4)
//		{
//			Num2-=2;
//		}
//		
//		
//		OLED_Printf(0, 0, OLED_6X8, "count:%05d", count);//%o5d,uint16_t的占位符
//		OLED_Printf(0, 16, OLED_6X8, "Num2:%03d", Num2);
//	
//        OLED_Update();
//       
//    }
//}



//void TIM1_UP_IRQHandler (void)   
//{
//	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
//	{
//		count ++;
//		Key_Tick();//定时调用
//		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);//清楚标志位
//		
//	}
//}



/*mpu6050测试*/
int16_t AX,AY,AZ,GX,GY,GZ;

int main (void)
	
{
	OLED_Init();
	MPU6050_Init();
	Timer_Init();
	
				//int16_t的占位符
	    
	
	
	
	while(1)
	{	
		OLED_Printf(0, 0, OLED_8X16, "%+06d", AX);
		OLED_Printf(0, 16, OLED_8X16, "%+06d", AY);
		OLED_Printf(0, 32, OLED_8X16, "%+06d", AZ);
	    OLED_Printf(64, 0, OLED_8X16, "%+06d", GX);
		OLED_Printf(64, 16, OLED_8X16, "%+06d", GY);
		OLED_Printf(64, 32, OLED_8X16, "%+06d", GZ);
		 OLED_Update();
		
	}
	
}



void TIM1_UP_IRQHandler (void)   
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{	
		MPU6050_GetData(&AX,&AY,&AZ,&GX,&GY,&GZ);
		
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);//清楚标志位
		
	}
}