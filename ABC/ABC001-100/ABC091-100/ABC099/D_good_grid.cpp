#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> d(c, vector<int>(c));
    for (auto& e : d) for (auto& f : e) cin >> f;
    vector<vector<int>> color(3, vector<int>(c));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int cij;
            cin >> cij, cij--;
            color[(i+j) % 3][cij]++;
        }
    }

    int ans = 1e9;
    for (int i = 0; i + 2 < c; i++) {
        for (int j = i + 1; j + 1 < c; j++) {
            for (int k = j + 1; k < c; k++) {
                vector<int> c3 { i, j, k };
                do {
                    int can = 0;
                    for (int l = 0; l < 3; l++) {
                        for (int m = 0; m < c; m++) {
                            can += color[l][m] * d[m][c3[l]];
                        }
                    }
                    ans = min(ans, can);
                } while (next_permutation(begin(c3), end(c3)));
            }
        }
    }

    cout << ans << endl;
}
