#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 因为边长的值最大可达 10^9，两个数相加可能会超过 int 范围，用 long long 更安全
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 从小到大排序
    sort(a.begin(), a.end());
    
    // 遍历所有相邻的三个数
    for (int i = 0; i < n - 2; i++) {
        // 如果较小的两边之和大于最大的一边
        if (a[i] + a[i+1] > a[i+2]) {
            // 找到一组解，直接输出并结束程序
            cout << a[i] << " " << a[i+1] << " " << a[i+2] << endl;
            return 0;
        }
    }
    
    // 如果循环结束都没找到，说明无解
    cout << "No solution" << endl;
    
    return 0;
}