#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << ((s.front() == s.back()) ^ (s.length() % 2 == 0) ? "Second" : "First") << endl;
}
