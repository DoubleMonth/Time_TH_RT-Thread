/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-03-08     obito0   first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "si702x/si702x.h"
#include "pcf8563/pcf8563.h"
#include "tm1638/tm1638.h"
#include "bh1750/bh1750.h"

/* defined the LED0 pin: PC13 */
//#define LED0_PIN    GET_PIN(C, 13)
//#define SET_PIN 	GET_PIN(B, 5)
//#define ADD_PIN 	GET_PIN(B, 4)
//static void key_thread_entry(void *parameter)
//{
//	rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
//	rt_pin_mode(SET_PIN,PIN_MODE_INPUT_PULLUP);
//	rt_pin_mode(ADD_PIN,PIN_MODE_INPUT_PULLUP);
//	rt_thread_t tid;
//	tid = rt_thread_create("key",key_thread_entry,RT_NULL,1024,2,10);
//	if(tid != RT_NULL)
//		rt_thread_startup(tid);
////	while (1)
////	{
//		if(rt_pin_read(SET_PIN) == PIN_LOW)
//		{
//			rt_kprintf("SET key pressed!\n");
//			
//		}
//		while(rt_pin_read(SET_PIN) == PIN_LOW) ;
//		if(rt_pin_read(ADD_PIN) == PIN_LOW)
//		{
//			rt_kprintf("ADD key pressed!\n");
//			
//		}
//		while(rt_pin_read(ADD_PIN) == PIN_LOW);
////	}
//		if(NULL == rt_i2c_bus_device_find("i2c3"))
//		{
//			rt_kprintf("no find i2c3!\n");
//		}
//		else
//		{
//			rt_kprintf("find i2c3 !\n");
//		}
//	
//	
//	
//}
rt_uint8_t displayNumber[10]={1,2,3,4,5,6,7,8,9,0};
int main(void)
{
//    int count = 1;
	
	si702x_init();
	pcf8563_init();
	pcf8563_start();
	bh1750_init();
	tm1638Init();
	while(1)
	{
		display(displayNumber,1,0,0);
		rt_thread_mdelay(10);
	}
	
//	while(1)
//	{
//		si702x_read_temp_humi();
//		pcf8563_read_time();
//		pcf8563_read_day();
//		bh1750_read_illuminace();
//		rt_thread_mdelay(1000);
//	}
	
    return RT_EOK;
}
//MSH_CMD_EXPORT(key_thread_entry,RT-Thread first  key sample);
