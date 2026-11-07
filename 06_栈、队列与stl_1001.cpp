#include<bits/stdc++.h>
using namespace std;
int n=8,a[9],book[9]={0};
void dfs(int step)
{
    if(step==n)
    {
        for(int i=0;i<n;i++)
        {
            if(i==0)
                cout << a[i];
            else
                cout << " " << a[i];
        }
        cout << endl;
        return;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            a[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
}
int main()
{
    dfs(0);
    return 0;
}