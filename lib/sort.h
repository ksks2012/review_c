#ifndef __SORT_H__
#define __SORT_H__

#include <time.h>
#include <stdlib.h>
#include <assert.h>

typedef enum bool {
	false,
	true
} bool;

#define swap(x,y) {int t; (t)=(x); (x)=(y); (y)=(t);}

void quick_sort(int *, int, int, int);
void bubble_sort(int *, int);
void merge_sort(int *, int, int, int *);
// TODO:
// void counting_sort(void *v, int k);

#endif
