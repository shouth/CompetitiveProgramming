#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n, n--;
    vector<string> can;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            can.push_back({s[i], s[j]});
        }
    }

    sort(begin(can), end(can));
    cout << can[n] << endl;
}
