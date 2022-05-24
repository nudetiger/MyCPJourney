#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int check(int n, vector<pii>& t) {

    // int m = 1;

    // for(int i = 0; i < n; i ++) {
    //     for(int j = 0; j < i; j++) {
    //         if(t[i].first > t[j].second && dp[j] >= dp[i]) {
    //             dp[i] = dp[j] + 1;
    //             m = max(m, dp[i]);
    //         }
    //     }
    // }

    // return m;

    vector<int> seq;
    seq.push_back(t[0].second);

    for(int i = 0; i < n; i ++) {
        if(seq.back() < t[i].first) {
            seq.push_back(t[i].second);
        } else {
            int ind = lower_bound(seq.begin(), seq.end(), t[i].first) - seq.begin();
            if(seq[ind] > t[i].second)
                seq[ind] = t[i].second;
        }
    }

    return seq.size();
}

int main() {

    freopen("LUNARG.INP", "r", stdin);
    freopen("LUNARG.OUT", "w", stdout);
    
    int n;
    cin >> n;
    vector<pii> inp(n);
    vector<pii> t;
    int a,b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        inp[i] = make_pair(a, b);
    }

    sort(inp.begin(), inp.end());
    t.push_back(inp[0]);
    for(int i = 1; i < n; i ++) {
        if(inp[i].first != inp[i-1].first) t.push_back(inp[i]);
    }
    int ans = check(t.size(), t);
    cout << ans;

    return 0;
}