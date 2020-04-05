#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> abc(3);
    for (auto& e : abc) cin >> e;
    int k;
    cin >> k;
    sort(begin(abc), end(abc));
    cout << abc[0] + abc[1] + abc[2] * pow(2, k) << endl;;
}
