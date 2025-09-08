#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t band[])
{
	int power = 0;
	resistor_value_t res;
	res.value = band[0];
	if (band[1] != 0)
	{
		res.value *= 10;
		res.value += band[1];
	}
	if (band[1] == 0)
		band[2]++;
	if (band[2] < 3)
	{
		res.unit = OHMS;
		power = band[2];
	}
	if (band[2] < 6 && band[2] >= 3)
	{
		power = band[2] - 3;
		res.unit = KILOOHMS;
	}
	if (band[2] < 9 && band[2] >= 6)
	{
		power = band[2] - 6;
		res.unit = MEGAOHMS;
	}
	if (band[2] >= 9)
	{
		power = band[2] - 9;
		res.unit = GIGAOHMS;
	}
	while (power > 0)
	{
		res.value *= 10;
		power--;
	}
	return res;
}
