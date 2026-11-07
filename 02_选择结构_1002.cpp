#include <stdio.h>
int main()
{
    int n,y;
    scanf("%d",&n);
    if (n%2!=0)
    {
        y=3*n+1;
        printf("%d",y);
    }
    else 
    {
        y=n/2;
        printf("%d",y);
    }
    return 0;
}