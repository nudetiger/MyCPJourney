#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>

#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <bitset>
#include <set>
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
    
    freopen("B.INP", "r", stdin);
    freopen("B.OUT", "w", stdout);

    int n, k;

    cin >> n >> k;

    int arr[n];
    map<int, int> pick;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    int ans = 0; 
    for(int i = 0; i < k; i++) {
        if(pick.find(arr[i]) == pick.end()) {
            pick[arr[i]] = 1;
            ans ++;
        } else pick[arr[i]] ++;
    }

    int mm = ans;
    for(int i = k; i < n; i++) {
        pick[arr[i-k]] --;
        if(pick[arr[i-k]] == 0) ans --;
        if(pick.find(arr[i]) == pick.end()) {
            pick[arr[i]] = 1;
            ans ++;
            mm = max(mm, ans);
        } else pick[arr[i]] ++;
    }
    
    cout << mm;

    return 0;
}