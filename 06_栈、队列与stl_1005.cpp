#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int count = 0;
    bool isGood = true;
    
    // 遍历字符串
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') {
            count++; // 遇到 a 加 1
        } else if (s[i] == 'b') {
            count--; // 遇到 b 减 1
        }
        
        // 如果在任意时刻 b 的数量超过了 a，说明不合法
        if (count < 0) {
            isGood = false;
            break;
        }
    }
    
    // 最后如果 count 为 0，且过程中没有出现 b 多了的情况
    if (isGood && count == 0) {
        cout << "Good" << endl;
    } else {
        cout << "Bad" << endl;
    }
    
    return 0;
}