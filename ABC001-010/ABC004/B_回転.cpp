#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<char>> c(4, vector<char>(4));
    for (auto& e : c) for (auto& f : e) cin >> f;
    for (int i = 3; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) cout << c[i][j] << (j == 0 ? "" : " ");
        cout << endl;
    }
}
