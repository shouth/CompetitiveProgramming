#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> ans;
    for (int i = 0; i < k && a + i <= b; i++) ans.push_back(a + i);
    for (int i = 0; i < k && b - i >= a; i++) ans.push_back(b - i);
    sort(begin(ans), end(ans));
    for (auto itr = begin(ans), eitr = unique(begin(ans), end(ans)); itr != eitr; itr++) cout << *itr << endl;
}
