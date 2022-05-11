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
    int n, l;
    cin >> n >> l;
    cout << n*l + n*(n-1)/2 - (l>0)*l - (l+n-1<0)*(l+n-1) << endl;
}
