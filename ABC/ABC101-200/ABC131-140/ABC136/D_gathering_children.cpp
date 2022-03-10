#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    s += '*';

    vector<int> ans(n);
    for (int i = 0; i < n;) {
        int pi = i;
        if (s[i] == 'R') {
            while (s[i] == 'R') i++;
            ans[i-1] += (i - pi + 1) / 2;
            ans[i] += (i - pi) / 2;
        } else {
            while (s[i] == 'L') i++;
            ans[pi-1] += (i - pi) / 2;
            ans[pi] += (i - pi + 1) / 2;
        }
    }
    for (auto& e : ans) cout << e << " ";
}
