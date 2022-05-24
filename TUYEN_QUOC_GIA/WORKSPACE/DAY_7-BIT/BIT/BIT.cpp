#include <iostream>
#include <vector>

using namespace std;

struct BIT {
    int n, *bit1, *bit2;

    int get(int b[], int i){
        int sum = 0;
        i++;
        while (i > 0) {
            sum += b[i];
            i -= i & (-i);
        }
        return sum;
    }

    void update(int b[], int i, int val) {
        i = i + 1;
        while (i <= n) {
            b[i] += val;
            i += i & (-i);
        }
    }

    void updateRange(int l, int r, int value) {
        update(bit1, l, value);
        update(bit1, r + 1, -value);
        update(bit2, l, value * (l - 1));
        update(bit2, r + 1, -value * r);
    }

    int sum(int x) {
        return (get(bit1, x) * x) - get(bit2, x);
    }

    int range(int l, int r) {
        return sum(r) - sum(l - 1);
    }


    BIT(int n, int *arr) {
        this->n = n + 1;
        bit1 = new int[n + 1];
        bit2 = new int[n + 2];

        bit2[n+1] = 0;
        for (int i = 0; i <= n + 1; i++) {
            bit1[i] = bit2[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            updateRange(i, i, arr[i]);
        }
    }

};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("BIT.INP", "r", stdin);
    freopen("BIT.OUT", "w", stdout);

    int n;
    cin >> n;
    
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    
    BIT tree = BIT(n, arr);

    for(int i = 1; i < n; i++) cout << tree.range(i, i+1) << " ";
    
    return 0;
}