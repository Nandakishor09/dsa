#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
        
    int maxi = 0;
    int cnt = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
                cnt++;
        }
        else{
            maxi = max(maxi, cnt);
            cnt = 0;
        }
    }
    maxi = max(maxi, cnt);
    
    return maxi;
}

int main(){
    
    vector<int> arr = {1,1,0,1,1,1};
    
    cout<<findMaxConsecutiveOnes(arr);
    
    return 0;
}