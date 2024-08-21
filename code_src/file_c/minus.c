#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


char* minus(char *a,char *b)
{
    int n1= strlen(a),n2=strlen(b);

    if( n2> n1)
    {   
        char* temp =a;
        a= b;
        b=temp;

        int t= n1;
        n1= n2; n2= t;printf("-");
    }

    int index =0; int nho =0;
    char *res =(char*) calloc( n1+1, sizeof( char));

    for( int i =n1-1; i>= n1-n2; i--)
    {
        int substraction = a[i] -b[i-n1+n2] -nho;
        if( substraction<0)
        {
            res[index++] = substraction+10 +'0'  ;
            nho=1;
        }
        else 
        {   nho=0;
            res[index++] = substraction +'0';
        }


    }

    for ( int i =n1-n2 -1; i>=0; i--)
    {
        int substraction = a[i]-'0' -nho;
        if( substraction<0)
        {
            res[index++] = substraction+10 +'0'  ;
            nho=1;
        }
        else 
        {   nho=0;

            res[index++] = substraction +'0';
        }
    }
    if( nho)
    {
        char z[100]= "1";
        char k[100];
        memset(k, '0', n1);
        strcpy(z+1,k);
        
        res = minus(z, res); printf("-");
    }

    else 
    {
        strrev(res);

    }

    while( res[0]=='0') res++;
    return res;


}




int  main(void)
{
    char a[100],b[100];
    
    scanf("%s %s",a,b);

    printf("%s", minus(a,b));
   


}