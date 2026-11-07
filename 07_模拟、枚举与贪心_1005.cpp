#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> cnt(10);
    int odd_cnt = 0;
    int mid = -1;
    
    // 读入 0-9 的出现次数
    for (int i = 0; i < 10; i++) {
        cin >> cnt[i];
        if (cnt[i] % 2 != 0) {
            odd_cnt++;
            mid = i; // 记录最后一个奇数，作为中间数
        }
    }
    
    // 1. 如果出现奇数次的数字超过 1 个，绝对无法构成回文数
    if (odd_cnt > 1) {
        cout << -1 << endl;
        return 0;
    }
    
    // 2. 找最小的非 0 数字，用它来开头
    int first_non_zero = -1;
    for (int i = 1; i <= 9; i++) {
        if (cnt[i] >= 2) {
            first_non_zero = i;
            break;
        }
    }
    
    // 3. 如果没有非 0 的数字能配对，说明只能是无解或单个 0
    if (first_non_zero == -1) {
        if (cnt[0] == 1 && odd_cnt == 1) {
            cout << 0 << endl; // 只有 1 个 0
        } else if (cnt[0] == 0 && odd_cnt == 1) {
            cout << mid << endl; // 只有 1 个非 0 数字
        } else {
            cout << -1 << endl; // 有多个 0 但没法开头，无解
        }
        return 0;
    }
    
    // 4. 开始构造左半部分
    string left = "";
    left += to_string(first_non_zero); // 开头放最小的非0数字
    
    // 紧接着放所有的 0
    if (cnt[0] > 1) {
        left += string(cnt[0] / 2, '0');
    }
    
    // 放剩下的 first_non_zero
    if (cnt[first_non_zero] > 2) {
        left += string(cnt[first_non_zero] / 2 - 1, first_non_zero + '0');
    }
    
    // 按顺序放剩下的非 0 数字
    for (int i = first_non_zero + 1; i <= 9; i++) {
        if (cnt[i] >= 2) {
            left += string(cnt[i] / 2, i + '0');
        }
    }
    
    // 5. 输出：左半边 + 中间数 + 右半边（左半边反转）
    cout << left;
    if (odd_cnt == 1) {
        cout << mid;
    }
    for (int i = left.length() - 1; i >= 0; i--) {
        cout << left[i];
    }
    cout << endl;
    
    return 0;
}