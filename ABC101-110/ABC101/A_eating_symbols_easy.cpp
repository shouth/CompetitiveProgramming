#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << count(begin(s), end(s), '+') - count(begin(s), end(s), '-') << endl;
}
