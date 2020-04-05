#include<bits/stdc++.h>
using namespace std;

int main() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<string> s(r);
    for (auto& e : s) cin >> e;
    vector<vector<int>> board(r, vector<int>(c));
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] == 'o') continue;
            q.emplace(i, j);
            board[i][j] = 1;
        }
    }

    vector<int> dxy { 0, 1, 0, -1, 0 };
    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        if (board[y][x] == k) continue;
        for (int i = 0; i < 4; i++) {
            int ny = y + dxy[i], nx = x + dxy[i+1];
            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (board[ny][nx] != 0) continue;
            board[ny][nx] = board[y][x] + 1;
            q.emplace(ny, nx);
        }
    }

    int ans = 0;
    for (int i = k-1; i < r-k+1; i++) {
        for (int j = k-1; j < c-k+1; j++) {
            if (board[i][j] == 0) ans++;
        }
    }

    cout << ans << endl;
}
