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
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    double answ = 1, anss = 0;
    for (int ai = 0; ai*a*100 <= f; ai++) {
        for (int bi = 0; ai*a*100+bi*b*100 <= f; bi++) {
            for (int ci = 0; ci*c <= (ai*a+bi*b)*e && ci*c+ai*a*100+bi*b*100 <= f; ci++) {
                for (int di = 0; ci*c+di*d <= (ai*a+bi*b)*e && ci*c+di*d+ai*a*100+bi*b*100 <= f; di++) {
                    if (anss/(answ+anss) <= (ci*c+di*d)/(ci*c+di*d+ai*a*100+bi*b*100)) {
                        answ = (ai*a*100+bi*b*100), anss = ci*c+di*d;
                    }
                }
            }
        }
    }

    cout << answ + anss << " " << anss << endl;
}
