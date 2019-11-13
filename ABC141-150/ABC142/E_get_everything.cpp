#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> box(1 << (n-1));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int index = 0;
        for (int j = 0; j < b; j++) {
            int c;
            cin >> c;
            index += 1 << (c-1);
        }

        box[index] = min(a, box[index]);
    }

    
}
