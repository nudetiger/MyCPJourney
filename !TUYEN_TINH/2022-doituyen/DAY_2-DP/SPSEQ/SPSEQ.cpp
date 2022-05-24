#include <bits/stdc++.h>

using namespace std;

int liq(int n, int arr[]){
    int sum = 0;
    vector<int> seq, seq2, dp(n), dp2(n);
    seq.push_back(arr[0]);
    for(int i = 1; i < n; i ++) {
        if(seq.back() < arr[i]) {
            seq.push_back(arr[i]);
        } else {
            int ind = lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
            seq[ind] = arr[i];
        }
        dp[i] = seq.size();
    }
    seq2.push_back(arr[n-1]);
    for(int i = n-2; i >= 0; i--) {
        if(seq2.back() < arr[i]) {
            seq2.push_back(arr[i]);
        } else {
            int ind = lower_bound(seq2.begin(), seq2.end(), arr[i]) - seq2.begin();
            seq2[ind] = arr[i];
        }
        dp2[i] = seq2.size();
    }
    for(int i = 0; i < n; i ++) {
        // cout << dp[i] << " " << dp2[i] << "\n";
        sum = max(sum, min(dp[i], dp2[i])*2 - 1);
    }
    return sum;
}

int main() {

    freopen("SPSEQ.INP", "r", stdin);
    freopen("SPSEQ.OUT", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    int ans = liq(n, arr);
    cout << ans;
    return 0;
}