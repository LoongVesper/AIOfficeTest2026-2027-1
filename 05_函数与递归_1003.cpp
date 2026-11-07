#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long ans = n;
    long long t = n / 10;

    while(t > 0){
        ans = ans * 10 + t % 10;
        t /= 10;
    }
    bool flag = true;
    for(long long i = 2; i*i < ans; i++){
        if(ans % i == 0){
            flag = false;
            break;
        }
    }
    if(flag){
        cout <<"prime"<< endl;
    }
    else{
        cout <<"noprime"<< endl;
    }
    return 0;
}