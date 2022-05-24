#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
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



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("TELEFONI.INP", "r", stdin);
    freopen("TELEFONI.OUT", "w", stdout);

    int n, k;

    cin >> n >> k;
    int s[n+1];

    int l = INF, tl = 0;

    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == 1) {
            l = i;
            tl ++;
        }
    }

    if(tl == 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << tl << endl;

    int f = k, ans = 0;
    for(int i = l; i < n; i++) {
        if(s[i] == 1) {
            f = k;
            tl--;
            if(tl == 0) break;
        }
        if(f == 0) {
            ans ++;
            f = k;
        }
        f--;
    }

    cout << ans << endl;

    return 0;
}