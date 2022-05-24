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

    int arr[n]; int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int best1 = arr[0], best2 = arr[1];
    int sum1 = 0, sum2 = 0;

    for(int i = 0; i < n; i++) {
        if(i < n-1) {
            sum1 = max(arr[i], sum1 + arr[i]);
            best1 = max(best1, sum1);
        }
        if(i >= 1) {
            sum2 = max(arr[i], sum2 + arr[i]);
            best2 = max(best2, sum2);
        }
    }

    if(sum > max(best1, best2)) cout << "YES" << endl;
    else cout << "NO" << endl;

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