#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> abc(3);
    for (auto& e : abc) cin >> e;
    sort(begin(abc), end(abc));
    cout << abc[1] << endl;
}
