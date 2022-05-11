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
    int h = 0;
    for (int i = n; i > 0; i /= 10) h += i % 10;
    cout << (n % h == 0 ? "Yes" : "No") << endl;
}
