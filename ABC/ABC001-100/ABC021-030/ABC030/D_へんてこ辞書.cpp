#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    string k, sn = to_string(n);
    cin >> k;
    vector<int> b(n+1);
    for (int i = 1; i <= n; i++) cin >> b[i];

    map<int, int> order;
    int s = 0, t = a;
    while (order.find(b[t]) == order.end()) order[t] = s++, t = b[t];
    int l = order[b[t]], c = s - l + 1;
    int kk = 0;

    if (k.length() == sn.length() ? k > sn : k.length() > sn.length()) {
        for (auto& e : k) kk = (kk * 10 + (e - '0')) % c;
        while (kk < l) kk += c;
    } else {
        kk = stoi(k);
    }

    int ans = a;
    for (int i = 0; i < kk; i++) ans = b[ans];
    cout << ans << endl;
}
