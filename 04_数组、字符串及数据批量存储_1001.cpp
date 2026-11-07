#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    while (cin >> T) {
        while (T--) {
            int n;
            cin >> n;

            vector<long long> a(n); 
            long long sum = 0;
            
            long long max_val = -1e18; 
            long long min_val = 1e18;

            for (int i = 0; i < n; i++) {
                cin >> a[i];
                sum += a[i];
                if (a[i] > max_val) max_val = a[i];
                if (a[i] < min_val) min_val = a[i];
            }

            long long range = max_val - min_val;
            
            double mean = (double)sum / n;
            
            double variance = 0;
            for (int i = 0; i < n; i++) {
                variance += (a[i] - mean) * (a[i] - mean);
            }
            variance /= n;

            if (variance < 0 && variance > -1e-6) {
                variance = 0;
            }

            cout << range << " " << fixed << setprecision(3) << variance << "\n";
        }
    }
    return 0;
}