class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int index =0;
        while(index<n && matrix[index][m-1] < target) index++;
        if(index == n) return false;
        int low = 0;
        int high = m-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(matrix[index][mid] == target) return true;
            else if(matrix[index][mid] < target) low=mid+1;
            else high = mid-1;
        }
        return false;
    }
};
