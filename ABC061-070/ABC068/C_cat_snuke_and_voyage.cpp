#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> c(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    vector<int> v;
    set_intersection(begin(c[1]), end(c[1]), begin(c[n]), end(c[n]), back_inserter(v));
    cout << (!v.empty() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}
