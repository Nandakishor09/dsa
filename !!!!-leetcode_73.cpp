#include <bits/stdc++.h>
using namespace std;

//this is not the correct solution.
//debugging is needed.

void setZeroes(vector<vector<int>> &matrix) {
        
    map<int, int> mpp;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){

            if(matrix[i][j] == 0 && (mpp.find(i) != mpp.end()) != 1){
                    
                for(int up = 0; up < matrix.size(); up++){
                    if(matrix[up][j] != 0){
                        mpp[up] = j;
                    }
                    matrix[up][j] = 0;
                    //mpp[up] = j;
                }
                for(int lo = 0; lo < matrix[i].size(); lo++){
                    if(matrix[i][lo] != 0){
                        mpp[i] = lo;
                    }
                    matrix[i][lo] = 0;
                    //mpp[i] = lo;
                }
            }
        }
    }
}

int main(){
    
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    
    setZeroes(matrix);
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
