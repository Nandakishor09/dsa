#include <bits/stdc++.h>
using namespace std;

bool canAliceWin(int n) {
    if(n < 10)
        return false;
    
    int alice = 1;
    int ten = 10;

    while(true){
        n = n - ten;
        if(n >= ten - 1){
            ten--;
            alice++;
        }else{
            break;
        }
    }

    if(alice % 2 != 0)
        return true;

    return false;

}

int main(){
    int n = 12;
    if(canAliceWin(n)){
        cout<<"Can Win...."<<endl;
    }else{
        cout<<"Can Not Win...."<<endl;
    }

    return 0;
}