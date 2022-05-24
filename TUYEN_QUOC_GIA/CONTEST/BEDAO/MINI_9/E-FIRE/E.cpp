#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>

#define int long long
#define II pair<int, int>
#define III pair<int, pair<int, int>>
#define DI pair<double, int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define LINF 9223372036854775807
#define INF 2147483647

using namespace std;

const int SIZE = 1000002;
const int MOD = 1000000007;

int fac[SIZE], ifac[SIZE];

int fpow(int a, int n){
	int ret = 1;
	while (n){
		if (n & 1) ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		n /= 2;
	}
	return ret % MOD;
}

inline void precompute(int MAX_N){
	int i;
	fac[0] = 1;
	for (i = 1; i < MAX_N; i++){
		fac[i] = (i * fac[i - 1]) % MOD;
	}
	ifac[MAX_N - 1] = fpow(fac[MAX_N - 1], MOD - 2);
	for (i = MAX_N - 2; i >= 0; i--){
		ifac[i] = ((i + 1) * ifac[i + 1]) % MOD;
	}
}

int cmb(int n, int r){
	int ret = fac[n] % MOD;
	ret = (ret * ifac[r]) % MOD;
	ret = (ret * ifac[n - r]) % MOD;
	return ret;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("E.INP", "r", stdin);
    freopen("E.OUT", "w", stdout);

    int a, b, q;
    cin >> a >> b >> q;
    precompute(max(a, b) + 2);

    
    int f = min(a, b);
    int pre[f + 2];

    pre[0] = 1;
    for(int i = 1; i <= f; i++) {
        pre[i] = ((cmb(a, a-i) * cmb(b, i)) % MOD + pre[i-1]) % MOD;
    }
    pre[f+1] = pre[f];    

    int x, t;
    while(q --) {
        cin >> x >> t;
        int fp = min(x + t, f+1);
        int sp = x - t;

        int ans = pre[f];
        if(fp >= 0) ans = (ans - (pre[fp] % MOD) + MOD) % MOD;
        if(sp >= 1) ans = (ans + pre[sp-1]) % MOD;
        cout << ans << endl;
    }

    return 0;
}