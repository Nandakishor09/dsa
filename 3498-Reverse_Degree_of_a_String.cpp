#include <bits/stdc++.h>
using namespace std;

int reverseDegree(string s) {
    int sum = 0;
    int i = 1;
    int a = 26;
    for(char ch : s){
        int val1 = ch - 97;
        int val2 = a - val1;
        sum += val2 * i;
        i++;
    }
    return sum;
}

int main(){
    string s = "abc";
    cout<<reverseDegree(s)<<endl;

    return 0;
}