#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {

    freopen("BEADS.INP", "r", stdin);
    freopen("BEADS.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    vector<int> seq;
    int dp[n], dp2[n];
    dp[n-1] = 1; dp2[n-1] = 1;
    seq.push_back(arr[n-1]);
    for(int i = n-2; i >= 0; i--) {
        if(seq.back() < arr[i]) {
            seq.push_back(arr[i]);
            dp[i] = seq.size();
        } else {
            int ind = lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
            seq[ind] = arr[i];
            dp[i] = ind + 1;
        }
    }
    seq.clear(); seq.push_back(arr[n-1]);
    for(int i = n-2; i >= 0; i--) {
        if(seq.back() > arr[i]) {
            seq.push_back(arr[i]);
            dp2[i] = seq.size();
        } else {
            int ind = lower_bound(seq.begin(), seq.end(), arr[i], greater<int>()) - seq.begin();
            seq[ind] = arr[i];
            dp2[i] = ind + 1;
        }
    }

    int m = 1;
    for(int i = 0; i < n; i++) {
        m = max(m, dp[i] + dp2[i] - 1);
    }

    cout << m;

    return 0;
}