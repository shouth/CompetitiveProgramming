#include <utility>
#include <bitset>
#include <tuple>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<string, int, int>> sp;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        int p;
        cin >> p;
        sp.emplace_back(s, p, i);
    }
    sort(sp.begin(), sp.end(), [](auto a, auto b) {
        return (get<0>(a) != get<0>(b)) ? (get<0>(a) < get<0>(b)) : (get<1>(a) > get<1>(b));
    });
    for(auto& e : sp) {
        cout << get<2>(e) << endl;
    }
}
