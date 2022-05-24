#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

#define int long long
#define II pair<int, int>
#define fs first
#define sc second
#define INF 9223372036854775807

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("KINV.INP", "r", stdin);
    freopen("KINV.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> seq, index(n, 1 - k);
    seq.push_back(arr[0]);

    for(int i = 1; i < n; i++) {
        if(seq.back() > arr[i]) {
            seq.push_back(arr[i]);
            index[i] = seq.size() - k;
        } else {
            int ind = lower_bound(seq.begin(), seq.end(), arr[i], greater<int>()) - seq.begin();
            seq[ind] = arr[i];
            index[i] = ind + 1 - k;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        cout << index[i] << " ";
    }

    //cout << ans;


    return 0;
}