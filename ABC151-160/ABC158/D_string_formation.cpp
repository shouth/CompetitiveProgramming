#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    string s;
    cin >> s;
    deque<char> dq(begin(s), end(s));
    i32 q;
    cin >> q;

    bool rev = false;
    for (i32 i = 0; i < q; i++) {
        i32 t;
        cin >> t;
        switch (t) {
        case 1:
            rev = !rev;
            break;
        case 2:
            i32 f;
            char c;
            cin >> f >> c;
            rev ^ (f == 1) ? dq.push_front(c) : dq.push_back(c);
            break;
        }
    }

    cout << (rev ? string(rbegin(dq), rend(dq)) : string(begin(dq), end(dq))) << endl;
}
