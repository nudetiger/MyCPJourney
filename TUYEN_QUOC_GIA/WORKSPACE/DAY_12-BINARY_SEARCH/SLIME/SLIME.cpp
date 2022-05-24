#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <ctime>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>

#define int long long
#define II pair<int, int>
#define III pair<int, pair<int, int>>
#define DI pair<double, int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define LINF 9223372036854775807
#define INF 2147483647

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("SLIME.INP", "r", stdin);
    freopen("SLIME.OUT", "w", stdout);

    int dp[2006], a[2006], v[2006];
    
    /* Khoi tao, tim vi tri phan tu nho nhat */

    int n, x;
    int m = INF, pos;
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < m) {
            m = a[i];
            pos = i;
        }
    }


    /*
    *   Xoay mang A sao cho phan tu nho nhat nam o vi tri dau tien
    *   VD:  4 5 6 1 2 3
    *   --> 1 2 3 4 5 6
    */
    for(int i = pos; i < n; i++) v[i - pos] = a[i];
    for(int i = 0; i < pos; i++) v[n - pos + i] = a[i];


    /*  Quy hoach dong
    *   dp[i] la gia tri nho nhat de tao ra cac cuc slime tinh den
    *   vi tri thu i cua mang V (mang A sau khi xoay)
    *   
    *   Co 2 truong hop de tao them mot cuc slime o vi tri thu i:
    *   1. Bien doi tat ca cuc slime hien co, tao ra them mot cuc slime
    *   o vi tri dau tien
    *   2. Tao ra them mot cuc slime o vi tri thu i
    * 
    *   => Cong thuc: dp[i] = min(dp[i-1] + x + v[0], dp[i-1] + v[i]);
    *   Dap an la dp[n-1] (vi tri cuoi cung cua mang)
    */

    dp[0] = v[0];
    for(int i = 1; i < n; i++) 
        dp[i] = min(dp[i-1] + v[i], dp[i-1] + x + v[0]);
        
    cout << dp[n-1] << endl;

    return 0;
}