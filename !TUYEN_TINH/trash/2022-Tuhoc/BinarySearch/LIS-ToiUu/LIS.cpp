#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll lis(int n, ll arr[]) {

    vector<int> seq;

    seq.push_back(arr[0]);

    for(int i = 0; i < n; i ++) {
        // if(seq.back() <= arr[i]) {
        if(seq.back() < arr[i]) {
            seq.push_back(arr[i]);
        } else {

            // int ind = upper_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
            int ind = lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
            seq[ind] = arr[i];
        }
    }
    return seq.size();
}

int main() {
    freopen("LIS.INP", "r", stdin);

    int n;
    cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    ll ans = lis(n, arr);
    cout << ans << "\n";

    return 0;
}