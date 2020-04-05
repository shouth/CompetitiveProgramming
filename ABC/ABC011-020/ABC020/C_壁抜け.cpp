#include<bits/stdc++.h>
using namespace std;
using node = tuple<int64_t, int64_t, int64_t>;

int main() {
    int64_t h, w, t;
    cin >> h >> w >> t;
    vector<vector<char>> s(h, vector<char>(w));
    int64_t sy, sx, gy, gx;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> s[i][j];
            if (s[i][j] == 'S') sy = i, sx = j;
            if (s[i][j] == 'G') gy = i, gx = j;
        }
    }

    vector<int64_t> dxy { 0, 1, 0, -1, 0 };
    int64_t bottom = 1, top = 1e9 + 10;
    while (abs(top - bottom) > 1) {
        int64_t middle = (bottom + top) / 2;

        vector<vector<int64_t>> cost(h, vector<int64_t>(w, -1));
        priority_queue<node, vector<node>, greater<node>> pq;
        pq.emplace(0, sy, sx);
        while (!pq.empty()) {
            int64_t t, y, x;
            tie(t, y, x) = pq.top(); pq.pop();
            if (cost[y][x] != -1) continue;
            cost[y][x] = t;
            for (int64_t i = 0; i < 4; i++) {
                int64_t ny = y + dxy[i], nx = x + dxy[i+1];
                if (ny < 0 || h <= ny || nx < 0 || w <= nx) continue;
                pq.emplace(t + (s[ny][nx] != '#' ? 1 : middle), ny, nx);
            }
        }

        (cost[gy][gx] <= t ? bottom : top) = middle;
    }

    cout << bottom << endl;
}
