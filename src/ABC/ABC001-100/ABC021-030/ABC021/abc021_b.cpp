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
    int a, b;
    cin >> a >> b;
    int k;
    cin >> k;
    map<int, int> count;
    count[a]++, count[b]++;
    string ans = "YES";
    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        if (count[p]++) ans = "NO";
    }

    cout << ans << endl;
}
