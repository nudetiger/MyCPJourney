#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <deque>

#define int long long
#define II pair<int,int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define INF LLONG_MAX

using namespace std;

void solve() {

    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    deque<int> dq;
    int minRange[n - k + 1];
    for (int i = 0; i < n; ++i) { 
        while (dq.size() && arr[dq.back()] >= arr[i]) dq.pop_back();

        dq.push_back(i); 
        
        if (dq.front() + k <= i) dq.pop_front(); 
        if (i >= k-1) minRange[i - k + 1] = arr[dq.front()]; 
    }
    for(int i = 0; i < n - k + 1; i++) {
        cout << minRange[i] << " ";
    }
    cout << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("LUCVANTIEN.INP", "r", stdin);
    freopen("LUCVANTIEN.OUT", "w", stdout);

    int t;
    cin >> t;
    while (t--) solve();
    

    return 0;
}