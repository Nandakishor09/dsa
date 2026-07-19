#include <bits/stdc++.h>
using namespace std;

/*void insertionSort(vector<int> &arr, int n){

    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]){
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}*/

void insertionSort(vector<int> &arr, int ind){
    
    if(ind == arr.size()) return;
    
    int j = ind;
    while(j > 0 && arr[j - 1] > arr[j]){
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }
    ind++;
    insertionSort(arr, ind);
}

int main(){
    
    vector<int> arr = {4,3,2,1,5};
    int n = arr.size();
    
    insertionSort(arr, 0);
    
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}