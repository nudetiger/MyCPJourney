#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <algorithm>

#define int long long
#define II pair<int, int>
#define DD pair<double, double>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define INF 9223372036854775807

using namespace std;

int n, k;
DD x[100001], cd[100001];

bool canBuild(int t) {
    for(int i = 0; i < n; i++) {
        cd[i].sc = x[i].fs - t/2/x[i].sc;
        cd[i].fs = x[i].fs + t/2/x[i].sc;
    }
    sort(cd, cd + n);

    int ans = 1;
    int u = cd[0].fs;
    for(int i = 1; i < n; i++) {
        if(cd[i].sc > u) {
            ans ++;
            u = cd[i].fs;
        }
        if(ans > k) return false;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("B.INP", "r", stdin);
    freopen("B.OUT", "w", stdout);

    cin >> n >> k;
    
    int i;
    for (i = 0; i < n; i++) cin >> x[i].fs;
    for (i = 0; i < n; i++) cin >> x[i].sc;

    int l = 0, r = 100000, mid;
    while(!canBuild(r)) l = r, r *= 2;
    while(r - l > 1) {
        mid = (l + r) / 2;
        if(canBuild(mid)) r = mid;
        else l = mid;
    }

    cout << r << endl;

    return 0;
}