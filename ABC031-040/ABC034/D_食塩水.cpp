#include<bits/stdc++.h>
using namespace std;

using pdouble = pair<double, double>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pdouble> wp(n);
    for (auto& e : wp) cin >> e.first >> e.second;
    
    double left = 0, right = 100;
    for (double i = 0; i < 100; i++) {
        double middle = (left + right) / 2;
        sort(begin(wp), end(wp), [&](pdouble a, pdouble b) {
            double ad = a.first * (a.second - middle) / 100;
            double bd = b.first * (b.second - middle) / 100;
            return ad > bd;
        });

        double salt = 0, solution = 0;
        for (int j = 0; j < k; j++) {
            solution += wp[j].first;
            salt += wp[j].first * wp[j].second / 100;
        }
        (salt / solution * 100 > middle ? left : right) = middle;
    }
    
    cout << fixed << setprecision(10) << right << endl;
}

