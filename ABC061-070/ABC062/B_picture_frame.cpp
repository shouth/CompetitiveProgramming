#include<bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (auto& e : a) cin >> e;
    cout << string(w+2, '#') << endl;
    for (auto& e : a) cout << '#' << e << '#' << endl;
    cout << string(w+2, '#') << endl;
}
