#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    map<string, int> m;
    for (int i = 0; i+k <= (int) s.size(); i++) m[s.substr(i, k)]++;
    cout << m.size() << endl;
}
