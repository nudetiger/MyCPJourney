#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 111539768;

int m, n, k, x, y, u, v;

int fpow(int a, int b) {

    int ans = 1;
    while(b > 0) {

        if(b & 1) {
            ans = ans * a % MOD;
            b--;
        }
        a = a * a % MOD;
        b /= 2;
    }

    return ans % MOD;
}

int cal(int a, int t) {
    if(t == 0) return 1;
    if(t == 1) return (1 + a) % MOD; 
    if(t == 2) return (cal(a, 1) + fpow(a, 2)) % MOD; 
    int ans = 0;
    if(t % 2 == 0) ans = (ans + fpow(a, t--)) % MOD;
    ans = (ans + (cal(a, t/2) * (1 + fpow(a, 1 + t/2))) % MOD ) % MOD;

    return ans;
}

int cal2(int a, int t) {
    if(t == 0) return 1;
    if(t == 1) return (1 + a) % MOD; 
    if(t == 2) return (cal2(a, 1) + fpow(a, 2)) % MOD; 
    if(t <= pow(10, 7)) return cal(a, t); 
    int ans = 0;
    if(t % 2 == 0) ans = (ans + fpow(a, t--)) % MOD;
    ans = (ans + (cal2(a, t/2) * (1 + fpow(a, 1 + t/2))) % MOD ) % MOD;

    return ans;
}

void sub() {

    int ans = 1;

    ans = cal2(k, u-x);
    ans = (ans * fpow(k, x-1)) % MOD;

    int tmp = fpow(k, m);
    ans = (ans * fpow(tmp, y-1)) % MOD;
    ans = (ans * cal2(tmp, v-y)) % MOD; 

    cout << ans << "\n";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);

    cin >> m >> n >> k >> y >> x >> v >> u;

    sub();

    //cout << cal(100, 29) - CALC(100, 29);
    
    return 0;
}