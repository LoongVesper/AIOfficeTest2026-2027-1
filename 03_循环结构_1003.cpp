#include<stdio.h>
int main()
{
    char b;
    scanf("%c",&b);
    int i=b-64;
    for(int n=0;n<i;n++)
    {
        for(int x = 1;x<i-n;x++)
        {printf(" ");}
      for(int m=65;m<=n+65;m++)
      {printf("%c",m);}
        for(int a=n+64;a>=65;a--)
        {printf("%c",a);}
        printf("\n");
    }
}