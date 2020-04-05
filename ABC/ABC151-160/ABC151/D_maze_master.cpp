#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (auto& e : s) cin >> e;

    vector<int64_t> dxy { 0, 1, 0, -1, 0 };
    vector<vector<int64_t>> dist(h*w, vector<int64_t>(h*w, INT32_MAX));
    for (int i = 0; i < h*w; i++) dist[i][i] = 0;

    for (int hi = 0; hi < h; hi++) {
        for (int wi = 0; wi < w; wi++) {
            for (int d = 0; d < 4; d++) {
                int nhi = hi + dxy[d], nwi = wi + dxy[d+1];
                if (nhi < 0 || h <= nhi || nwi < 0 || w <= nwi) continue;
                if (s[hi][wi] != '.' || s[nhi][nwi] != '.') continue;
                dist[w*hi+wi][w*nhi+nwi] = 1;
            }
        }
    }

    for (int i = 0; i < h*w; i++) {
        for (int j = 0; j < h*w; j++) {
            for (int k = 0; k < h*w; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    int64_t ans = 0;
    for (int hi1 = 0; hi1 < h; hi1++) {
        for (int wi1 = 0; wi1 < w; wi1++) {
            for (int hi2 = 0; hi2 < h; hi2++) {
                for (int wi2 = 0; wi2 < w; wi2++) {
                    if (s[hi1][wi1] != '.' || s[hi2][wi2] != '.') continue;
                    if (dist[w*hi1+wi1][w*hi2+wi2] == INT32_MAX) continue;
                    ans = max(ans, dist[w*hi1+wi1][w*hi2+wi2]);
                }
            }
        }
    }

    cout << ans << endl;
}
