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
    int sum = 0;
    for (int m = n; m != 0; m /= 10) sum += m % 10;
    cout << (n % sum == 0 ? "Yes" : "No") << endl;
}
