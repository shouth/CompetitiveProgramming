#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    auto itr = unique(begin(s), end(s));
    cout << itr - begin(s) << endl;
}
