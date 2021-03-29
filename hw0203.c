#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hw0203.h"

int main()
{
    int number,ans;
    int flip=-1;
    printf("Please enter a byte (0-255) :");
    scanf("%d",&number);
    if(number>=0&&number<=255)
    {
        uByte *var=(uByte*)&(number);
        printer(number,*var);
        change(number,&ans,&flip);
        var=(uByte*)&(ans);
        printer(ans,*var);
        while(flip!=0)
        {
            change(ans,&ans,&flip);
            var=(uByte*)&(ans);
            printer(ans,*var);
        }
    }
    else
    {
        printf("error!\n");
    }    
    return 0;
}