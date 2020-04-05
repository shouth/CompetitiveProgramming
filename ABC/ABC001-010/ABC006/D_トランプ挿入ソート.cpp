#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        auto itr = upper_bound(begin(v), end(v), c);
        if (itr == end(v)) v.push_back(c);
        else *itr = c;
    }

    cout << n - v.size() << endl;
}
