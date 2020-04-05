#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    auto itr = unique(begin(s), end(s));
    cout << distance(begin(s), itr) - 1 << endl;
}
