#include<bits/stdc++.h>
using namespace std;

int main() {
    int w, h;
    cin >> w >> h;
    cout << (w/(w-h) == 4 ? "4:3" : "16:9") << endl;
}
