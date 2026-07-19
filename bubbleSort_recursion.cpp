#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n){
    
    if(n == 1) return;
    int flag = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            flag = 1;
            swap(arr[i], arr[i + 1]);
        }
    }
    n--;
    if(flag == 0) return;
    bubbleSort(arr, n);
}

int main(){
    
    vector<int> arr = {3,3,3,1};
    int n = arr.size();
    
    bubbleSort(arr, n);
    
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}