#include<bits/stdc++.h>
using namespace std;

int main() {
    int dir, w;
    cin >> dir >> w;

    dir = (dir * 10 + 1125) / 2250 % 16;
    w = w / 6.0 + .5;

    vector<string> dirstr { "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW" };

    int wind;
    vector<int> border { 0, 3, 16, 34, 55, 80, 108, 139, 172, 208, 245, 285, 327 };
    for (int i = 12; i >= 0; i--) {
        if (w - border[i] >= 0) {
            wind = i;
            break;
        }
    }

    cout << (wind == 0 ? "C" : dirstr[dir]) << " " << wind << endl;
}
