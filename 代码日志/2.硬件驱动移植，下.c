//按键控制电机测试

/*timer	和按键测试*/


//int8_t  PWML,PWMR;

//uint8_t Num;


//int main(void)
//{	OLED_Init();
//	Key_Init();
//	Timer_Init();
//	Motor_Init();
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
//			PWML+=1;
//		}
//		if(Num==2)
//		{
//			PWML+=2;
//		}if(Num==3)
//		{
//			PWMR-=1;
//		}if(Num==4)
//		{
//			PWMR-=2;
//		}
//		
//		Motor_SetPWM(1,PWML);
//		Motor_SetPWM(2,PWMR);

//		OLED_Printf(0, 0, OLED_6X8, "PWML:%+04d", PWML);//%+04d,int8_t的占位符
//		OLED_Printf(0, 16, OLED_6X8, "PWMR:%+04d", PWMR );
//	
//        OLED_Update();
//       
//    }
//}
//void TIM1_UP_IRQHandler (void)   
//{
//	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
//	{
//		Key_Tick();//定时调用
//		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);//清楚标志位
//		
//	}
//}


//按键控制电机+encoder测试




//int8_t  PWML,PWMR;
//float  SpeedL,SpeedR;
//uint8_t Num;


//int main(void)
//{	OLED_Init();
//	Key_Init();
//	Timer_Init();
//	Motor_Init();
//	Encoder_Init();
//    while (1)
//    {
//        
//		
//		Num=Key_GetNum();
//		
//		if(Num==1)//如果==,
//			//=是赋值，Num=1，永远为真
//		{
//			PWML+=1;
//		}
//		if(Num==2)
//		{
//			PWML+=2;
//		}if(Num==3)
//		{
//			PWMR-=1;
//		}if(Num==4)
//		{
//			PWMR-=2;
//		}
//		
//		Motor_SetPWM(1,PWML);
//		Motor_SetPWM(2,PWMR);
//		
//		OLED_Printf(0, 0, OLED_6X8, "PWML:%+04d", PWML);//%+04d,int8_t的占位符
//		OLED_Printf(0, 16, OLED_6X8, "PWMR:%+04d", PWMR );
//	 	OLED_Printf(0, 24, OLED_6X8, "spd:%+06.2f", SpeedL );
//		OLED_Printf(0, 32, OLED_6X8, "spd:%+06.2f", SpeedR  );


//        OLED_Update();
//       
//    }
//}


//uint8_t count;

//void TIM1_UP_IRQHandler (void)   
//{
//	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
//	{	
//		
//		count ++;
//		if(count>50)
//		{
//			SpeedL=Encoder_Get(1)/44.0/ 0.05 / 9.27666;
//			SpeedR=Encoder_Get(2)/44.0/ 0.05 / 9.27666;

//		}
//		Key_Tick();//定时调用
//		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);//清楚标志位
//		
//	}
//}




//串口测试

int main (void)
{	
	
	
	
//
	OLED_Init();
	Serial_Init();
	BlueSerial_Init();
	
//		Timer_Init();
	
	Serial_SendString("日常文 ");
	printf ("男主");
	Serial_Printf("World");
	
    BlueSerial_SendString("hello");
	BlueSerial_Printf("world");

	while(1)
	{
		if(Serial_GetRxFlag()==1)
		{
			uint8_t sendstring=Serial_GetRxData();//接收一个字节
			OLED_Printf(0, 0, OLED_6X8, "send:%02X", sendstring  );
			OLED_Update();
		}
		
		if(BlueSerial_RxFlag==1)
		{
			OLED_Printf(0, 16, OLED_8X16, "%s", BlueSerial_RxPacket);		
			OLED_Update();
			BlueSerial_RxFlag=0;
		}
		
	}
}


//if (BlueSerial_RxFlag == 1)
//OLED_Printf (0, 16, OLED_8Xl6, "%s", BlueSerial_RxPacket) ;OLED_Update() ;
//Blueserial_RxFlag = 0;              Blueserial_RxFlag = 0;
//为什么不放到前面，实现处理第一个数据包时，防止处理另一个，造成混淆？
//先清0标志位，下一个数据过来，标志位重新设置为1，重新进入中断，打断对数据包的处理。
//后面清0，只有当写入又一个数据，才会进入总断。

//BlueSerial_RxPacket 这个变量为什么能存储数据？
//这个是全局数组，在蓝牙.h里定义，不断被写入数据




