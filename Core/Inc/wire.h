#ifndef INC_WIRE_H_
#define INC_WIRE_H_

#include "stm32l4xx.h"

HAL_StatusTypeDef wire_init(void);
HAL_StatusTypeDef wire_reset(void);
uint8_t wire_read(void);
void wire_write(uint8_t byte);
uint8_t wire_crc(const uint8_t* data, int len);


#endif /* INC_WIRE_H_ */
