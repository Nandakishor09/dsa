#include <bits/stdc++.h>
using namespace std;

string toLowerCase(string s) {
    string ans = "";
    for(char ch : s){
        ch = tolower(ch);
        ans += ch;
    }
    return ans;
}

int main(){
    string s = "Hello";
    cout<<s<<"--";
    s = toLowerCase(s);
    cout<<s<<endl;

    return 0;
}