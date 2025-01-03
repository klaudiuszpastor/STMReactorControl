#include "hagl_hal.h"
#include "hagl.h"

void hagl_hal_put_pixel(void *self, int16_t x0, int16_t y0, hagl_color_t color) {
    lcd_put_pixel(x0, y0, (uint16_t)color); // Cast if needed for compatibility
}

void hagl_hal_init(hagl_surface_t *surface) {
    surface->width = DISPLAY_WIDTH;
    surface->height = DISPLAY_HEIGHT;
    surface->depth = DISPLAY_DEPTH;

    surface->clip.x0 = 0;
    surface->clip.y0 = 0;
    surface->clip.x1 = DISPLAY_WIDTH - 1;
    surface->clip.y1 = DISPLAY_HEIGHT - 1;

    surface->put_pixel = hagl_hal_put_pixel;
    surface->get_pixel = NULL;
    surface->color = NULL;
    surface->blit = NULL;
    surface->scale_blit = NULL;
    surface->hline = NULL;
    surface->vline = NULL;
}

void scaled_put_text(hagl_surface_t *surface, const wchar_t *text, int x, int y, hagl_color_t color, const unsigned char *font, int scale) {
    hagl_bitmap_t glyph;
    int cursor_x = x;

    while (*text) {
        if (hagl_get_glyph(surface, *text, color, &glyph, font) == 0) {
            for (int gy = 0; gy < glyph.height; gy++) {
                for (int gx = 0; gx < glyph.width; gx++) {
                    hagl_color_t pixel_color = ((hagl_color_t *)glyph.buffer)[gy * glyph.width + gx];
                    if (pixel_color != 0x0000) { // Skip transparent pixels
                        hagl_fill_rectangle(surface,
                                            cursor_x + gx * scale,
                                            y + gy * scale,
                                            cursor_x + (gx + 1) * scale - 1,
                                            y + (gy + 1) * scale - 1,
                                            pixel_color);
                    }
                }
            }
            cursor_x += glyph.width * scale;
        }
        text++;
    }
}

