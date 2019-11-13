#include<bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    for (auto e : n) cout << (e == '1' ? '9' : '1');
}
