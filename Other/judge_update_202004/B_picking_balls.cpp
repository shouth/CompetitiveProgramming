#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n;
    cin >> n;
    vector<i32> r, b;
    for (i32 i = 0; i < n; i++) {
        i32 x;
        char c;
        cin >> x >> c;
        (c == 'R' ? r : b).push_back(x);
    }

    sort(begin(r), end(r));
    sort(begin(b), end(b));

    for (auto& e : r) cout << e << endl;
    for (auto& e : b) cout << e << endl;
}
