#include<bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> m(h, vector<int>(w));
    for (auto& e : m) {
        for (auto& f : e) {
            cin >> f;
        }
    }
    for (auto& e : m) {
        for (auto& f : e) {
            int b;
            cin >> b;
            f -= b;
        }
    }

    
}
