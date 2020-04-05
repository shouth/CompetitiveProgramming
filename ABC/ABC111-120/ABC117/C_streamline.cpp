#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(m);
    for (auto& e : x) cin >> e;
    sort(x.begin(), x.end());
    
    vector<int> d(m-1);
    for (int i=0; i<m-1; i++) d[i] = x[i+1] - x[i];
    sort(d.begin(), d.end());
    
    cout << (n >= m ? 0 : accumulate(d.begin(), d.begin() + m-n, 0)) << endl;
}