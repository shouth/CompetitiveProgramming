#include<bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    vector<pair<string, string>> vw(n);
    for (auto& e : vw) cin >> e.first >> e.second;

    for (int i = 0; i < pow(3, k); i++) {
        map<char, int> d;
        int t = i;
        for (char j = '1'; j < '1' + k; j++) d[j] = t % 3 + 1, t /= 3;

        map<char, string> m;
        bool integrity = true;
        for (auto& e : vw) {
            string v, w;
            tie(v, w) = e;
            int wi = 0;
            for (auto& c : v) {
                if (wi + d[c] > (int) w.size()) {
                    integrity = false;
                    break;
                }

                string ss = w.substr(wi, d[c]);
                if (m[c] != "" && m[c] != ss) {
                    integrity = false;
                    break;
                }

                wi += d[c], m[c] = ss;
            }

            if (wi != (int) w.size()) {
                integrity = false;
                break;
            }
        }

        if (integrity) {
            for (char c = '1'; c < '1' + k; c++) cout << m[c] << endl;
            break;
        }
    }
}
