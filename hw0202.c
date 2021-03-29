#include <stdio.h>
#include "hw0202.h"

int main() 
{
    struct _Number pNumber;
    double number;
    printf("Please enter a floating -point number (double precision):　");
    scanf("%lf",&number);
    func(&pNumber,number);
    return 0;
}