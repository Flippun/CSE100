#include "Swap.h"

/**
 * Swap the values of integers a and b (in-place)
 */
void swap(int & a, int & b) {
    int* aPtr = &a;
    int* bPtr = &b;
    int temp = a;
    *aPtr = *bPtr;
    *bPtr = temp;
}
