#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    // 记录两点之间的必经点，没有则为 0
    int mid[10][10] = {0};
    
    // 初始化必经点
    mid[1][3] = mid[3][1] = 2;
    mid[1][7] = mid[7][1] = 4;
    mid[1][9] = mid[9][1] = 5;
    mid[2][8] = mid[8][2] = 5;
    mid[3][7] = mid[7][3] = 5;
    mid[3][9] = mid[9][3] = 6;
    mid[4][6] = mid[6][4] = 5;
    mid[7][9] = mid[9][7] = 8;
    
    string s;
    // 多组输入，注意题目虽然没明说结束条件，但一般用 while(cin >> s) 处理即可
    while (cin >> s) {
        bool vis[10] = {false}; // 记录 1-9 是否被访问过
        bool isValid = true;
        
        // 记录第一个点
        int first = s[0] - '0';
        vis[first] = true;
        
        // 从第二个点开始遍历
        for (int i = 1; i < s.length(); i++) {
            int curr = s[i] - '0';       // 当前点
            int prev = s[i - 1] - '0';   // 上一个点
            
            // 规则1：不能重复使用
            if (vis[curr]) {
                isValid = false;
                break;
            }
            
            // 规则2：不能跨过未被使用的必经点
            int m = mid[prev][curr];
            if (m != 0 && !vis[m]) {
                isValid = false;
                break;
            }
            
            // 标记当前点为已访问
            vis[curr] = true;
        }
        
        // 输出结果
        if (isValid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}