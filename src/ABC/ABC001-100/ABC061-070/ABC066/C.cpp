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
    deque<int> ans;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (n % 2 != i % 2) ans.push_front(a); else ans.push_back(a);
    }
    for (auto& e : ans) cout << e << " ";
}
