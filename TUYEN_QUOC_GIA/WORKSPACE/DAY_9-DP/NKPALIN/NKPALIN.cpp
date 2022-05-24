#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

#define MAX_N 2022
#define int long long

using namespace std;


string s;
int mark[MAX_N], dp[MAX_N][MAX_N];
int n;

void count(int i,int j) {

    if (i > j) return;
    if (dp[i][j] != 0) return;

    if (i == j) {
        dp[i][j] = 1;
        return;
    }     
    if (s[i - 1] == s[j - 1]) {

        if (j - i == 1) {
            dp[i][j]=2;
            return;
        }

        if (dp[i + 1][j - 1] == 0) count(i + 1, j - 1);

        dp[i][j] = dp[i + 1][j - 1] + 2;

    } else {
        if (dp[i + 1][j] == 0) count(i + 1, j);
        if (dp[i][j - 1] == 0) count(i, j - 1);
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    }

    return;
}

void calc(void) {
    int i, j;     
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++) count(i, j);     
}

void trace(void) {
    
    int i = 1, j = n;
    while (i <= j){
        if (s[i - 1] == s[j - 1]) {
            mark[i++] = 1;
            mark[j--] = 1;
        } else {
            if (dp[i][j] == dp[i + 1][j]) i++;
            else j--;                    
        }
    }

    for (i = 1; i <= n; i++)
        if(mark[i]) cout << s[i-1];

    return;
}

void solve() {

    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; i++) mark[i] = 0;
    calc();
    trace();
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("NKPALIN.INP", "r", stdin);
    freopen("NKPALIN.OUT", "w", stdout);

    solve();

    return 0;
}