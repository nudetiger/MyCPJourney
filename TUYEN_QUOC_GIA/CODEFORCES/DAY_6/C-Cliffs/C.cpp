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

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int m = INF, p = 1;
    for(int i = 1; i < n; i++) {
        int t = arr[i] - arr[i - 1];
        if(t < m) {
            m = t;
            p = i;
        }
    }  
    
    cout << arr[p-1] << " ";
    for(int i = p + 1; i < n; i++) {
        cout << arr[i] << " ";
    }
    for(int i = 0; i < p-1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[p] << endl;
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