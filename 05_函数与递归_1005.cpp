#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 高精度乘法函数
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    
    int n1 = num1.size();
    int n2 = num2.size();
    // 两个数相乘，结果的最大位数是 n1 + n2
    vector<int> res(n1 + n2, 0);
    
    // 从后往前遍历（即从个位开始算）
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            // 将字符转成数字并相乘
            int mul = (num1[i] - '0') * (num2[j] - '0');
            
            // mul 加在哪个位置？
            int p1 = i + j;     // 高位进位位置
            int p2 = i + j + 1; // 当前位位置
            
            // 加上当前位置原本的数（可能之前有进位）
            int sum = mul + res[p2];
            
            // 更新当前位和进位
            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }
    
    // 将数组转回字符串
    string ans = "";
    bool leadingZero = true;
    for (int num : res) {
        // 去掉前导 0
        if (num == 0 && leadingZero) continue;
        leadingZero = false;
        ans += to_string(num);
    }
    
    return ans.empty() ? "0" : ans;
}

int main() {
    int T;
    cin >> T; // 读取测试组数
    
    while (T--) {
        string s1, s2;
        cin >> s1 >> s2; // 以字符串形式读取两个大数
        cout << multiply(s1, s2) << endl;
    }
    
    return 0;
}