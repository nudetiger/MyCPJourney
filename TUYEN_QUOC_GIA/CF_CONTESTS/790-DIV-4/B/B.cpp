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
    int n;
    cin >> n;

    int arr[n];
    int sum = 0, ans = 0, num = INF;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        num = min(num, arr[i]);
    }
    
    ans = sum - num * n;
    cout << ans << endl;

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("B.INP", "r", stdin);
    freopen("B.OUT", "w", stdout);

    int t;
    cin >> t;
    while (t--) solve();
    

    return 0;
}