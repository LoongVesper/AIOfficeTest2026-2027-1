#include <iostream>
using namespace std;
int main(){ 
    int x,y;
    cin>>x>>y;
    int cnt=0;
    for(int i=x;i<=y;i++){
        int ans=0;
        int t=i;
        while(t>0){
            ans+=t%10;
            t/=10;
        }
        if(ans % 5 == 0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
return 0;
}