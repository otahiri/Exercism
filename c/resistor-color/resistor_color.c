#include "resistor_color.h"


resistor_band_t *colors()
{
	static resistor_band_t color[] = {
        BLACK,
        BROWN,
        RED,
        ORANGE,
        YELLOW,
        GREEN,
        BLUE,
        VIOLET,
        GREY,
        WHITE
	};
	return color;
}
	

resistor_band_t color_code(resistor_band_t color)
{
	return color;
}
