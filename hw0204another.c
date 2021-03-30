#include "bignum.h"

void print( const sBigNum num )
{    
    int o=1;
    for(int i=0;i<num.log;i++)
    {
        if(num.a[i]!=0)
        {
            o=0;
            break;
        }
    }
    if(o==1)
    {
        printf("0");
    }
    if(num.sign==-1)
    printf("-");
    if(num.overflow==1)
    printf("%d",num.overflow);
    else if(num.overflow==-1)
    printf("-");
    if(o==0)
    {
        for(int i=0;i<num.log;i++)
        {
            if(i!=0)
            {
                printf("%d",num.a[i]);
            }
            else
            {
                if(num.a[i])
                printf("%d",num.a[i]);
            }
        }
    }   
    printf("\n");
}
int32_t set( sBigNum *pNum, char *str )
{
    pNum->sign=1;
    for(int i=0;i<1000;i++)
    {
        pNum->a[i]=-1;
    }
    if(str[0]!='-')
    {
        for(int i=0;i<strlen(str);i++)
        {
            pNum->a[i]=(str[i]-48);
        }
    }
    else
    {
        for(int i=0;i<strlen(str)-1;i++)
        {
            pNum->a[i]=(str[i+1]-48);
        }
        pNum->sign=-1;
    }
    pNum->log=0;
    for(int i=0;pNum->a[i]!=-1&&i<1000;i++)
    {
        pNum->log++;
    }
}

int32_t compare( const sBigNum num01 , const sBigNum num02 )
{
    
    if(num01.log>num02.log)
    {
        return 1;
    }
    else if(num01.log<num02.log)
    {
        return -1;
    }
    else
    {
        int rnum=0;
        for(int i=0;num01.log;i++)
        {
            if(num01.a[i]>num02.a[i])
            {
                rnum=1;
                break;
            }
            else if(num01.a[i]<num02.a[i])
            {
                rnum=-1;
                break;
            }
        }
        return rnum;
    }
}

int32_t digits( const sBigNum num )
{
    return num.log;
}

void add( sBigNum *pResult ,const sBigNum num01 ,const sBigNum num02 )
{
    for(int i=0;i<1000;i++)
    {
        pResult->a[i]=0;
    }
    int times1=num01.log>num02.log?num01.log:num02.log;
    pResult->log=times1;
    pResult->overflow=0;
    int times2=num01.log<num02.log?num01.log:num02.log;
    
    times2--;
    for(int i=times1;i<1000;i++)
    {
        pResult->a[i]=-1;
    }
    if(num01.sign==1)
    {
        if(times1==num01.log)
        {
            for(int i=times1-1;i>=0;i--)
            {
                if(times2>-1)
                {
                    pResult->a[i]+=num01.a[i]+num02.sign*num02.a[times2];
                    times2--;
                }
                else
                {
                    pResult->a[i]+=num01.a[i];  
                }
                if(pResult->a[i]>=10&&i!=0)
                {
                    pResult->a[i]-=10;
                    pResult->a[i-1]=1;
                }
                else if(pResult->a[i]>=10&&i==0)
                {
                    pResult->a[i]-=10;
                    pResult->overflow=1;
                }
                if(pResult->a[i]<0&&i!=0)
                {
                    pResult->a[i]+=10;
                    pResult->a[i-1]=-1;
                }
                else if(pResult->a[i]<0&&i==0)
                {
                    pResult->a[i]+=10;
                    pResult->overflow=-1;
                }
            }
        }
        else
        {
            for(int i=times1-1;i>=0;i--)
            {
                if(times2>-1)
                {
                    pResult->a[i]+=num01.a[times2]+num02.a[i]*num02.sign;
                    times2--;
                }
                else
                {
                    pResult->a[i]+=num02.a[i]*num02.sign;
                }
                if(pResult->a[i]>=10&&i!=0)
                {
                    pResult->a[i]-=10;
                    pResult->a[i-1]=1;
                }
                else if(pResult->a[i]>=10&&i==0)
                {
                    pResult->a[i]-=10;
                    pResult->overflow=1;
                }
                if(pResult->a[i]<0&&i!=0)
                {
                    pResult->a[i]+=10;
                    pResult->a[i-1]=-1;
                }
                else if(pResult->a[i]<0&&i==0)
                {
                    pResult->a[i]+=10;
                    pResult->overflow=-1;
                }
            }
        }
    }
    else if(num01.sign==-1)
    {
        
        if(times1==num01.log)
        {
            for(int i=times1-1;i>=0;i--)
            {
                if(times2>-1)
                {
                    pResult->a[i]+=num01.a[i]*-num01.sign-num02.sign*num02.a[times2];
                    times2--;
                }
                else
                {
                    pResult->a[i]-=num01.a[i]*num01.sign;  
                }
                if(pResult->a[i]>=10&&i!=0)
                {
                    pResult->a[i]-=10;
                    pResult->a[i-1]=1;
                }
                else if(pResult->a[i]>=10&&i==0)
                {
                    pResult->a[i]-=10;
                    pResult->overflow=1;
                }
                if(pResult->a[i]<0&&i!=0)
                {
                    pResult->a[i]+=10;
                    pResult->a[i-1]=-1;
                }
                else if(pResult->a[i]<0&&i==0)
                {
                    pResult->a[i]+=10;
                    pResult->overflow=-1;
                }
                pResult->sign=-1;
            }
        }
        else
        {
            for(int i=times1-1;i>=0;i--)
            {
                if(times2>-1)
                {
                    pResult->a[i]+=num01.a[times2]*num01.sign+num02.a[i]*num02.sign;
                    times2--;
                }
                else
                {
                    pResult->a[i]+=num02.a[i]*num02.sign;
                }
                if(pResult->a[i]>=10&&i!=0)
                {
                    pResult->a[i]-=10;
                    pResult->a[i-1]=1;
                }
                else if(pResult->a[i]>=10&&i==0)
                {
                    pResult->a[i]-=10;
                    pResult->overflow=1;
                }
                if(pResult->a[i]<0&&i!=0)
                {
                    pResult->a[i]+=10;
                    pResult->a[i-1]=-1;
                }
                else if(pResult->a[i]<0&&i==0)
                {
                    pResult->a[i]+=10;
                    pResult->overflow=-1;
                }
            }
        }
    }
}

void subtract( sBigNum *pResult , const sBigNum num01 , const sBigNum num02 )
{
    for(int i=0;i<1000;i++)
    {
        pResult->a[i]=0;
    }
    int times1=num01.log>num02.log?num01.log:num02.log;
    pResult->log=times1;
    pResult->overflow=0;
    int times2=num01.log<num02.log?num01.log:num02.log;
    
    times2--;
    for(int i=times1;i<1000;i++)
    {
        pResult->a[i]=-1;
    }
    
    if(num02.sign==-1&&num01.sign==1)
    {
        //printf("1\n");
        if(times1==num01.log)
        {
            for(int i=times1-1;i>=0;i--)
            {
                if(times2>-1)
                {
                    pResult->a[i]+=num01.a[i]*num01.sign+num02.a[times2];
                    times2--;
                }
                else
                {
                    pResult->a[i]+=num01.a[i]*num01.sign;  
                }
                if(pResult->a[i]<0&&i!=0)
                {
                    pResult->a[i]+=10;
                    pResult->a[i-1]=-1;
                }
                else if(pResult->a[i]>=10&&i==0)
                {
                    pResult->a[i]+=10;
                    pResult->overflow=-1;
                }      
            }           
        }
        else
        {
            for(int i=times1-1;i>=0;i--)
            {
                if(times2>-1)
                {
                    pResult->a[i]+=num01.a[times2]*num01.sign+num02.a[i];
                    times2--;
                }
                else
                {
                    pResult->a[i]+=num02.a[i]*num02.sign;
                }
                if(pResult->a[i]<0&&i!=0)
                {
                    pResult->a[i]+=10;
                    pResult->a[i-1]=-1;
                }
                else if(pResult->a[i]>=10&&i==0)
                {
                    pResult->a[i]+=10;
                    pResult->overflow=-1;
                }                
            }
        }
        if(num01.sign==-1)
        pResult->sign=1;
    }
    else if(num02.sign==-1&&num01.sign==-1)
    {
        //printf("2\n");
        if(times1==num01.log)
        {
            for(int i=times1-1;i>=0;i--)
            {
                if(times2>-1)
                {
                    pResult->a[i]+=num02.a[times2]-num01.a[i];
                    times2--;
                }
                else
                {
                    pResult->a[i]-=num01.a[i];  
                }
                if(pResult->a[i]<0&&i!=0)
                {
                    pResult->a[i]+=10;
                    pResult->a[i-1]=-1;
                }
                else if(pResult->a[i]>=10&&i==0)
                {
                    pResult->a[i]+=10;
                    pResult->overflow=-1;
                }      
            }           
        }
        else
        {
            for(int i=times1-1;i>=0;i--)
            {
                if(times2>-1)
                {
                    pResult->a[i]+=num01.a[times2]+num02.a[i];
                    times2--;
                }
                else
                {
                    pResult->a[i]+=num02.a[i];
                }
                if(pResult->a[i]<0&&i!=0)
                {
                    pResult->a[i]+=10;
                    pResult->a[i-1]=-1;
                }
                else if(pResult->a[i]>=10&&i==0)
                {
                    pResult->a[i]+=10;
                    pResult->overflow=-1;
                }                
            }
        }
        if(num01.sign==-1)
        pResult->sign=1;
    }
    else if(num01.sign==-1)
    {
        if(times1==num01.log)
        {
            for(int i=times1-1;i>=0;i--)
            {
                if(times2>-1)
                {
                    pResult->a[i]+=num01.a[i]*-num01.sign-num02.a[times2];
                    times2--;
                }
                else
                {
                    pResult->a[i]+=num01.a[i]*-num01.sign;  
                }
                if(pResult->a[i]<0&&i!=0)
                {
                    pResult->a[i]+=10;
                    pResult->a[i-1]=-1;
                }
                else if(pResult->a[i]>=10&&i==0)
                {
                    pResult->a[i]+=10;
                    pResult->overflow=-1;
                }      
            }           
        }
        else
        {
            for(int i=times1-1;i>=0;i--)
            {
                if(times2>-1)
                {
                    pResult->a[i]+=num01.a[times2]*-num01.sign-num02.a[i]*-num02.sign;
                    times2--;
                }
                else
                {
                    pResult->a[i]-=num02.a[i]*-num02.sign;
                }
                if(pResult->a[i]<0&&i!=0)
                {
                    pResult->a[i]+=10;
                    pResult->a[i-1]=-1;
                }
                else if(pResult->a[i]>=10&&i==0)
                {
                    pResult->a[i]+=10;
                    pResult->overflow=-1;
                }
                                
            }
        }
    }
    else if(num01.sign==1)
    {
        if(times1==num01.log)
        {
            for(int i=times1-1;i>=0;i--)
            {
                if(times2>-1)
                {
                    pResult->a[i]+=num01.a[i]-num02.a[times2];
                    times2--;
                }
                else
                {
                    pResult->a[i]+=num01.a[i];  
                }
                if(pResult->a[i]<0&&i!=0)
                {
                    pResult->a[i]+=10;
                    pResult->a[i-1]=-1;
                }
                else if(pResult->a[i]>=10&&i==0)
                {
                    pResult->a[i]+=10;
                    pResult->overflow=-1;
                }      
            }           
        }
        else if(num01.sign==1&&num02.sign==-1)
        {
            for(int i=times1-1;i>=0;i--)
            {
                if(times2>-1)
                {
                    pResult->a[i]+=num01.a[times2]+num02.a[i];
                    times2--;
                }
                else
                {
                    pResult->a[i]+=num02.a[i];
                }
                if(pResult->a[i]<0&&i!=0)
                {
                    pResult->a[i]+=10;
                    pResult->a[i-1]=-1;
                }
                else if(pResult->a[i]>=10&&i==0)
                {
                    pResult->a[i]+=10;
                    pResult->overflow=-1;
                }                
            }
        }
    }
}    
void multiply( sBigNum *pResult , const sBigNum num01 , const sBigNum num02 )
{
    int ans[1000]={0};
    int t=0;
    int array01[num01.log];
    int times1=0;
    for(int i=num01.log-1;i>=0;i--)
    {
        array01[times1]=num01.a[i];
        times1++;
    }
    int array02[num02.log];
    int times2=0;
    for(int i=num02.log-1;i>=0;i--)
    {
        array02[times2]=num02.a[i];
        times2++;
    }
    for(int m=0;m<num01.log;m++)
    {
        for(int n=0;n<num02.log;n++)
        {
            ans[m+n+1]+=array01[m]*array02[n];
            if(ans[m+n]>10)
            {
                ans[m+n+1]+=ans[m+n]/10;
                ans[m+n]%=10;
            }   
        }
    }
    int time;
    for(int j=num01.log+num02.log;j>0;j--)
    {
        if(j!=0)
        {
            time=j;
            break;
        }
    }
    int count =0;
    for(int j=time-1;j>0;j--)
    {
        pResult->a[count]=ans[j];
        count++;
    }
    pResult->log=count;
    pResult->sign=num01.sign*num02.sign;
}
void divide( sBigNum *pQuotient , sBigNum *pRemainder , const sBigNum num01 , const sBigNum num02 )
{
    sBigNum A,B;
    for(int i=0;i<num01.log;i++)
    {
        A.a[i]=num01.a[i];
    }
    A.log=num01.log;
    int times=0;
    A.sign=1;
    B.a[0]=0;
    for(;B.a[0]>=0;times++)
    {
        subtract( &B , A ,num02);
        for(int i=0;i<B.log;i++)
        {  
            A.a[i]=B.a[i]; 
        }
    }
    add( &B , A ,num02);
    
    for(int i=0;i<B.log;i++)
    {
        pRemainder->a[i]=B.a[i]; 
    }
    pRemainder->log=B.log;
    
    times--;
    int count=0;
    int array1[(int)log(times)];
    while(times>0)
    {
        array1[count]=times%10;
        times/=10;
        count++;
    }
     
    int j=0;
    for(int i=count-1;i>=0;i--)
    {
        pQuotient->a[j]=array1[i];
        j++;
    }
    pQuotient->log=count;
    
    B.log=pRemainder->log;
    
    
}

int32_t power( sBigNum *pResult , int32_t n, int32_t k )
{
    sBigNum A,B;
    int N=n;
    int count=0;
    int array1[(int)log(n)];
    while(N>0)
    {
        array1[count]=N%10;
        N/=10;
        count++;
    }
    int j=0;
    for(int i=count-1;i>=0;i--)
    {
        pResult->a[j]=array1[i];
        j++;
    }
    for(int i=0;i<count;i++)
    {
        A.a[i]=pResult->a[i];
        B.a[i]=pResult->a[i];
    }
    A.log=count;
    B.log=A.log;
    if(k>1)
    {
        for(int i=1;i<k;i++)
        {
            multiply( pResult, B , A );
            for(int i=0;i<B.log;i++)
            {   
                B.a[i]=pResult->a[i];
            }
        }
    }
    else if(k==1)
    {

        for(int i=0;i<A.log;i++)
        {
            A.a[i]=pResult->a[i];
            pResult->log=A.log;
        }
    } 
    else if(k==0)
    {
        pResult->a[0]=1;
        pResult->log=1;
    }  
    pResult->sign=1; 
}
/*int32_t combine( sBigNum *pResult , int32_t n, int32_t k )
{
    sBigNum A,B;
    set(&A,"0");
    A.sign=1;
    A.log=1;
    A.a[0]=1;
    if(n==1&&k==0)
    {
        set(pResult,"1");
        //printf("1,0:");
        //print(*pResult);
    }
    
    else if(k==0||n==k)
    {
        set(pResult,"1");

        //print(*pResult);
    }

    else
    {
        if(n-k<k)
            k=n-k;
        
        combine(pResult,n-1,k);
        
        
        add(pResult,*pResult,A);
        
        for(int i=0;i<pResult->log;i++)
        {
            pResult->a[i]=A.a[i];
        }
        print(*pResult);
        pResult->log=A.log;
        pResult->sign=A.sign;
        combine(pResult,n-1,k-1);
        add(pResult,*pResult,A);

    }

}*/
int32_t combine( sBigNum *pResult , int32_t n, int32_t k )
{
    sBigNum num,A;
    int e[(int)log(n)];
    set(&A,"0");
    A.sign=1;
    set(&num,"1");
    set(pResult,"0");
    if(n==k)
    {
        num.sign=1;
        pResult->sign=1;
        add(pResult,*pResult,num);
    }
    else if(k==0)
    {
        num.sign=1;
        pResult->sign=1;
        add(pResult,*pResult,num);   
    }
    else if(k==1)
    {
        /*int count=0;
        int N=n;
        while(N>0)
        {
            e[count]=N%10;
            N/=10;
            count++;
        }
        int times=0;
        for(int i=count-1;i>=0;i++)
        {
            num.a[times]=e[i];
            times++;
        }
        num.log=count;
        num.sign=1;*/
        num.a[0]=n;
        num.log=1;
        num.sign=1;
        pResult->sign=1;
        add(pResult,*pResult,num);
    }
    else
    {
        num.sign=1;
        pResult->sign=1;
        combine(pResult,n-1,k-1);
        for(int i=0;i<pResult->log;i++)
        {
            A.a[i]=pResult->a[i];
        }
        
        A.log=pResult->log;
        A.sign=pResult->sign;
        combine(pResult,n-1,k);
        add(pResult,*pResult,A);
    }
}
/*
int32_t combine2( sBigNum *pResult , int32_t n, int32_t k )
{
    sBigNum num,A;
    int e[(int)log(n)];
    set(&A,"0");
    A.sign=1;
    set(&num,"1");
    set(pResult,"0");
    if(pResult->log==NULL)
    {
        set(pResult,"0");
        pResult->sign=1;
    }
    if(n==k)
    {
        num.sign=1;
        pResult->sign=1;
        add(pResult,*pResult,num);
    }
    else if(k==0)
    {
        num.sign=1;
        pResult->sign=1;
        add(pResult,*pResult,num);   
    }
    else if(k==1)
    {
        /*int count=0;
        int N=n;
        while(N>0)
        {
            e[count]=N%10;
            N/=10;
            count++;
        }
        int times=0;
        for(int i=count-1;i>=0;i++)
        {
            num.a[times]=e[i];
            times++;
        }
        num.log=count;
        num.sign=1;
        num.a[0]=n;
        num.log=1;
        num.sign=1;
        pResult->sign=1;
        add(pResult,*pResult,num);
    }
    else
    {
        num.sign=1;
        pResult->sign=1;
        combine2(pResult,n-1,k-1);
        for(int i=0;i<pResult->log;i++)
        {
            A.a[i]=pResult->a[i];
        }
        
        A.log=pResult->log;
        A.sign=pResult->sign;
        combine2(pResult,n-1,k);
        add(pResult,*pResult,A);
    }
}*/