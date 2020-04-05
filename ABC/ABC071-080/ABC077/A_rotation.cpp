#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    reverse(begin(b), end(b));
    cout << (a == b ? "YES" : "NO") << endl;
}
