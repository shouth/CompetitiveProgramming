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
    string s;
    cin >> s;
    int n;
    cin >> n, n--;
    vector<string> can;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            can.push_back({s[i], s[j]});
        }
    }

    sort(begin(can), end(can));
    cout << can[n] << endl;
}
