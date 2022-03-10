#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> abc(3);
    for (auto& e : abc) cin >> e;
    sort(begin(abc), end(abc));
    auto itr = unique(begin(abc), end(abc));
    cout << distance(begin(abc), itr) << endl;
}
