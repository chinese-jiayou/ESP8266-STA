#include "stm32f10x.h"
#include "usart.h"
#include "delay.h"
#include "esp8266.h"



uint8_t flag;

 int main ( void )
{
	/* ��ʼ�� */
  USART_Config(); 	//��ʼ������1                      
	ESP8266_Init ();   //��ʼ��WiFiģ��ʹ�õĽӿں����裨ʹ�ô���2��
  ESP8266_StaTcpClient_UnvarnishTest ();//WiFiģ������
	
	
	//LED��������  GPIOA pin0��
	GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA , ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
		

  while ( 1 )
	{ 
switch(flag)
{
	case 'a': GPIO_SetBits(GPIOA,GPIO_Pin_0 );break;//����
	
	case 'c': GPIO_ResetBits(GPIOA,GPIO_Pin_0 );break;//�ص�
}	
	
	}

}


