#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[30][100];
int cmp(const void *p,const void *q)
{
    int i=*(const int *)p;
    int j=*(const int *)q;
    
    char ab[60],ba[200];
    
    strcpy(ab,a[i]);
    strcat(ab,a[j]);
    
    strcpy(ba,a[j]);
    strcat(ba,a[i]);
    
    return strcmp(ba,ab);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);

}    int idx[30];
    for(int i=0;i<n;++i)
    {
    idx[i]=i;
}
    qsort(idx,n,sizeof(int),cmp);
    
    for(int i=0;i<n;++i)
    {
    printf("%s",a[idx[i]]);
}
    printf("\n");

    return 0;

}
