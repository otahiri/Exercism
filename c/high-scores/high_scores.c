#include "high_scores.h"

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
	output[0] = 0;
	output[1] = 0;
	output[2] = 0;
	size_t idx1;
	size_t idx2;
	int size;
	for (size_t i = 0; i < scores_len; i++)
	{
		if (scores[i] > output[0])
		{
			output[0] = scores[i];
			size = 1;
			idx1 = i;
		}
	}
	for (size_t i = 0; i < scores_len; i++)
	{
		if (scores[i] > output[1] && idx1 != i)
		{
			output[1] = scores[i];
			size = 2;
			idx2 = i;
		}
	}
	for (size_t i = 0; i < scores_len; i++)
	{
		if (scores[i] > output[2]  && idx1 != i && idx2 != i)
		{
			output[2] = scores[i];
			size = 3;
		}
	}
	return size;
}

int32_t personal_best(const int32_t *scores, size_t scores_len)
{
	int32_t res = 0;
	for (size_t i = 0; i < scores_len; i++)
	{
		if (scores[i] > res)
			res = scores[i];
	}
	return res;
}

int32_t latest(const int32_t *scores, size_t scores_len)
{
	return scores[scores_len - 1];
}
