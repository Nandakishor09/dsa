#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
    stringstream split(s);
    map<string, char> mpp2;
    map<char, string> mpp1;

    if(pattern.size() == 1){
        string temp;
        split>>temp;
        mpp1.insert({pattern[0], temp});
    }
    string word;
    int i = 0;
    while(split >> word){    
        mpp1.insert({pattern[i], word});
        i++;
    }  
    
    for(auto x : mpp1) {
        mpp2[x.second] = x.first;
    } 
    i = 0;
    stringstream ss(s);
    int count = 0;
    while(ss >> word){
        count++;
        if(mpp2[word] == pattern[i] && word == mpp1[pattern[i]]){
            i++;
        }else{
            return false;
        }
    }
    if(count == pattern.size()){
        return true;
    }
    return false;
}

int main(){
    string pattern = "jquery";
    string s = "jquery";

    if(wordPattern(pattern, s)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    return 0;
}