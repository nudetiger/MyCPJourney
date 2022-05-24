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
#define DD pair<double, double>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define INF 9223372036854775807
 
using namespace std;
 
int n, k;
double x[100005], a[100005];
 
bool canBuild(int t) {
    DD cd[n+2];
    for(int i = 0; i < n; i++) {
        cd[i].sc = x[i] - t/2/a[i];
        cd[i].fs = x[i] + t/2/a[i];
    }
    sort(cd, cd + n);
 
    int ans = 1;
    int u = cd[0].fs;
    for(int i = 1; i < n; i++) {
        if(cd[i].sc > u) {
            ans ++;
            u = cd[i].fs;
        }
        if(ans > k) return false;
    }
    return true;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    int h[i];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    II p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i].fs >> p[i].sc;
    }
    
    return 0;
}