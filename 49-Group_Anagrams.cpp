#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    for(int i = 0; i < strs.size(); i++){
        int check = 0;
        vector<char> chars;
        vector<string> sett;
        int cnt1 = 0;
        /*if(strs[i].size() == 0){
            sett.push_back(strs[i]);
            ans.push_back(sett);
            continue;
        }*/
        for(int j = 0; j < strs[i].size(); j++){
            chars.push_back(strs[i][j]);
            cnt1++;
        }
        for(int k = i + 1; k < strs.size(); k++){
            int check = 0;
            int cnt2 = 0;
            for(int l = 0; l < strs[k].size(); l++){
                for(int ii = 0; ii < chars.size(); ii++){
                    if(strs[k][l] == chars[ii]){
                        cnt2++;
                        break;
                    }
                }
            }
            if(cnt1 == cnt2){
                sett.push_back(strs[k]);
                strs.erase(strs.begin() + k);
                check = 1;
            }
        }
        if(check == 0){
            sett.push_back(strs[i]);
        }
        ans.push_back(sett);
    }
    return ans;
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}