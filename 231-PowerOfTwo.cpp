#include <bits/stdc++.h>
using namespace std;

int powerTwo(int num, int n){

    if(pow(2, num) == n) return 1;
    if(pow(2, num) > n) return 0;
    num++;
    return powerTwo(num, n);
}

bool isPowerOfTwo(int n) {
        
    if(powerTwo(0, n)) return true;
    else return false;
}

int main(){
    
    if(isPowerOfTwo(8)) cout<<"True";
    else cout<<"False";
    
    return 0;
}
