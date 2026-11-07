#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k,m;cin>>n>>k>>m;
    vector<bool> vec(n,true);
    int now=k;
    for(int i=0;i<n-1;i++){
        int cnt=0;
        while(true){
            if(vec[now]){
                cnt+=1;
                if(cnt==m){
                    vec[now]=false;
                    break;
                }
            }
            now=(now+1)%n;
        }
        now=(now+1)%n;
    }
    
    for(int i=0;i<n;i++){
        if(vec[i]==true){
            cout<<i;
        }
    }
    
    return 0;
}