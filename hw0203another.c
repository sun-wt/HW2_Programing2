#include "hw0203.h"

void printer(int n,const uByte var)
{
    printf("Data: %3d ",n);
    printf("%d%d%d%d%d%d%d%d\n",var.bits.b8, var.bits.b7,var.bits.b6,var.bits.b5,var.bits.b4,var.bits.b3,var.bits.b2,var.bits.b1);
}

void change(int n,int *ans,int *f)
{
    int flip=-1;
    int sum=0;
    while(flip>8||flip<0)
    {
        printf("Flip bit (1-8, 0: exit):");
        scanf("%d",&flip);
        *f=flip;
    }
    if(flip) 
    {
        int num=n,i=0;
        int e[8]={0};
        while(num>0)
        {
            e[i]=num%2;
            i++;
            num/=2;
        }
        if(e[8-flip]==0)
        {
            e[8-flip]=1;
        }
        else
        {
            e[8-flip]=0;
        }
        for(int j=0;j<8;j++)
        {
            sum+=e[j]*pow(2,j);
        }
        *ans=sum;  
    }  
    else
    {
        *ans=0;
        exit(0);
    }
}