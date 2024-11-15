#ifndef __SORT_H__
#define __SORT_H__

#include <stdlib.h>

void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
int sort_one_digit(int *array, size_t size, int radix);

#endif /* __SORT_H__ */
