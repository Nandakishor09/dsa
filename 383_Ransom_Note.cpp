#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int target = ransomNote.size();
    map<char, int> mpp1;
    map<char, int> mpp2;

    for(char ch : ransomNote){
        mpp1[ch]++;
    }
    for(char ch : magazine){
        mpp2[ch]++;
    }
    int sum = 0;
    for(char ch : ransomNote){
        if(mpp1[ch] <= mpp2[ch]){
            sum++;
        }else{
            return false;
        }
    }
    if(sum == target){
        return true;
    }
    return true;
}

//Better Solution
bool canConstruct(string ransomNote, string magazine) {
    vector<int>mp(26,0);
    for(char c: magazine){
        mp[c-'a']++;
    }
    for(char c: ransomNote){
        mp[c-'a']--;
        if(mp[c-'a']<0){
            return false;
        }
    }
    return true;
}

int main(){
    string s1 = "aa", s2 = "aab";
    cout<<canConstruct(s1, s2);

    return 0;
}