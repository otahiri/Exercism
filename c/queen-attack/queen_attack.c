#include "queen_attack.h"
#include <stdlib.h>

attack_status_t can_attack(position_t qw, position_t qb)
{
	if (qw.row == qb.row && qw.column == qb.column)
		return INVALID_POSITION;
	if (qw.row > 7 || qw.column > 7 || qb.row > 7 || qb.column > 7)
		return INVALID_POSITION;
	if (qw.row == qb.row || qw.column == qb.column)
		return CAN_ATTACK;
	if (abs( qw.row - qb.row) == abs(qw.column - qb.column))
		return CAN_ATTACK;
	return CAN_NOT_ATTACK;
}
