#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    int len = s.size();
    for(int i = 0; i < len; i++){
        int check = 0;
        for(int j = i + 1; j < len; j++){
            if(s[i] == s[j]){
                check = 1;
                break;
            }
        }
        for(int k = 0; k < i; k++){
            if(s[i] == s[k]){
                check = 1;
                break;
            }
        }
        if(check == 0){
            return i;
        } 
    }
    return -1;
}

int main(){
    string s = "leetcode";
    cout<<firstUniqChar(s)<<endl;

    return 0;
}