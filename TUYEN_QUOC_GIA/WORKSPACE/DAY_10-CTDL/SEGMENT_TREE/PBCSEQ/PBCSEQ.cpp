#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define int long long
#define II pair<int, int>
#define fs first
#define sc second
#define INF 9223372036854775807

using namespace std;

bool cmp(II a, II b) {
    if(b.fs >= a.fs && a.sc >= b.sc) return true;
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("PBCSEQ.INP", "r", stdin);
    freopen("PBCSEQ.OUT", "w", stdout);

    int n;
    cin >> n;
    II arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i].fs >> arr[i].sc;
    }
    
    vector<II> seq;
    seq.push_back(arr[0]);

    for(int i = 1; i < n; i++) {

        if(cmp(seq.back(), arr[i])) seq.push_back(arr[i]);
        else {
            int ind = lower_bound(seq.begin(), seq.end(), arr[i], cmp) - seq.begin();
            seq[ind] = arr[i];
        }

    }

    cout << seq.size() << endl;

    return 0;
}