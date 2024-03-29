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
    int s;
    cin >> s;
    int l = s / 100, r = s % 100;
    bool yymm = r > 0 && r <= 12, mmyy = l > 0 && l <= 12;

    if (yymm && !mmyy) {
        cout << "YYMM" << endl;
    } else if (mmyy && !yymm) {
        cout << "MMYY" << endl;
    } else if (mmyy && yymm) {
        cout << "AMBIGUOUS" << endl;
    } else {
        cout << "NA" << endl;
    }
}
