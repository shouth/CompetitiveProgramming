#include<bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h+2, vector<char>(w+2, '#'));
    int white = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> s[i][j];
            if (s[i][j] == '.') white++;
        }
    }

    queue<tuple<int, int, int>> q;
    q.emplace(1, 1, 1);
    s[1][1] = '#';

    int ans = -1;
    vector<int> dxy{ 0, 1, 0, -1, 0 };
    while (!q.empty()) {
        auto n = q.front(); q.pop();
        int ch, cw, d;
        tie(ch, cw, d) = n;

        if (ch == h && cw == w) {
            ans = white - d;
            break;
        }

        for (int i = 0; i < 4; i++) {
            if (s[ch + dxy[i]][cw + dxy[i+1]] == '.') {
                q.emplace(ch + dxy[i], cw + dxy[i+1], d + 1);
                s[ch + dxy[i]][cw + dxy[i+1]] = '#';
            }
        }
    }
    
    cout << ans << endl;
}
