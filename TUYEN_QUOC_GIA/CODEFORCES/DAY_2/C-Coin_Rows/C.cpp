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

void solve() {
    
    int m;
    cin >> m;

    int arr[m + 2];
    int pre2[m + 2], suf[m + 2];
    
    for(int i = 1; i <= m; i++) cin >> arr[i];

    suf[m+1] = 0;
    for(int i = m; i >= 2; i--) {
        suf[i] = suf[i+1] + arr[i];
    }

    pre2[0] = 0;
    for(int i = 1; i <= m-1; i++) {
        cin >> arr[i];
        pre2[i] = pre2[i-1] + arr[i];
    }
    cin >> arr[m];

    int mm = INF;
    for(int i = 0; i <= m-1; i++) {
        mm = min(mm, max(pre2[i], suf[i+2]));
    }

    cout << mm << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);

    int t;
    cin >> t;
    while (t--) solve();
    

    return 0;
}