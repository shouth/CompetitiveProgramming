#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> s(n, vector<char>(n));
    for (auto& e : s) for (auto& f : e) cin >> f;

    for (int i = 0; i < n; i++) {
        for (int j = n-1; j >= 0; j--) {
            cout << s[j][i];
        }
        cout << endl;
    }
}
