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
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    vector<int> arr2;

    for(int i = 0; i < n; i++) {
        if(i != 0) if(arr[i] == arr[i-1]) continue;
        int ind = lower_bound(arr, arr + n, arr[i]) - arr;
        int ind2 = upper_bound(arr, arr + n, arr[i]) - arr;

        if(ind2 - ind >= k) arr2.push_back(arr[i]);
    }

    if(arr2.size() == 0) {
        cout << -1 << endl;
        return;
    }

    sort(arr2.begin(), arr2.end());

    // for(int i = 0; i < arr2.size(); i++) {
    //     cout << arr2[i] << " ";
    // }
    // cout << endl;

    int rp = arr2[0], cnt = 1, best = 1;
    int brp = arr2[0];
    for(int i = 1; i < arr2.size(); i++) {
        if(arr2[i] == arr2[i-1] + 1) {
            cnt ++;
            rp = arr2[i];
            if(cnt > best) brp = rp;
        } else {
            best = max(best, cnt);
            cnt = 1;
            rp = arr2[i];
        }
    }
    best = max(best, cnt);
 
    cout << brp - best + 1 << " " << brp << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("F.INP", "r", stdin);
    freopen("F.OUT", "w", stdout);

    int t;
    cin >> t;
    while (t--) solve();
    

    return 0;
}