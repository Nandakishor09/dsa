#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> arr){

    int n = arr.size();
    int mini = 0;

    for(int i = 0; i < n; i++){
        mini = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int n = 0;
    cout<<"Enter no of elements in the array: ";
    cin>>n;

    vector<int> arr;

    for(int i = 0; i < n; i++){
        int num = 0;
        cout<<"Enter number: ";
        cin>>num;
        arr.push_back(num);
    }

    selectionSort(arr);

    return 0;
}
