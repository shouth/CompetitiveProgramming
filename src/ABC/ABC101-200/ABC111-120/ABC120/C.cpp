#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    size_t a = count(s.begin(), s.end(), '0');
    cout << min(a, s.size() - a) * 2 << endl;
}