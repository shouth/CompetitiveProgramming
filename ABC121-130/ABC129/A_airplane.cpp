#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> pqr(3);
    for (auto& e : pqr) cin >> e;

    cout << accumulate(pqr.begin(), pqr.end(), 0) - *max_element(pqr.begin(), pqr.end()) << endl;
}
