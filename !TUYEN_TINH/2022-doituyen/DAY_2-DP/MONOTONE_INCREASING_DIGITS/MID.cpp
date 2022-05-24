#include <iostream>

#define ll long long

using namespace std;

int mid(int n) {

    int i = 0;
    int d[10];
    while(n >= 10) {
        d[9-i] = n % 10;
        i++;
        n/=10;
    }
    d[9-i] = n%10;
    int s = 9-i;
    int mark = 10;
    for(i = 9; i >= s; i--) {
        if(i == s) break;
        if(d[i-1] > d[i]) {
            mark = i-1;
            d[i-1]--;
        }
    }
    n = 0;
    for(int i = s; i <= 9; i++) {
        if(i > mark) {
            n= 10*n + 9;
        } else {
            n = 10*n + d[i];
        }
    }
    return n;
}

int main() {

    freopen("MID.INP", "r", stdin);
    freopen("MID.OUT", "w", stdout);
    int n;
    cin >> n;

    int ans = mid(n);

    cout << ans;

    return 0;
}