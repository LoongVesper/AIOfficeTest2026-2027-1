#include<stdio.h>
int main()
{
    int n,m=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int x=1;x<=i;x++)
        {printf("%4d",m);m++;}
        printf("\n");
    }
    return 0;
}