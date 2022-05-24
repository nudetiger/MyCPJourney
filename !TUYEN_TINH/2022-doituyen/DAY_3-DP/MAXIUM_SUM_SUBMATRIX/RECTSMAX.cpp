#include <iostream>
#include <vector>

using namespace std;

int kadane(vector<int>& v) {
    int cur_sum = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        cur_sum += v[i];
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
        }
        if (cur_sum < 0) {
            cur_sum = 0;
        }
    }
    return max_sum;
}

void maxSubmatrixSum(vector<vector<int>>& matrix) {
   
    int r = matrix.size();
    int c = matrix[0].size();
 
    int prefix[r][c];
 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            prefix[i][j] = 0;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (j == 0)
                prefix[i][j] = matrix[i][j];
            else
                prefix[i][j] = matrix[i][j] + prefix[i][j - 1];
        }
    }
 
    int max_sum = INT_MIN;
 
    for (int i = 0; i < c; i++) {
        for (int j = i; j < c; j++) {
            vector<int> v;
            for (int k = 0; k < r; k++) {
                int el = 0;
                if (i == 0)
                    el = prefix[k][j];
                else
                    el = prefix[k][j] - prefix[k][i - 1];
                v.push_back(el);
            }
            max_sum = max(max_sum, kadane(v));
        }
    }
    cout << max_sum;
}


int main() {

    freopen("RECTSMAX.INP", "r", stdin);
    freopen("RECTSMAX.OUT", "w", stdout);

    int m, n, i, j;
    cin >> m >> n;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            cin >> matrix[j][i];
        }
    }

    maxSubmatrixSum(matrix);

    return 0;
}