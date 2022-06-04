#ifndef __KS_RANDOM_H__
#define __KS_RANDOM_H__

#ifndef BOOL
typedef enum bool {
	false,
	true
} bool;
#define BOOL
#endif

static int prngState = 0;
static int (*_rand)();

int init_rand(int);
extern inline int linear_congruential_generator();
extern inline rand_range(int , int );



#endif