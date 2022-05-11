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
    int n, k;
    cin >> n >> k;
    vector<int> vp(n+1);
    for(int i=1; i<=n; i++) {
        int tmp = 1;
        while (tmp * i < k) {
            tmp *= 2;
        }
        vp[i] = tmp;
    }
    int mother = *max_element(vp.begin(), vp.end()), child = 0;
    for(int i=1; i<=n; i++) {
        child += mother / vp[i];
    }
    cout << fixed << setprecision(12) << (double) child / (double) (mother * n) << endl;
}
