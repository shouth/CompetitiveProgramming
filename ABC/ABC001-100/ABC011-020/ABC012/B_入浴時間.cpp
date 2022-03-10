#include<bits/stdc++.h>
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
