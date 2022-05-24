#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
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



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);

    int n;
    string s;
    cin >> n;
    cin >> s;

    int cnt = 0, c = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == ')') {
            c --;
            if(c < 0) {
                cnt += c;
                c = 0;
            }
        } else {
            c++;
        }
    }

    string s1 = "", s2 = "";
    for(int i = 0; i < abs(cnt); i++) s1 += "(";
    for(int i = 0; i < c; i++) s2 += ")";
    
    s = s1 + s + s2;

    cout << s;

    return 0;
}