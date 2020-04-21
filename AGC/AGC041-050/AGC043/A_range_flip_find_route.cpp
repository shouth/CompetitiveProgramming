#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

i32 h, w;
vector<string> dp;

i32 dfs(i32 r, i32 c) {
    
}

int main() {
    cin >> h >> w;
    dp.assign(h, "");
    for (auto& e : dp) cin >> e;
    cout << dfs(0, 0) << endl;
}
