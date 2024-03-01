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
    double n, k;
    cin >> n >> k;
    cout << fixed
         << setprecision(15)
         << ((k-1) * (n-k) * 6 + (n-1) * 3 + 1) / (n * n * n)
         << endl;
}
