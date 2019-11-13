#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a;
    a.push_back(0);
    for (int i=1; i<n; i++) {
        if (s[i-1] != s[i]) a.push_back(i);
    }
    vector<int> can;
    for (int i=0; i<a.size(); i++) {
        if (s[a[i]] == '0') {
            can.push_back((i+2*k >= a.size() ? n : a[i+2*k]) - a[i]);
        } else {
            can.push_back((i+2*k+1 >= a.size() ? n : a[i+2*k+1]) - a[i]);
        }
    }
    cout << *max_element(can.begin(), can.end()) << endl;
}