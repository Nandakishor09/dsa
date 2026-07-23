#include <bits/stdc++.h>
using namespace std;

//optimized 
/*bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    for(int i = 0; i < matrix.size(); i++){
        if(matrix[i][0] <= target && matrix[i][matrix[i].size() - 1] >= target){
            int low = 0;
            int high = matrix[i].size() - 1;
            int mid = (low + high) / 2;
            while(low <= high){
                mid = (low + high) / 2;
                if(matrix[i][mid] > target)
                    high = mid - 1;
                else if(matrix[i][mid] < target)
                    low = mid + 1;
                else 
                    return true;
            }
        }
    }
    return false;
}*/

//most optimized 
bool searchMatrix(vector<vector<int>>& matrix, int target){
    
    int low = 0;
    int high = (matrix[0].size() * matrix.size()) - 1;
    
    while(low <= high){
        int mid = (low + high) / 2;
        int row = mid / matrix[0].size();
        int col = mid % matrix[0].size();
        
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}


int main(){
    
    vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 23;
    
    if(searchMatrix(mat, target)) cout<<"Found\n";
    else cout<<"Not Found\n";
    
    return 0;
}
