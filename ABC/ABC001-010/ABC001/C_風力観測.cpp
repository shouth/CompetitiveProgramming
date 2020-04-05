#include<bits/stdc++.h>
using namespace std;

int main() {
    int deg, dis;
    cin >> deg >> dis;

    deg = (deg * 10 + 1125) / 2250 % 16;
    dis = dis / 6.0 + .5;

    vector<string> dir { "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW" };

    vector<int> border { 327, 285, 245, 208, 172, 139, 108, 80, 55, 34, 16, 3, 0 };
    auto itr = lower_bound(begin(border), end(border), dis, greater<>());
    int w = end(border) - itr - 1;

    cout << (w == 0 ? "C" : dir[deg]) << " " << w << endl;
}
