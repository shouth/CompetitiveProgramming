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
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        generate_n(back_inserter(ans), a, [&]() { return i; });
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << (i % 2 == 0 ? ans[i*w+j] : ans[i*w+(w-j-1)]) << " ";
        }
        cout << endl;
    }
}
