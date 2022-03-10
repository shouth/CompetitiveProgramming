#include<bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    auto itr = unique(begin(n), end(n));
    cout << (distance(begin(n), itr) == 1 ? "SAME" : "DIFFERENT") << endl;
}
