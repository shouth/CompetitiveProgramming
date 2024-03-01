#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    string s;
    cin >> N >> Q >> s;
    vector<pair<char, char>> td(Q);
    for(auto& e : td) {
        cin >> e.first >> e.second;
    }
    reverse(td.begin(), td.end());
    int l = 0, r = N;
    for(auto& e : td) {
        if(e.second == 'R') {
            if(s[l-1] == e.first) l--;
            if(s[r-1] == e.first) r--;
        } else {
            if(s[l] == e.first) l++;
            if(s[r] == e.first) r++;
        }
    }
    cout << r - l << endl;
}
