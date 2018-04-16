/*
 * bsp.c
 *
 *  Created on: 2018年4月14日
 *      Author: o2
 */
#include "includes.h"

void BSP_Config()
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	GPIO_Config();
}

