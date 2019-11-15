#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> ans;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (n % 2 != i % 2) ans.push_front(a); else ans.push_back(a);
    }
    for (auto& e : ans) cout << e << " ";
}
