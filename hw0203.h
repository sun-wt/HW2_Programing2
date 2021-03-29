#ifndef HW0203_H_INCLUDE
#define HW0203_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef union
{
    struct
    {
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
        unsigned char b8:1;
    }bits;
    unsigned char byte;
}uByte;

void printer(int n,const uByte var);
void change(int n,int *ans,int *f);

#endif