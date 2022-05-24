#include <bits/stdc++.h>

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

int l1[100005], l2[100005];

void precompute() {

    l1[1] = 1;
    l2[1] = 1;

    int k = 2;
    int x = 1, y = 1;
    while (k < 100005) {
        l1[k] = l1[k-1] + (k-1) * 2 - 1;
        l2[k] = l2[k-1] + (k-1) * 2 + 1;
        k++;
    }
}

void solve() {
    int n;
    cin >> n;

    int l = upper_bound(l1+1, l1 + 100006, n) - l1 - 1;
    int r = lower_bound(l2+1, l2 + 100006, n) - l2;

    int mid = (l1[l] + l2[r]) / 2;

    if(n > mid) {
        cout << r << " " << l - (n-mid) << endl;
    } else if(n < mid) {
        cout << r - (mid-n) << " " << l << endl;
    } else {
        cout << r << " " << l << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);
    
    precompute();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}