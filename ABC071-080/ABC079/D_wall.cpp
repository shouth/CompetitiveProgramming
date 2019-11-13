#include<bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> c(10, vector<int>(10));
    for (auto& e : c) for (auto& f : e) cin >> f;
    vector<int> m(10);
    for (int i = 0; i < h * w; i++) {
        int a;
        cin >> a;
        if (a != -1) m[a]++;
    }

    int ans = 0;
    bitset<10> done;
    while (!done.all()) {
        vector<int> can(10, 1e9);
        for (int i = 0; i < 10; i++) if (!done[i]) can[i] = c[i][1];
        int mi = min_element(begin(can), end(can)) - begin(can);
        done.set(mi);
        for (int i = 0; i < 10; i++) c[i][1] = min(c[i][1], c[mi][1] + c[i][mi]);
        ans += c[mi][1] * m[mi];
    }

    cout << ans << endl;
}
