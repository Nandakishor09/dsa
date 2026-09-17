#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;

    for (int i = 0; i < strs.size(); i++) {
        vector<string> sett;
        sett.push_back(strs[i]);

        vector<int> freq1(26, 0);
        for (int j = 0; j < strs[i].size(); j++) {
            freq1[strs[i][j] - 'a']++;
        }

        for (int k = i + 1; k < strs.size(); ) {
            vector<int> freq2(26, 0);
            for (int l = 0; l < strs[k].size(); l++) {
                freq2[strs[k][l] - 'a']++;
            }

            if (freq1 == freq2) {
                sett.push_back(strs[k]);
                strs.erase(strs.begin() + k);
            }
            else {
                 k++;
            }
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