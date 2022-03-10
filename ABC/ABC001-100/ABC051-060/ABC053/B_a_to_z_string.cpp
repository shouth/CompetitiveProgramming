#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    auto a = find(begin(s), end(s), 'A');
    auto z = find(rbegin(s), rend(s), 'Z');
    cout << (int) s.size() - distance(begin(s), a) - distance(rbegin(s), z) << endl;
}
