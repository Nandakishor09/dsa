#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
        
    int len = s.length();
    int cnt = 0;

    for(int i = 0; i < t.size(); i++){
        if(t[i] == s[cnt]){
            cnt++;
        }
    }
        
    if(cnt == len) return true;
    else return false;
}

int main(){
    
    string s = "abc";
    string t = "ahbgdc";
    
    if(isSubsequence(s, t)) cout<<"True";
    else cout<<"False";
    
    return 0;
}
