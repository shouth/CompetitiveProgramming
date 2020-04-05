#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << 700 + 100 * (count(begin(s), end(s), 'o')) << endl;
}
