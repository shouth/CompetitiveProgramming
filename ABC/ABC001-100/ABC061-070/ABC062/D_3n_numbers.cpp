#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> fcan(n+1), scan(n+1);
    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> fpq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fpq.push(a);
        fcan[0] += a;
    }
    vector<int64_t> amid(n);
    for (auto& e : amid) cin >> e;
    priority_queue<int64_t> spq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        spq.push(a);
        scan[n] += a;
    }

    for (int64_t i = 0; i < n; i++) {
        fpq.push(amid[i]);
        fcan[i+1] = fcan[i] + amid[i] - fpq.top(); fpq.pop();
        spq.push(amid[n-1-i]);
        scan[n-i-1] = scan[n-i] + amid[n-1-i] - spq.top(); spq.pop();
    }

    int64_t ans = -1e18;
    for (int64_t i = 0; i <= n; i++) ans = max(ans, fcan[i] - scan[i]);

    cout << ans << endl;
}
