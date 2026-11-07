#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    long long t;
    cin >> n >> t;
    string s;
    cin >> s;
    
    // 找到小数点的位置
    int pos = s.find('.');
    if (pos == string::npos) {
        // 没有小数点，直接输出原数字
        cout << s << endl;
        return 0;
    }
    
    // 从小数点后第一位开始，找第一个 >= '5' 的数字
    int i = pos + 1;
    while (i < s.length() && s[i] < '5') {
        i++;
    }
    
    // 如果找到了，且还有四舍五入次数
    while (t > 0 && i < s.length() && s[i] >= '5' && i > pos) {
        t--;
        s.erase(i); // 舍去当前位置及其后面的所有数字
        i--;        // 准备进位，i 指向需要加 1 的位置
        
        // 如果进位位置正好到了小数点，直接跳过小数点去加前一位
        if (i == pos) {
            i--;
        }
        
        // 处理连续进位（比如 9 进位变 10）
        while (i >= 0 && s[i] == '9') {
            s[i] = '0';
            i--;
            if (i == pos) i--; // 跳过小数点
        }
        
        if (i < 0) {
            // 到了最高位还在进位，补一个 1
            s = "1" + s;
            i = 0;
            break;
        } else {
            // 正常进位，加 1
            s[i]++;
        }
    }
    
    // 如果最终还存在小数点，处理末尾的 0 和小数点
    if (pos != -1) {
        while (s.length() > pos && s.back() == '0') {
            s.pop_back();
        }
        if (s.back() == '.') {
            s.pop_back();
        }
    }
    
    cout << s << endl;
    return 0;
}