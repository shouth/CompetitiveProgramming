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
    vector<string> ans;
    for (int i = 0; i < pow(3, n); i++) {
        string can;
        for (int j = 0, k = i; j < n; j++) {
            can += (char) ('a' + k % 3);
            k /= 3;
        }
        ans.push_back(can);
    }
    sort(ans.begin(), ans.end());
    for (auto& e : ans) cout << e << endl;
}
