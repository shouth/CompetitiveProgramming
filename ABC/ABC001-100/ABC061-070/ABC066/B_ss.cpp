#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = s.size() / 2 - 1; i > 0; i--) {
        if (equal(begin(s), begin(s) + i, begin(s) + i, begin(s) + 2*i)) {
            cout << i * 2 << endl;
            return 0;
        }
    }
}
