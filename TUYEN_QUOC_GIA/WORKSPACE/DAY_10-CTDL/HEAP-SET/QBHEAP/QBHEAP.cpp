#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>

#include <iterator>

#include <vector>
#include <set>
#include <queue>
#include <map>

#define int long long
#define INF 2147483647 

using namespace std;

char s[100000];

int32_t main() {

    freopen("QBHEAP.INP", "r", stdin);
    freopen("QBHEAP.OUT", "w", stdout);

    priority_queue<int> qu;

    while(gets(s) != NULL) {
        if( s[0] == '-' ) {
            if(!qu.empty()) {
                int mx = qu.top();
                while(!qu.empty() && qu.top() == mx) qu.pop();
            }
        } else if(qu.size() < 15000) {
            qu.push(atoi(s+1));
        }
    }

    vector<int> res;
    int prev = INT_MAX;
    for(;!qu.empty(); qu.pop()) {
        if(qu.top() != prev)
        res.push_back(prev = qu.top());
    }

    printf("%d\n", res.size());
    for(vector<int>::iterator it = res.begin(); it != res.end(); it++)
        printf("%d\n", *it);
    return 0;
}