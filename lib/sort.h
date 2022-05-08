#ifndef __SORT_H__
#define __SORT_H__

#include <time.h>
#include <stdlib.h>
#include <assert.h>

#define swap(x,y) {int t; (t)=(x); (x)=(y); (y)=(t);}

void quick_sort(int *, int, int, int);
void bubble_sort(int *, int);
// TODO:
// void merge_sort(void *v, int left, int right);
// void counting_sort(void *v, int k);

#endif
