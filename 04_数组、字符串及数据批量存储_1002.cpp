#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;cin>>n>>x;
    string s;
    for(int i=1;i<=n;i++){
        string tmp=to_string(i);
        s+=tmp;
    }
    int cnt=count(s.begin(),s.end(),x+'0');
    cout<<cnt;
    
    return 0;
}