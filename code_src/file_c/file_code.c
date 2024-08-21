#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void solve (char a[100],char b[100])
{   int max =0;
    
    int count [10000]={0};
    char * z =strtok( a,"+");
   while( 1)
   {
        
        if( z == NULL) break;

        char *c= strstr(z,"*x^");


        count[atoi(c+3)] += atoi(z);
        if( atoi(c+3) >= max) max = atoi(c+3);
        z = strtok(NULL,"+");



   }
    z =strtok( b,"+");
   while( 1)
   {
        
        if( z == NULL) break;

        char *c= strstr(z,"*x^");

        count[atoi(c+3)] += atoi(z);
        if( atoi(c+3) >= max) max = atoi(c+3);
        z = strtok(NULL,"+");
   }
        int flag =0;
    for (int i =max; i>=0; i--)
    {   
        if( count[i] !=0)
        {   if( flag ==1)
            printf(" + " );

            printf("%d*x^%d",count[i],i);
            flag =1;
            
        }

    }

}




int main(void)
{
    int t ;scanf("%d",&t);
    getchar();
    while( t --)
    {
        char a[500], b[500];

       
        fgets(a,500,stdin);
        fgets(b,500,stdin);
         printf("%s %s",a,b);
        solve(a,b);


    }
/*1 
1*x^3 + 1*x^4 + 3*x^8
1*x^3 + 1*x^4 + 3*x^8 */



}