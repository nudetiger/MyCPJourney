#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = pow(10, 9);

int fast_power(int base, int power) {
    int result = 1;
    while(power > 0) {
        if(power & 1) {
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power >>=1;
    }
    return result;  
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("BAI01.INP", "r", stdin);
    freopen("BAI01.OUT", "w", stdout);

    int a, b, n, m;

    cin >> a >> b >> n >> m;

    cout << fast_power(a, n) + fast_power(b, m);
    return 0;
}