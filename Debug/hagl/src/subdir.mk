################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hagl/src/fontx.c \
../hagl/src/hagl.c \
../hagl/src/hagl_bitmap.c \
../hagl/src/hagl_blit.c \
../hagl/src/hagl_char.c \
../hagl/src/hagl_circle.c \
../hagl/src/hagl_clip.c \
../hagl/src/hagl_color.c \
../hagl/src/hagl_ellipse.c \
../hagl/src/hagl_hline.c \
../hagl/src/hagl_image.c \
../hagl/src/hagl_line.c \
../hagl/src/hagl_pixel.c \
../hagl/src/hagl_polygon.c \
../hagl/src/hagl_rectangle.c \
../hagl/src/hagl_triangle.c \
../hagl/src/hagl_vline.c \
../hagl/src/hsl.c \
../hagl/src/rgb565.c \
../hagl/src/rgb888.c \
../hagl/src/tjpgd.c 

OBJS += \
./hagl/src/fontx.o \
./hagl/src/hagl.o \
./hagl/src/hagl_bitmap.o \
./hagl/src/hagl_blit.o \
./hagl/src/hagl_char.o \
./hagl/src/hagl_circle.o \
./hagl/src/hagl_clip.o \
./hagl/src/hagl_color.o \
./hagl/src/hagl_ellipse.o \
./hagl/src/hagl_hline.o \
./hagl/src/hagl_image.o \
./hagl/src/hagl_line.o \
./hagl/src/hagl_pixel.o \
./hagl/src/hagl_polygon.o \
./hagl/src/hagl_rectangle.o \
./hagl/src/hagl_triangle.o \
./hagl/src/hagl_vline.o \
./hagl/src/hsl.o \
./hagl/src/rgb565.o \
./hagl/src/rgb888.o \
./hagl/src/tjpgd.o 

C_DEPS += \
./hagl/src/fontx.d \
./hagl/src/hagl.d \
./hagl/src/hagl_bitmap.d \
./hagl/src/hagl_blit.d \
./hagl/src/hagl_char.d \
./hagl/src/hagl_circle.d \
./hagl/src/hagl_clip.d \
./hagl/src/hagl_color.d \
./hagl/src/hagl_ellipse.d \
./hagl/src/hagl_hline.d \
./hagl/src/hagl_image.d \
./hagl/src/hagl_line.d \
./hagl/src/hagl_pixel.d \
./hagl/src/hagl_polygon.d \
./hagl/src/hagl_rectangle.d \
./hagl/src/hagl_triangle.d \
./hagl/src/hagl_vline.d \
./hagl/src/hsl.d \
./hagl/src/rgb565.d \
./hagl/src/rgb888.d \
./hagl/src/tjpgd.d 


# Each subdirectory must supply rules for building sources it contributes
hagl/src/%.o hagl/src/%.su hagl/src/%.cyclo: ../hagl/src/%.c hagl/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"C:/Users/User/STM32CubeIDE/workspace_1.17.0/1/hagl/include" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-hagl-2f-src

clean-hagl-2f-src:
	-$(RM) ./hagl/src/fontx.cyclo ./hagl/src/fontx.d ./hagl/src/fontx.o ./hagl/src/fontx.su ./hagl/src/hagl.cyclo ./hagl/src/hagl.d ./hagl/src/hagl.o ./hagl/src/hagl.su ./hagl/src/hagl_bitmap.cyclo ./hagl/src/hagl_bitmap.d ./hagl/src/hagl_bitmap.o ./hagl/src/hagl_bitmap.su ./hagl/src/hagl_blit.cyclo ./hagl/src/hagl_blit.d ./hagl/src/hagl_blit.o ./hagl/src/hagl_blit.su ./hagl/src/hagl_char.cyclo ./hagl/src/hagl_char.d ./hagl/src/hagl_char.o ./hagl/src/hagl_char.su ./hagl/src/hagl_circle.cyclo ./hagl/src/hagl_circle.d ./hagl/src/hagl_circle.o ./hagl/src/hagl_circle.su ./hagl/src/hagl_clip.cyclo ./hagl/src/hagl_clip.d ./hagl/src/hagl_clip.o ./hagl/src/hagl_clip.su ./hagl/src/hagl_color.cyclo ./hagl/src/hagl_color.d ./hagl/src/hagl_color.o ./hagl/src/hagl_color.su ./hagl/src/hagl_ellipse.cyclo ./hagl/src/hagl_ellipse.d ./hagl/src/hagl_ellipse.o ./hagl/src/hagl_ellipse.su ./hagl/src/hagl_hline.cyclo ./hagl/src/hagl_hline.d ./hagl/src/hagl_hline.o ./hagl/src/hagl_hline.su ./hagl/src/hagl_image.cyclo ./hagl/src/hagl_image.d ./hagl/src/hagl_image.o ./hagl/src/hagl_image.su ./hagl/src/hagl_line.cyclo ./hagl/src/hagl_line.d ./hagl/src/hagl_line.o ./hagl/src/hagl_line.su ./hagl/src/hagl_pixel.cyclo ./hagl/src/hagl_pixel.d ./hagl/src/hagl_pixel.o ./hagl/src/hagl_pixel.su ./hagl/src/hagl_polygon.cyclo ./hagl/src/hagl_polygon.d ./hagl/src/hagl_polygon.o ./hagl/src/hagl_polygon.su ./hagl/src/hagl_rectangle.cyclo ./hagl/src/hagl_rectangle.d ./hagl/src/hagl_rectangle.o ./hagl/src/hagl_rectangle.su ./hagl/src/hagl_triangle.cyclo ./hagl/src/hagl_triangle.d ./hagl/src/hagl_triangle.o ./hagl/src/hagl_triangle.su ./hagl/src/hagl_vline.cyclo ./hagl/src/hagl_vline.d ./hagl/src/hagl_vline.o ./hagl/src/hagl_vline.su ./hagl/src/hsl.cyclo ./hagl/src/hsl.d ./hagl/src/hsl.o ./hagl/src/hsl.su ./hagl/src/rgb565.cyclo ./hagl/src/rgb565.d ./hagl/src/rgb565.o ./hagl/src/rgb565.su ./hagl/src/rgb888.cyclo ./hagl/src/rgb888.d ./hagl/src/rgb888.o ./hagl/src/rgb888.su ./hagl/src/tjpgd.cyclo ./hagl/src/tjpgd.d ./hagl/src/tjpgd.o ./hagl/src/tjpgd.su

.PHONY: clean-hagl-2f-src

