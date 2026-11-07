#include<bits/stdc++.h>
using namespace std;

int aaa(int n){
    int cot=0;
    while (n>0){
        if (n%10==2){
            cot++;
        }
        n/=10;
    }
    return cot;
}

int main(){
    int L,R;
    cin>>L>>R;
    int ans=0;
    for (int i=L;i<=R;i++){
        ans+=aaa(i);
    }
    cout<<ans;
    return 0;
}