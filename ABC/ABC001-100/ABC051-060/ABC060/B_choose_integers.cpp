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
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 2; a * i % b != a % b; i++) {
        if (a * i % b == c) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
