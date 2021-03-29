#include "mixed.h"

int mixed_set(sMixedNumber *pNumber,int32_t a,int32_t b,int32_t c)
{
    pNumber->a=a;
    pNumber->b=b;
    pNumber->c=c;
    if(b>=c)
    {
        return -1;
    }
    if(a!=0)
    {
        if(b<=0||c<=0||(c<0&&b<0))
        {
            return -1;
        }
    }
    else
    {
        if(c<=0||(c<0&&b<0))
        {
            return -1;
        }
    }
    for(int i=2;i<sqrt(b>c?b:c);i++)
    {
        if(b%i==0&&c%i==0)
        return -1;
    }
    return 0;
}

int mixed_print(const sMixedNumber number)
{
    printf("(%d,%d,%d)\n",number.a,number.b,number.c);
    return 0;
} 

void mixed_add(sMixedNumber *pNumber,const sMixedNumber r1,const sMixedNumber r2)
{
    int sum;
    if(r1.a<0&&r2.a<0)
    {
        sum=(r1.a*r1.c-r1.b)*r2.c+(r2.a*r2.c-r2.b)*r1.c;
    }
    else if(r1.a<0&&r2.a>0)
    {
        sum=(r1.a*r1.c-r1.b)*r2.c+(r2.a*r2.c+r2.b)*r1.c;
    }
    else if(r1.a>0&&r2.a<0)
    {
        sum=(r1.a*r1.c+r1.b)*r2.c+(r2.a*r2.c-r2.b)*r1.c;
    }
    else
    {
        sum=(r1.a*r1.c+r1.b)*r2.c+(r2.a*r2.c+r2.b)*r1.c;
    }
    pNumber->a=(int)sum/(r1.c*r2.c);
    int tempb=(int)sum%(r1.c*r2.c);
    int tempc=(int)r1.c*r2.c;
    for(int i=1;i<(tempb>tempc?tempb:tempc);i++)
    {
        if(tempb%i==0&&tempc%i==0)
        {
            tempb/=i;
            tempc/=i;
        }
    }
    if(tempb==0)
    tempc=0;
    pNumber->b=tempb;
    pNumber->c=tempc;
}

void mixed_sub(sMixedNumber *pNumber,const sMixedNumber r1,const sMixedNumber r2)
{
    int sum;
    if(r1.a<0&&r2.a<0)
    {
        sum=(r1.a*r1.c-r1.b)*r2.c-(r2.a*r2.c-r2.b)*r1.c;
    }
    else if(r1.a<0&&r2.a>0)
    {
        sum=(r1.a*r1.c-r1.b)*r2.c-(r2.a*r2.c+r2.b)*r1.c;
    }
    else if(r1.a>0&&r2.a<0)
    {
        sum=(r1.a*r1.c+r1.b)*r2.c-(r2.a*r2.c-r2.b)*r1.c;
    }
    else
    {
        sum=(r1.a*r1.c+r1.b)*r2.c-(r2.a*r2.c+r2.b)*r1.c;
    }
    pNumber->a=sum/(r1.c*r2.c);
    int tempb;
    if(pNumber->a==0)
    {
        tempb=sum%(r1.c*r2.c);
    }
    else
    {
        tempb=abs(sum%(r1.c*r2.c));
    }
    int tempc=r1.c*r2.c;
    for(int i=1;i<(tempb>tempc?tempb:tempc);i++)
    {
        if(tempb%i==0&&tempc%i==0)
        {
            tempb/=i;
            tempc/=i;
        }
    }
    if(tempb==0)
    tempc=0;
    pNumber->b=tempb;
    pNumber->c=tempc;
}

void mixed_mul(sMixedNumber *pNumber,const sMixedNumber r1,const sMixedNumber r2)
{
    int upper;
    if(r1.a<0&&r2.a<0)
    {
        upper=(r1.a*r1.c-r1.b)*(r2.a*r2.c-r2.b);
    }
    else if(r1.a<0&&r2.a>0)
    {
        upper=(r1.a*r1.c-r1.b)*(r2.a*r2.c+r2.b);
    }
    else if(r1.a>0&&r2.a<0)
    {
        upper=(r1.a*r1.c+r1.b)*(r2.a*r2.c-r2.b);
    }
    else
    {
        upper=(r1.a*r1.c+r1.b)*(r2.a*r2.c+r2.b);
    }
    int lower=(r1.c)*(r2.c);
    pNumber->a=upper/lower;
    int tempb;
    if(pNumber->a==0)
    {
        tempb=upper%lower;
    }
    else
    {
        tempb=abs(upper%lower);
    }
    int tempc=lower;
    for(int i=1;i<(tempb>tempc?tempb:tempc);i++)
    {
        if(tempb%i==0&&tempc%i==0)
        {
            tempb/=i;
            tempc/=i;
        }
    }
    if(tempb==0)
    tempc=0;
    pNumber->b=tempb;
    pNumber->c=tempc;
}

void mixed_div(sMixedNumber *pNumber,const sMixedNumber r1,const sMixedNumber r2)
{
    int upper,lower;
    if(r1.a<0&&r2.a<0)
    {
        upper=(r1.a*r1.c-r1.b)*(r2.c);
        lower=(r1.c)*(r2.a*r2.c-r2.b);
    }
    else if(r1.a<0&&r2.a>0)
    {
        upper=(r1.a*r1.c-r1.b)*(r2.c);
        lower=(r1.c)*(r2.a*r2.c+r2.b);
    }
    else if(r1.a>0&&r2.a<0)
    {
        upper=(r1.a*r1.c+r1.b)*(r2.c);
        lower=(r1.c)*(r2.a*r2.c-r2.b);
    }
    else
    {
        upper=(r1.a*r1.c+r1.b)*(r2.c);
        lower=(r1.c)*(r2.a*r2.c+r2.b);
    }
    pNumber->a=upper/lower;
    int tempb;
    if(pNumber->a==0)
    {
        tempb=upper%lower;
    }
    else
    {
        tempb=abs(upper%lower);
    }
    int tempc=lower;
    for(int i=1;i<(tempb>tempc?tempb:tempc);i++)
    {
        if(tempb%i==0&&tempc%i==0)
        {
            tempb/=i;
            tempc/=i;
        }
    }
    if(tempb==0)
    tempc=0;
    pNumber->b=tempb;
    pNumber->c=tempc;
}
