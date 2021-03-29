#include "hw0202.h"

void func(Number *pNumber,double number)
{
    int32_t fra[64];
    if(number>0)
    {
        pNumber->sign=0;
    }
    else
    {
        pNumber->sign=1;
    }
    for(int i=0;i<64;i++)
    {
        fra[i]=0;
    }
    int integer=abs((int)number);
    
    if(integer!=0)
    {
        int binary1[64];
        int i=0;
        while(integer>0)
        {
            binary1[i]=integer%2;
            i++;
            integer/=2;       
        }
        pNumber->exponent=1022+i;
        i-=2;
        int count=0;
        for(;i>=0;i--)
        {
        fra[count]=binary1[i];
        count++;
        }
        double fraction=fabs(number)-abs((int)number);
        int binary2[64];
        int j=0;
        while(fraction>0)
        {
            binary2[j]=(int)(fraction*2);
            j++;
            fraction=(fraction*2)-1;      
        }
        j--;
        int times=j;
        for(;j>=0;j--)
        {
            fra[count]=binary2[j];
            count++;
        }
        printf("Sign: %d\n",pNumber->sign);
        printf("Exponent: ");
        int e[64]={0};
        int p=0;
        int exponent=pNumber->exponent;
        while(exponent>0)
        {
            e[p]=exponent%2;
            p++;
            exponent/=2;       
        }
        p--;
        for(int j=0;j+p<10;j++)
        {
            printf("0");
        }
        for(;p>=0;p--)
        {
            printf("%d",e[p]);
        }
        printf("\n");
        printf("Fraction: ");
        for(int i=0;i<64;i++)
        {
            printf("%d",fra[i]);
        }
        printf("\n");
        printf("%g = (-1)^%d * (1",number,pNumber->sign);
        for(int i=0;i<=63;i++)
        {
            if(fra[i]!=0)
            {
                printf(" + 2^-%d ",i+1);
            }
        }
        printf(") * 2 ^ (%d-1023)\n",pNumber->exponent);
    }
    else
    {
        double test=fabs(number);
        int i=0;
        while(test<1)
        {
            test*=2;
            i++;
        }
        pNumber->exponent=1023-i;
        int count=0;
        double fraction=fabs(number);
        int binary[64];
        int j=0;
        while(fraction!=0&&j<64)
        {
            fraction*=2;
            binary[j]=(int)fraction;
            if(binary[j])
            {
                fraction--;
            }
            j++;
        }
        j-=2;
        int times=j;
        for(;j>=0;j--)
        {
            fra[count]=binary[j];
            count++;
        }
        printf("Sign: %d\n",pNumber->sign);
        printf("Exponent: ");
        int e[64]={0};
        int p=0;
        int exponent=pNumber->exponent;
        while(exponent>0)
        {
            e[p]=exponent%2;
            p++;
            exponent/=2;       
        }
        p--;
        for(int j=0;j+p<10;j++)
        {
            printf("0");
        }
        for(;p>=0;p--)
        {
            printf("%d",e[p]);
        }
        printf("\n");
        printf("Fraction: ");
        for(int i=0;i<64;i++)
        {
            printf("%d",fra[i]);
        }
        printf("\n");
        
        printf("%g = (-1)^%d * (1",number,pNumber->sign);
        for(int i=0;i<=63;i++)
        {
            if(fra[i]!=0)
            {
                printf(" + 2^-%d ",i+1);
            }
        }
        printf(") * 2 ^ (%d-1023)\n",pNumber->exponent);
    }
}