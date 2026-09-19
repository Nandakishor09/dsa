#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    vector<int> map1(26, 0);
    vector<int> map2(26, 0);

    for(char ch : s){
        map1[ch - 97]++;
    }
    for(char ch : t){
        map2[ch - 97]++;
    }

    for(int i = 0; i < map1.size(); i++){
        if(map1[i] == map2[i]){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    string s1 = "anagram";
    string s2 = "nagaram";

    if(isAnagram(s1, s2)){
        cout<<"Valid";
    }else{
        cout<<"Invalid";
    }

    return 0;
}