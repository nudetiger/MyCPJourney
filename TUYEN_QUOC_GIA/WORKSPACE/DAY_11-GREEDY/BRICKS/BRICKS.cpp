#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <climits>

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

const int SIZE = 100003;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("BRICKS.INP", "r", stdin);
    freopen("BRICKS.OUT", "w", stdout);

    int p[SIZE + 2];
    memset(p, 0, sizeof(p));
    p[0] = 1; p[1] = 1;
    for(int i = 2; i*i <= SIZE; i += 2) {
        if(i == 4) i--;
        if(p[i] == 1) continue;
        for(int j = i*i; j <= SIZE; j += i) p[j] = 1;
    }
    vector<int> ans;
    int l = 2;
    for(int i = 3; i <= SIZE; i+= 2) {
        if(p[i] == 1) continue;
        ans.push_back(l * i);
        l = i;
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << n - *(upper_bound(ans.begin(), ans.end(), n) - 1) << endl;
    }

    return 0;
}