#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> abc(3);
    for (auto& e : abc) cin >> e;
    sort(begin(abc), end(abc));
    cout << (abc == vector<int> { 5, 5, 7 } ? "YES" : "NO") << endl;
}
