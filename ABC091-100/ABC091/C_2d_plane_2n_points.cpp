#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> r(n), b(n);
    for (auto& e : r) cin >> e.first >> e.second;
    for (auto& e : b) cin >> e.first >> e.second;
    sort(begin(r), end(r), [](auto a, auto b) { return a.second > b.second; });
    sort(begin(b), end(b));

    int ans = 0;
    for (auto& bp : b) {
        for (auto itr = begin(r); itr != end(r); itr++) {
            if (bp.first > itr->first && bp.second > itr->second) {
                ans++;
                r.erase(itr);
                r.shrink_to_fit();
                break;
            }
        }
    }

    cout << ans << endl;
}
