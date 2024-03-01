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
    map<int, int> m;
    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        m[n]++;
    }
    cout << (m.size() == 2 ? "Yes" : "No") << endl;
}
