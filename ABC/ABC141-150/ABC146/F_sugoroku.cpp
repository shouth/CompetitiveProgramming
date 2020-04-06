#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

template<typename T>
struct sparsetable {
    vector<vector<T>> st;
    vector<i32> lookup;
    
    sparsetable(const vector<T> &v) {
        i32 n = v.size();
        st.assign(log2(n) + 1, vector<T>());
        st[0].assign(begin(v), end(v));
        for (i32 i = 1; (1 << i) <= n; i++) {
            st[i].assign(n - (1 << i) + 1, 0);
            for (i32 j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }

        lookup.assign(n + 1, 0);
        for (i32 i = 2; i < n + 1; i++) {
            lookup[i] = lookup[i >> 1] + 1;
        }
    }

    inline T rmq(i32 l, i32 r) {
        i32 b = lookup[r - l];
        return min(st[b][l], st[b][r - (1 << b)]);
    }
};

int main() {
    i32 n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<i32> idx(n+1);
    for (i32 i = 0; i < n+1; i++) idx[i] = s[i] == '0' ? i : INT32_MAX;
    
    sparsetable<i32> st(idx);
    deque<i32> ans;
    for (i32 i = n, j; i > 0; i = j) {
        j = st.rmq(max(0l, i - m), i);
        if (j == INT32_MAX) {
            cout << -1 << endl;
            return 0;
        }
        ans.push_front(i - j);
    }

    for (i32 i = 0; i < ans.size(); i++) cout << (i == 0 ? "" : " ") << ans[i];
    cout << endl;
}
