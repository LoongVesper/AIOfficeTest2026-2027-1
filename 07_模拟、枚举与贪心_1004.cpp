#include <iostream>
#include <string>
using namespace std;

int main() {
    // 加速输入输出
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    while (T--) {
        string s;
        cin >> s;
        string ans = "";
        int n = s.length();
        int i = 0;
        
        while (i < n) {
            // 1. 如果当前字符是数字
            if (s[i] >= '0' && s[i] <= '9') {
                // 只有 0, 2, 4, 6, 9 是需要提取的
                if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '9') {
                    ans += s[i];
                }
                i++;
            } 
            // 2. 如果当前字符是字母，检查是否匹配单词
            else {
                // 注意要先判断剩余长度，防止 substr 越界报错
                if (i + 4 <= n && s.substr(i, 4) == "zero") {
                    ans += '0';
                    i += 4;
                } else if (i + 3 <= n && s.substr(i, 3) == "two") {
                    ans += '2';
                    i += 3;
                } else if (i + 4 <= n && s.substr(i, 4) == "four") {
                    ans += '4';
                    i += 4;
                } else if (i + 3 <= n && s.substr(i, 3) == "six") {
                    ans += '6';
                    i += 3;
                } else if (i + 4 <= n && s.substr(i, 4) == "nine") {
                    ans += '9';
                    i += 4;
                } else {
                    // 如果都不是，说明是无关字母，跳过
                    i++;
                }
            }
        }
        
        // 输出本组结果
        cout << ans << "\n";
    }
    
    return 0;
}