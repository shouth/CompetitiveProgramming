#include <utility>
#include <bitset>
#include <tuple>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> t(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    bitset<100'010> v;
    v[1] = v[n] = 1;
    queue<pair<int, int>> q;
    q.emplace(1, 0);
    q.emplace(n, 1);
    vector<int> s { 1, 1 };
    while (!q.empty()) {
        auto tmp = q.front(); q.pop();
        for (auto& e : t[tmp.first]) {
            if (v[e]) continue;
            q.emplace(e, tmp.second);
            s[tmp.second]++;
            v[e] = 1;
        }
    }
    cout << (s[0] > s[1] ? "Fennec" : "Snuke") << endl;
}
