#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义一个结构体，用来存每个巧克力的早上和晚上甜蜜值
struct Chocolate {
    int a;
    int b;
    int diff; // 存放差值 a - b
};

// 自定义排序规则：按差值从大到小排序
bool cmp(const Chocolate& x, const Chocolate& y) {
    return x.diff > y.diff;
}

int main() {
    // 加速输入输出，防止数据量大超时
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, K;
    if (!(cin >> n >> K)) return 0;

    vector<Chocolate> choco(n);
    
    // 读入早上的甜蜜值
    for (int i = 0; i < n; i++) {
        cin >> choco[i].a;
    }
    // 读入晚上的甜蜜值
    for (int i = 0; i < n; i++) {
        cin >> choco[i].b;
        // 顺便计算差值
        choco[i].diff = choco[i].a - choco[i].b;
    }

    // 按照差值从大到小排序，把早上吃优势最大的排在前面
    sort(choco.begin(), choco.end(), cmp);

    // 注意：数据范围相乘很大，必须用 long long 存总和，否则会溢出
    long long ans = 0;

    // 前 K 个在早上吃，剩下的在晚上吃
    for (int i = 0; i < n; i++) {
        if (i < K) {
            ans += choco[i].a;
        } else {
            ans += choco[i].b;
        }
    }

    cout << ans << "\n";

    return 0;
}