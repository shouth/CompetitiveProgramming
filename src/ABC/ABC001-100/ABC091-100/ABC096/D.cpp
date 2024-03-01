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

bool is_prime(int x) {
    bool res = true;
    for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) res = false;
    return res;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0, j = 0; i < n; i++, j++) {
        while (!is_prime(j*5+2)) j++;
        cout << j*5+2 << " ";
    }
}
