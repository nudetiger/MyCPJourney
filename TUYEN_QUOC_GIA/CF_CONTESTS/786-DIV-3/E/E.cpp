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
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("E.INP", "r", stdin);
    freopen("E.OUT", "w", stdout);

    int n;
    cin >> n;
 
    int arr[n+2];
    int m = INF, m2 = INF;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if(arr[i] < m) {
            m2 = m;
            m = arr[i];
        } else if(arr[i] < m2) {
            m2 = arr[i];
        }
    }
    int ans = (m+1)/2 + (m2+1)/2;
    for(int i = 2; i <= n; i++) {
        int f = max(arr[i], arr[i-1]);
        int f2 = min(arr[i], arr[i-1]);

        if(f >= 2 * f2) ans = min(ans, (f+1)/2);
        else ans = min(ans, (f + f2 + 2) / 3);
    }
 
    for(int i = 1; i <= n-2; i++) {
        ans = min(ans, (arr[i] + arr[i+2] + 1) / 2);
        ans = min(ans, max(arr[i], arr[i+2]));
    }
 
    cout << ans << endl;
 
    return 0;
}