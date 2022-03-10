#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    char t;
    if (s[k-1] == 'A') t = 'a';
    else if (s[k-1] == 'B') t = 'b';
    else t = 'c';

    s[k-1] = t;

    cout << s << endl;
}