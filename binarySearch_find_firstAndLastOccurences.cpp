#include <bits/stdc++.h>
using namespace std;
 
void sortArray(vector<int> &arr){
 
	int n = arr.size();
	for(int i = 0; i < n; i++){
    	int minn = i;
    	for(int j = i + 1; j < n; j++){
        	if(arr[j] < arr[minn]){
            	minn = j;
        	}
    	}
    	swap(arr[i], arr[minn]);
	}
}
 
int binarySearch(vector<int> &arr, int toCheck){
 
	int low = 0;
	int high = arr.size() - 1;
	int index = 0;
 
	while(low <= high){
    	int mid = (low + high) / 2;
    	if(arr[mid] < toCheck){
        	low = mid + 1;
    	}
    	else if(arr[mid] > toCheck){
        	high = mid - 1;
    	}
    	else{
        	index = mid;
        	break;
    	}
	}
 
	int cnt = 1;
	int left = index - 1;
	int right = index + 1;
	while(arr[left] == toCheck){
    	cnt++;
    	left--;
	}
	while(arr[right] == toCheck){
    	cnt++;
    	right++;
	}
    cout<<"First Occurrence: "<<left + 1<<endl;
    cout<<"Last Occurrence: "<<right - 1<<endl;
	return cnt;
 
}
 
void print(vector<int> arr){
 
	for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
	}
	cout<<endl;
}
 
int main(){
 
	vector<int> arr;
 
	int n = 0;
    cout<<"Enter no of inputs: ";
	cin>>n;
 
	for(int i = 0; i < n; i++){
        cout<<"Enter number: ";
    	int num = 0;
        cin>>num;
        arr.push_back(num);
	}
 
	sortArray(arr);
	print(arr);
 
	int check = 0;
    cout<<"Enter number to be searched: ";
	cin>>check;
 
    cout<<binarySearch(arr, check);
 
	return 0;
}
