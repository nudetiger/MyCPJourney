#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("COWDICES.INP", "r", stdin);
    freopen("COWDICES.OUT", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;

    int m = 0, p = 1;
    vector<int> dp(2811, 0);

    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++){
            for(int k = 1; k <= c; k++){
                int x = i + j + k; 
                dp[x] ++;
                if(dp[x] > m) {
                    m = dp[x];
                    p = x;
                }
            }
        }
    }

    cout << p;

    return 0;
}