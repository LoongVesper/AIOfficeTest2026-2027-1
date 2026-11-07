#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    char c;

    while (cin.get(c)) {
        s += c;
    }

    string ans;
    bool inString = false;
    int slashCount = 0;
    size_t i = 0;

    while (i < s.size()) {
        if (!inString && s[i] == '/' &&
            i + 1 < s.size() && s[i + 1] == '*') {

            size_t end = s.find("*/", i + 2);

            if (end != string::npos) {
                i = end + 2;
                slashCount = 0;
                continue;
            }
        }

        char c = s[i];

        if (c == '"' && slashCount % 2 == 0) {
            inString = !inString;
        }

        ans += c;

        if (c == '\\') {
            slashCount++;
        } else {
            slashCount = 0;
        }

        i++;
    }

    cout << ans;
    return 0;
}