#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <algorithm>

#include <vector>
#include <bitset>
#include <set>
#include <string>

#define int long long
#define II pair<int, int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define LINF 9223372036854775807
#define INF 2147483648

const int SIZE = 100004;

using namespace std;

int w[102], v[102];
vector<int> dp(SIZE, INF);

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("KNAPSACK2.INP", "r", stdin);
    freopen("KNAPSACK2.OUT", "w", stdout);

    int n, c;
    cin >> n >> c;

    for(int i = 0; i < n; i++) cin >> w[i] >> v[i];

    int m = 0;

    dp[0] = 0;
    for(int i = 0; i < n; i++) 
        for(int j = SIZE - 1; j >= 0; j--) 
            if(j + v[i] <= SIZE + 100 && dp[j] + w[i] <= c) 
                dp[j + v[i]] = min(dp[j + v[i]], dp[j] + w[i]);

    for(int i = SIZE - 1; i >= 0; i--) {
        if(dp[i] <= c && dp[i] >= 0) {
            m = i;
            break;
        }
    }

    cout << m << endl;
    
    return 0;
}