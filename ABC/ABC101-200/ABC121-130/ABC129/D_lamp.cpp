#include<bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (auto& e : s) cin >> e;
    
    vector<vector<int>> left(h, vector<int>(w)), right(h, vector<int>(w)), up(h, vector<int>(w)), down(h, vector<int>(w));
    
    for (int y=0; y<h; y++) {
        left[y][0] = (s[y][0] == '.' ? 1 : 0);
        for (int x=1; x<w; x++) {
            left[y][x] = (s[y][x] == '.' ? left[y][x-1] + 1 : 0);
        }
    }

    for (int y=0; y<h; y++) {
        right[y][w-1] = (s[y][w-1] == '.' ? 1 : 0);
        for (int x=w-2; x>=0; x--) {
            right[y][x] = (s[y][x] == '.' ? right[y][x+1] + 1 : 0);
        }
    }

    for (int x=0; x<w; x++) {
        up[0][x] = (s[0][x] == '.' ? 1 : 0);
        for (int y=1; y<h; y++) {
            up[y][x] = (s[y][x] == '.' ? up[y-1][x] + 1 : 0);
        }
    }

    for (int x=0; x<w; x++) {
        down[h-1][x] = (s[h-1][x] == '.' ? 1 : 0);
        for (int y=h-2; y>=0; y--) {
            down[y][x] = (s[y][x] == '.' ? down[y+1][x] + 1 : 0);
        }
    }

    vector<vector<int>> sum(h, vector<int>(w));
    for (int y=0; y<h; y++) {
        for (int x=0; x<w; x++) {
            sum[y][x] = left[y][x] + right[y][x] + up[y][x] + down[y][x];
        }
    }

    int ans = 0;
    for (auto& e : sum) {
        ans = max(ans, *max_element(e.begin(), e.end()));
    }

    cout << ans - 3 << endl;
}
