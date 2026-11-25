#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> nums, int target) {
    
    vector<int> sortedNums;
    int index = 0;

    if(nums.size() == 1){
        if(nums[0] == target)
            return true;
        return false;
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] <= nums[i + 1]){
            continue;
        }else{
            index = i + 1;
            break;
        }
    }

    for(int i = index; i < nums.size(); i++){
        sortedNums.push_back(nums[i]);
    }

    for(int i = 0; i <= index - 1; i++){
        sortedNums.push_back(nums[i]);
    }

    for(int i = 0; i < sortedNums.size(); i++){
        cout<<sortedNums[i]<<" ";
    }
    cout<<endl;

    int left = 0;
    int right = nums.size() - 1;

    while(left <= right){
        int mid = (left + right) / 2;
        if(sortedNums[mid] == target)
            return true;
        else if(sortedNums[mid] < target)
            left = mid + 1;
        else if(sortedNums[mid] > target)
            right = mid - 1;
    }

    return false;
}

int main(){
    vector<int> arr = {2, 2, 2, 3, 2, 2, 2};
    int target = 3;

    if(search(arr, target)){
        cout<<"Found";
    }else{
        cout<<"Not Found";
    }

    return 0;
}