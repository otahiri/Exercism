#include "allergies.h"
bool is_allergic_to(allergen_t which, int allergy)
{
	int inp = 1 << which;
	if (allergy & inp)
		return true;
	return false;	
}	
allergen_list_t get_allergens(int allergy)
{
	allergen_list_t aller;
	aller.count = 0;
	for (int i = 0; i < 8; i++)
	{
		if (allergy & (1 << i))
		{	
			aller.count++;
			aller.allergens[i] = true;
		}
		else
			aller.allergens[i] = false;
	}	
	return aller;
}
