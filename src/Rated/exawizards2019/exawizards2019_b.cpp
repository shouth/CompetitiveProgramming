#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int r = count(s.begin(), s.end(), 'R'), b = n - r;
    cout << (r > b ? "Yes" : "No") << endl;
}