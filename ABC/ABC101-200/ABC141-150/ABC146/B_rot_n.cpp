#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (auto& e : s) {
        cout << (char) ((e - 'A' + n) % 26 + 'A');
    }
}
