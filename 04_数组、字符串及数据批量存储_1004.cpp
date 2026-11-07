#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int L,M;cin>>L>>M;
    vector<int> vec(L+1);
    while(M){
        int l,r;cin>>l>>r;
        for(int i=l;i<=r;i++){
            vec[i]+=1;
        }
        M--;
    }
    int cnt=0;
    for(auto x:vec){
        if(x==0){
            cnt+=1;
        }
    }
    cout<<cnt;
    
    
    
    return 0;
}