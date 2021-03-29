#include <stdio.h>
#include "mixed.h"

int main(void) 
{
    struct _sMixedNumber pNumber;
    struct _sMixedNumber r1;
    struct _sMixedNumber r2;
    int32_t a,b,c;
    printf("Please enter the whole number: ");
    scanf("%d",&a);
    printf("Please enter the numerator: ");
    scanf("%d",&b);
    printf("Please enter the dinominator: ");
    scanf("%d",&c); 
    if(mixed_set(&r1,a,b,c)==0)
    {
        printf("Please enter the whole number: ");
        scanf("%d",&a);
        printf("Please enter the numerator: ");
        scanf("%d",&b);
        printf("Please enter the dinominator: ");
        scanf("%d",&c);
        if(mixed_set(&r2,a,b,c)==0)
        {
            mixed_add(&pNumber,r1,r2);
            mixed_print(pNumber);
            mixed_sub(&pNumber,r1,r2);
            mixed_print(pNumber);
            mixed_mul(&pNumber,r1,r2);
            mixed_print(pNumber);
            mixed_div(&pNumber,r1,r2);
            mixed_print(pNumber);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
    
    return 0;
}