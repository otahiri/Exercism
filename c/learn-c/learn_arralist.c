#include <stdlib.h>
#include <stdio.h>

typedef struct{
	int *data;
	int size;
	int cap;
}list;

list *create_list(int cap)
{
	list *alist = malloc(sizeof(list));
	alist->size = 0;
	alist->cap = cap;
	alist->data = malloc(sizeof(int) * cap);
	return alist;
}


void ft_memcpy(int *srcs, int *dest, size_t size)
{
	int i = 0;
	while (i < size)
	{
		dest[i] = srcs[i];
		i++;
	}
}

void add_element(int num, list *alist)
{
	if (alist->size == alist->cap)
	{
		alist->cap *= 2;
		int *new_arr = malloc(sizeof(int) * alist->cap);
		ft_memcpy(alist->data, new_arr, alist->size);
		free(alist->data);
		alist->data = new_arr;
	}
	alist->data[alist->size] = num;
	alist->size++;
}

void remove_element(int idx, list *alist)
{
	int i = 0;
	int j = 0;
	int *new_list = malloc(sizeof(int) * (alist->size - 1));
	while (i < alist->size && j < alist->size - 1)
	{
		if (i == idx)
		{
			i++;
			continue;
		}

		new_list[j] = alist->data[i];
		i++;
		j++;
	}
	alist->size -= 1;
	free(alist->data);
	alist->data = new_list;
}

void print_list(list *alist)
{
	int i = 0;

	while (i < alist->size)
	{
		printf("%d\n", alist->data[i]);
		i++;
	}
}


int main()
{
	list *alist = create_list(2);

	add_element(10, alist);
	add_element(30, alist);
	add_element(40, alist);
	print_list(alist);
	remove_element(1, alist);
	print_list(alist);
}
