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
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    cout << string(ty-sy, 'U')
         << string(tx-sx, 'R')
         << string(ty-sy, 'D')
         << string(tx-sx, 'L')
         << 'L'
         << string(ty-sy+1, 'U')
         << string(tx-sx+1, 'R')
         << 'D'
         << 'R'
         << string(ty-sy+1, 'D')
         << string(tx-sx+1, 'L')
         << 'U'
         << endl;
}
