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

int arr[500005], cnt[500005];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("NOW.INP", "r", stdin);
    freopen("NOW.OUT", "w", stdout);

    int n;
    cin >> n;

    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum % 3 != 0 || n < 3) {
        cout << 0 << "\n";
    } else {
        sum /= 3;

        int ss = 0;

        for(int i = n-1; i >= 0 ; i--) {
            ss += arr[i];
            if (ss == sum) cnt[i] = 1;
        }
        for(int i = n-2 ; i >= 0 ; i--) cnt[i] += cnt[i+1];
        
        int ans = 0;
        ss = 0;
        for(int i = 0 ; i+2 < n ; i++) {
            ss += arr[i];
            if (ss == sum)  ans += cnt[i+2];
        }
        cout << ans << "\n";
    }

    return 0;
}