#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H
#define min_(a, b) ((a) < (b) ? (a) : (b))

/*Libraries*/
#include <stddef.h>

/*Prototypes*/
int linear_search(int *, size_t, int);
int binary_search(int *, size_t, int);
int jump_search(int *, size_t, int);
int interpolation_search(int *, size_t, int);
int exponential_search(int *, size_t, int);
int advanced_binary(int *, size_t, int);

#endif /*SEARCH_ALGOS_H*/
