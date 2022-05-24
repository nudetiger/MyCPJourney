#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int n, m, s;

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("SUMX.INP", "r", stdin);
    freopen("SUMX.OUT", "w", stdout);

    cin >> m >> n >> s;
    vector<int> a(m), b(n);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    for(int i = 0; i < m; i++) {
        int l = lower_bound(b.begin(), b.end(), s-a[i]) - b.begin();
        int r = upper_bound(b.begin(), b.end(), s-a[i]) - b.begin();

        ans += r - l;
    }
    cout << ans;

    return 0;
}