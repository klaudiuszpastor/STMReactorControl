/*
 * interrupt.h
 *
 *  Created on: Dec 14, 2024
 *      Author: User
 */

#ifndef INC_INTERRUPT_H_
#define INC_INTERRUPT_H_

#include "stm32l4xx.h"

uint32_t enter_critical_section(uint32_t priority);
void exit_critical_section(uint32_t old_basepri);

#endif /* INC_INTERRUPT_H_ */
