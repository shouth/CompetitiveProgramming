#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> n(5);
    for (auto& e : n) cin >> e;
    vector<int> select { 0, 0, 1, 1, 1 };
    vector<int> s;
    do {
        int tmp = 0;
        for (int i = 0; i < 5; i++) {
            if (select[i]) tmp += n[i];
        }
        s.push_back(tmp);
    } while (next_permutation(begin(select), end(select)));
    sort(begin(s), end(s), greater<>());
    cout << s[2] << endl;
}
