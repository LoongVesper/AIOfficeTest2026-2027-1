#include <iostream>
using namespace std;

int main(){
    int y, m, x;
    int cnt = 0;

    while(cin >> y >> m >> x){
        int days = 28;
        if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)){
            days = 29;
        }

        if(m == 1 || m == 3 || m == 5 || m == 7 ||
           m == 8 || m == 10 || m == 12){
            for(int i = 1; i <= 31; i++){
                int t = i;
                while(t > 0){
                    if(t % 10 == x){
                        cnt++;
                    }
                    t /= 10;
                }

                int ty = y;
                while(ty > 0){
                    if(ty % 10 == x){
                        cnt++;
                    }
                    ty /= 10;
                }

                int tm = m;
                while(tm > 0){
                    if(tm % 10 == x){
                        cnt++;
                    }
                    tm /= 10;
                }
            }
        }

        if(m == 4 || m == 6 || m == 9 || m == 11){
            for(int i = 1; i <= 30; i++){
                int t = i;
                while(t > 0){
                    if(t % 10 == x){
                        cnt++;
                    }
                    t /= 10;
                }

                int ty = y;
                while(ty > 0){
                    if(ty % 10 == x){
                        cnt++;
                    }
                    ty /= 10;
                }

                int tm = m;
                while(tm > 0){
                    if(tm % 10 == x){
                        cnt++;
                    }
                    tm /= 10;
                }
            }
        }

        if(m == 2){
            for(int i = 1; i <= days; i++){
                int t = i;
                while(t > 0){
                    if(t % 10 == x){
                        cnt++;
                    }
                    t /= 10;
                }

                int ty = y;
                while(ty > 0){
                    if(ty % 10 == x){
                        cnt++;
                    }
                    ty /= 10;
                }

                int tm = m;
                while(tm > 0){
                    if(tm % 10 == x){
                        cnt++;
                    }
                    tm /= 10;
                }
            }
        }

        if(x == 0){
            cnt += 9;

            if(m < 10){
                if(m == 2){
                    cnt += days;
                }
                else if(m == 4 || m == 6 || m == 9){
                    cnt += 30;
                }
                else{
                    cnt += 31;
                }
            }
        }

        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}