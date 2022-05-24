#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>

#define int long long
#define bs bitset<20>
#define INF 9223372036854775807

using namespace std;

int ans = 0;

void check(int n) {

    vector<int> v;
    while (n % 2 == 0) {
        v.push_back(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            v.push_back(i);
            n = n/i;
        }
    }
        if (n > 2) v.push_back(n);

        return v;

}

int v(int n) {
    if(n < 10) return n;

    int ans = 0;
    while(n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return v(ans);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("ROOTS.INP", "r", stdin);
    freopen("ROOTS.OUT", "w", stdout);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        check(n);
    }

    cout << ans;
    
    return 0;
}