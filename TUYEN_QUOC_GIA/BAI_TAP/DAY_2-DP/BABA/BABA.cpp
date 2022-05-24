#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define int long long

using namespace std;

string s;
int n;

void solve() {

    vector<int> dp(3, 0), tmp(3, 0);
    vector<vector<int>> dp2(2, vector<int>(11, 0)), tmp2(2, vector<int>(11, 0));

    int ans = 0;
    int cc = s[0] - '0';
    tmp[cc % 3] = 1;
    tmp2[1][cc] = 1;

    for (int i = 1; i < n; i++) {
        int d = s[i] - '0'; 

        for(int j = 0; j < 3; j++) {
            dp[j] = tmp[(j-d+3) % 3];
        }
        for(int j = 0; j < 11; j++) {
            dp2[1][j] = tmp2[0][(j-d+11) % 11];
            dp2[0][j] = tmp2[1][(j+d+11) % 11];
        }
        if(d == 0) {
            ans ++;
        } else {
            dp[d % 3] += 1;
            dp2[1][d] += 1;
        }
        ans += min(dp[0], dp2[0][0] + dp2[1][0]);
        tmp = dp;
        tmp2 = dp2;
        for(int x = 0; x < 11; x++) {
            cout << tmp2[0][x] << " ";
        }
        cout << endl;
        for(int x = 0; x < 11; x++) {
            cout << tmp2[1][x] << " ";
        }
        cout << endl;
        cout << endl;
    }

    cout << ans;
}

void solve1() {
    
}

void solve2() {

}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("BABA.INP", "r", stdin);
    freopen("BABA.OUT", "w", stdout);

    cin >> s;
    n = s.size();

    int f = 0;
    cin >> f;
    if(f == 1) solve();
    else solve2();

    return 0;
}