#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define int long long
#define INF 9223372036854775807

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("NKSEQ.INP", "r", stdin);
    freopen("NKSEQ.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n+2), pre(n+2, 0);

    pre[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[i] = pre[i-1] + arr[i];
    }
    int mark = 0, ans = 0;

    for(int i = 1; i <= n; i++) {
        if(pre[i] < 0) {
            if(pre[i-1] - pre[mark] + arr[i]> 0) {
                ans ++;
                continue;
            }
            ans = 0;
            mark = i;
            continue;
        }

        if(mark == 0) {
            ans ++;
        } else {
            if(pre[n] - pre[i-1] + pre[mark] > 0) {
                ans ++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}