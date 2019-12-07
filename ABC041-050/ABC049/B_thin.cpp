#include<bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    for (auto& e : c) for (auto& f : e) cin >> f;

    for (auto& e : c) {
        for (auto& f : e) cout << f;
        cout << endl;
        for (auto& f : e) cout << f;
        cout << endl;
    }
}
