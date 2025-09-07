#include "dnd_character.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

int ability(void)
{
	srand(time(NULL));
	return rand()% 15 + 3;
}
int modifier(int score)
{
	return  floor((score - 10) / 2.0);
}
dnd_character_t make_dnd_character(void)
{
	dnd_character_t chara;
	chara.strength = ability();
	chara.dexterity = ability();
	chara.constitution = ability();
	chara.intelligence = ability();
	chara.wisdom = ability();
	chara.charisma = ability();
	chara.hitpoints = modifier(chara.constitution) + 10;
	return chara;
}
