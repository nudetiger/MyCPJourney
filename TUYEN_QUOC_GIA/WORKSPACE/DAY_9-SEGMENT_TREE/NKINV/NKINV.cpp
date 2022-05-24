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
    
    freopen("NKINV.INP", "r", stdin);
    freopen("NKINV.OUT", "w", stdout);

    int n, x, ans = 0;
    cin >> n;
    int f[60600];

    while (n--)
    {
        cin >> x;
        for (int i = x + 1; i <= 60000; i += (i&-i)) ans += f[i];
        for (int i = x; i; i -= (i & -i)) f[i]++;   
    }

    cout << ans << endl;
    return 0;
}