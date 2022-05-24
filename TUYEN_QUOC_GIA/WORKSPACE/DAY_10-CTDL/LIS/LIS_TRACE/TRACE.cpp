#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

#define int long long
#define II pair<int, int>
#define fs first
#define sc second
#define INF 9223372036854775807

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("TRACE.INP", "r", stdin);
    freopen("TRACE.OUT", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> seq, index(n, 1);
    seq.push_back(arr[0]);

    int mark;
    for(int i = 1; i < n; i++) {
        if(seq.back() < arr[i]) {
            seq.push_back(arr[i]);
            index[i] = seq.size();
            mark = i;
        } else {
            int ind = lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
            seq[ind] = arr[i];
            index[i] = ind + 1;
        }
    }
    cout << seq.size() << endl;

    int m = seq.size() - 1;
    stack<int> st; st.push(arr[mark]);
    for(int i = mark - 1; i >= 0; i--) {
        if(index[i] == m) {
            m--;
            st.push(arr[i]);
            if(m == 0) break;
        }
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}