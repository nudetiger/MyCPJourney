#include <bits/stdc++.h>

#define int long long

using namespace std;

const int SIZE = pow(10, 6) + 5;

int arr[SIZE];

int isPrime(int number) {
    int lll = sqrt(number);
    for(int i = 2; i <= lll; i++){
        if(number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int isSuperPrime(int number) {
    while(number > 0) {
        if(!isPrime(number)) return 0;
        number /= 10;
    }
    return 1;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("BAI02.INP", "r", stdin);
    freopen("BAI02.OUT", "w", stdout);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << isSuperPrime(arr[5]);   
    return 0;
}