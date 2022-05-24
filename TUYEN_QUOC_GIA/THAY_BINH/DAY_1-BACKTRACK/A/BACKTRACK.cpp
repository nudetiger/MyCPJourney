#include <iostream>
#include <algorithm>

using namespace std;

void thu(int k, int& x[]){

    if(k > n) {
        xuly();
        return;
    }
    for(int i = 0; i <= 1; i ++) {
        x[k] = i;
        thu(k+1);
    }
}
void xuly() {

}

int main(){

    thu(1);

    return 0;
}