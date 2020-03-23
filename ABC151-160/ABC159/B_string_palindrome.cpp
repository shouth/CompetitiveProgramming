#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

bool is_kaibun(const string &str, i32 s, i32 e) {
    while (s <= e) {
        if (str[s] != str[e]) return false;
        s++, e--;
    }

    return true;
}

int main() {
    string s;
    cin >> s;
    i32 n = s.size();

    cout << (is_kaibun(s, 0, (n-3) / 2) && is_kaibun(s, 0, n-1) ? "Yes" : "No") << endl;
}
