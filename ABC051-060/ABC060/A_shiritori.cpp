#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    cout << (a.back() == b.front() && b.back() == c.front() ? "YES" : "NO") << endl;
}
