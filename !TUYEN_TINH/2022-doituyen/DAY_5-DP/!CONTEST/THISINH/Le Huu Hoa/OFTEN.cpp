#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;

int32_t main() {

    freopen("OFTEN.INP", "r", stdin);
    freopen("OFTEN.OUT", "w", stdout);

    cin >> n;
    int arr[n];
    int m = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i == 1) arr[i] = max(arr[i-1], arr[i]);
        if(i == 2) arr[i] = max(arr[i-2] + arr[i], arr[i-1]);
        if(i >= 3) {
            arr[i] = max(arr[i-2], arr[i-3]) + arr[i];
            m = max(arr[i], m);
        }
    }

    cout << m;
    return 0;
}