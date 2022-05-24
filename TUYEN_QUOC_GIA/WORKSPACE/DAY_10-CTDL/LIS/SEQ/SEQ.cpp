#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <time.h>

#define int long long
#define II pair<int, int>
#define fs first
#define sc second
#define INF 9223372036854775807

int n, k;
int arr[32000];

using namespace std;

int getNum(vector<int>& v) {
    int n = v.size();
    srand(time(NULL));
 
    int index = rand() % n;
 
    int num = v[index];
 
    swap(v[index], v[n-1]);
    v.pop_back();
 
    return num;
}

void generateRandom(int n, int k) {
    freopen("SEQ.INP", "w", stdout);
    cout << n << " " << k << "\n";
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = i + 1;
    while (!v.empty()) {
        cout << getNum(v) << " ";
    }
}


void lds() {
    vector<int> seq, index(n, 1);
    seq.push_back(arr[0]);

    int mark;
    for(int i = 1; i < n; i++) {
        if(seq.back() > arr[i]) {
            seq.push_back(arr[i]);
            index[i] = seq.size();
            mark = i;
        } else {
            int ind = lower_bound(seq.begin(), seq.end(), arr[i], greater<int>()) - seq.begin();
            seq[ind] = arr[i];
            index[i] = ind + 1;
        }
        if(seq.size() == k) break;
    }

    k--;
    stack<int> st; st.push(arr[mark]);
    for(int i = mark - 1; i >= 0; i--) {
        if(index[i] == k) {
            k--;
            st.push(arr[i]);
            if(k == 0) break;
        }
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

}


void lis() {
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
        if(seq.size() == k) break;
    }


    if(seq.size() == k) {
        k--;
        stack<int> st; st.push(arr[mark]);
        for(int i = mark - 1; i >= 0; i--) {
            if(index[i] == k) {
                k--;
                st.push(arr[i]);
                if(k == 0) break;
            }
        }

        while(!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
    } else {
        lds();
    }
}


void solve() {

    freopen("SEQ.INP", "r", stdin);
    freopen("SEQ.OUT", "w", stdout);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    lis();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //generateRandom(200, 50);

    solve();

    return 0;
}