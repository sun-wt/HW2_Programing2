#ifndef HW0202_H_INCLUDE
#define HW0202_H_INCLUDE

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct _Number
{   
    bool sign;
    int32_t exponent;
}Number;
void func(Number *pNumber,double number);

#endif