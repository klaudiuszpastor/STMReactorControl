#ifndef INC_HAGL_HAL_H_
#define INC_HAGL_HAL_H_

#include "lcd.h"
#include "hagl/surface.h"
#include "hagl/color.h"
#include <stddef.h>
#include "hagl/bitmap.h"
#include "hagl/char.h"
#include "hagl/line.h"

#define DISPLAY_WIDTH   (LCD_WIDTH)
#define DISPLAY_HEIGHT  (LCD_HEIGHT)
#define DISPLAY_DEPTH   16

void hagl_hal_put_pixel(void *self, int16_t x0, int16_t y0, hagl_color_t color);
void hagl_hal_init(hagl_surface_t *surface);
void scaled_put_text(hagl_surface_t *surface, const wchar_t *text, int x, int y, hagl_color_t color, const unsigned char *font, int scale);

#endif /* INC_HAGL_HAL_H_ */
