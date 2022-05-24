#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int32_t main() {

    freopen("PS.INP", "r", stdin);
    freopen("PS.OUT", "w", stdout);

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> arr(n+2), pre(n+2, 0);

    pre[0] = 0;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    int a, b, c;

    for(int i = 0; i < k; i ++) {
        cin >> a >> b >> c;
        pre[a] += c; pre[b+1] -= c;
    }
    for(int i = 1; i <= n; i++) pre[i] += pre[i-1];
    for(int i = 1; i <= n; i++) pre[i] += pre[i-1] + arr[i];
    
    for(int i = 1; i <= n; i++) cout << pre[i] << " ";
    cout << endl;

    for(int i = 1; i <= q; i++) {
        cin >> a >> b;
        cout << pre[b] - pre[a-1] << "\n";
    }

    return 0;
}