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
    scanf("%d", &n);
    int h, m, s;
    s = n % 60, n /= 60;
    m = n % 60, n /= 60;
    h = n;
    printf("%02d:%02d:%02d", h, m, s);
}
