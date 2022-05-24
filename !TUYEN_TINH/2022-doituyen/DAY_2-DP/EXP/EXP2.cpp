#include <iostream>
#include <vector>

using namespace std;

bool exp(int n, int s, vector<int>& arr, int sum) {
    int value = sum-s;
    if(value % 2 == 1) return false;
    value /= 2;
    if(value == 0) return true;
    arr[0] = 0;
    bool sub[n + 1][value + 1];
 
    int i;
    for (i = 0; i <= n; i++)
        sub[i][0] = true;
    for (i = 1; i <= value; i++)
        sub[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= value; j++) {
            if (j < arr[i - 1])
                sub[i][j] = sub[i - 1][j];
            if (j >= arr[i - 1])
                sub[i][j] = sub[i - 1][j]
                               || sub[i - 1][j - arr[i - 1]];
        }
    }
 
    return sub[n][value];

}

int main() {
    freopen("EXP.INP", "r", stdin);
    freopen("EXP.OUT", "w", stdout);

    int n, s, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> s;

    bool ans = exp(n, s, arr, sum);

    if(ans) cout << "Yes";
    else cout << "No";

    return 0;
}