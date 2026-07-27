#include <bits/stdc++.h>
using namespace std;

//Dutch National Flag Algorithm
//TC -- O(N)
//Uses 3 pointers
//if mid == 0, swap low and mid, and move both low and mid by one postion
//if mid == 1, move mid by one postion
//if mid == 2, swap mid and high, and decrease high by one postion

void sortColors(vector<int>& nums) {
        
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else if(nums[mid] == 2){
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main(){
    
    vector<int> arr = {0,1,1,0,1,2,1,2,0,0,0};
    
    sortColors(arr);
    
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}