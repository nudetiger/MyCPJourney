#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <climits>

#include <vector>
#include <map>
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

map<int, bool> pass;
map<int, int> num;

int n;

int len(int x) {
    int cnt = 0;
    while (x > 0) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int backtrack(int x) {
    if(pass[x]) return num[x];
    pass[x] = 1;

    if(len(x) == n) return 0;

    int l = x;
    int ans = 50;
    while(l > 0) {
        if(l % 10 > 1) ans = min(ans, backtrack(x * (l % 10)) + 1);
        l /= 10;
    }

    num[x] = ans;
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);

    int x;
    cin >> n >> x;
    
    int ans = backtrack(x);

    if(ans == 50) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}