#include<bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int sy, sx;
    cin >> sy >> sx, sy--, sx--;
    int gy, gx;
    cin >> gy >> gx, gy--, gx--;
    vector<vector<char>> maze(r, vector<char>(c));
    for (auto& e : maze) for (auto& f : e) cin >> f;

    vector<vector<int>> depth(r, vector<int>(c, -1));
    depth[sy][sx] = 0;
    queue<pair<int, int>> q;
    q.emplace(sy, sx);
    vector<int> dxy { 0, 1, 0, -1, 0 };
    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dxy[i], nx = x + dxy[i+1];
            if (ny < 0 || r <= ny || nx < 0 || c < nx) continue;
            if (maze[ny][nx] == '#' || depth[ny][nx] != -1) continue;
            depth[ny][nx] = depth[y][x] + 1;
            q.emplace(ny, nx);
        }
    }

    cout << depth[gy][gx] << endl;
}
