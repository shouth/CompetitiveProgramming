#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    vector<i32> a(9), u(9);
    for (auto& e : a) cin >> e;
    i32 n;
    cin >> n;
    for (i32 i = 0; i < n; i++) {
        i32 b;
        cin >> b;
        auto itr = find(begin(a), end(a), b);
        if (itr == end(a)) continue;
        i32 idx = distance(begin(a), itr);
        u[idx] = 1;
    }

    bool j = false;
    j |= u[0] && u[3] && u[6];
    j |= u[1] && u[4] && u[7];
    j |= u[2] && u[5] && u[8];
    j |= u[0] && u[1] && u[2];
    j |= u[3] && u[4] && u[5];
    j |= u[6] && u[7] && u[8];
    j |= u[0] && u[4] && u[8];
    j |= u[2] && u[4] && u[6];
    cout << (j ? "Yes" : "No") << endl;
}
