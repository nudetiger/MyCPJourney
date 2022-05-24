#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("TIMOVI.INP", "r", stdin);
    freopen("TIMOVI.OUT", "w", stdout);

    int n, k, m;
    cin >> n >> k >> m;

    vector<int> arr(n, 0);

    int f = m/k;
    int f2 = m%k;

    if(f <= n) {
        if(f == n) {
            arr[n-2] += f2;
        }
        for(int i = 0; i < n; i ++) {
            if(i < f) arr[i] += k;
            if(i == f) arr[i] += f2;            
            cout << arr[i] << " ";
        }
        return 0;
    }
    f = f-n;
    int a = f/(n-1);

    for(int i = 1; i < n-1; i++) {
        arr[i] += k*(a+1);
    }
    arr[n-1] += k; arr[0] += k;
    arr[n-1] += k*(a/2);
    if(a > 0) arr[0] += k*((a-1)/2 + 1);
    f = f % (n-1);
    if(a % 2 == 0) {
        for(int i = n-2; i >= n-1-f; i--) {
            arr[i] += k;
        }
        arr[n-2-f] += f2;
    } else {
        for(int i = 1; i <= f; i++) {
            arr[i] += k;
        }
        arr[f+1] += f2;
    }


    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}