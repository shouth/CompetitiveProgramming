#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    sort(begin(s), end(s));
    auto itr = unique(begin(s), end(s));
    cout << (n == distance(begin(s), itr) ? "yes" : "no") << endl;
}
