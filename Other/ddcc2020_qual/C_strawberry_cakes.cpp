#include<bits/stdc++.h>
using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> s(h, vector<char>(w));
    for (auto& e : s) for (auto& f : e) cin >> f;

    int g = 0, bi = 0;
    vector<vector<int>> ans(h, vector<int>(w));
    vector<bool> emp(h);
    for (int hi = 0; hi < h; hi++) {
        int last = 0;
        for (int wi = 0; wi < w; wi++) {
            if (s[hi][wi] == '.') continue;
            g++;
            fill(begin(ans[hi])+last, begin(ans[hi])+wi+1, g);
            last = wi+1;
        }
        if (last == 0) {
            emp[hi] = true;
        } else {
            bi = hi;
            fill(begin(ans[hi])+last, end(ans[hi]), g);
        }
    }

    for (int i = bi; i-1 >= 0; i--) {
        if (emp[i-1]) ans[i-1] = ans[i];
    }
    for (int i = bi; i+1 < h; i++) {
        if (emp[i+1]) ans[i+1] = ans[i];
    }

    for (auto& e : ans) {
        for (auto& f : e) {
            cout << f << " ";
        }
        
        cout << endl;
    }
}
