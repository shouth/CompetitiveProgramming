#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    vector<int64_t> time(5);
    cin >> n;
    for(auto& e : time) {
        cin >> e;
    }
    sort(time.begin(), time.end());
    cout << 5 + n / time[0] + (n % time[0] != 0 ? 1 : 0) - 1 << endl;
}