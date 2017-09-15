class Solution {
public:
    bool searchColumn(vector<vector<int>>& matrix, int row, int lo, int hi, int target) {
        if (lo >= hi) return (matrix[row][lo] == target);
        
        int med = lo + (hi - lo) / 2;
        if (target == matrix[row][med]) {
            return true;
        }
        if (target < matrix[row][med]) {
            return searchColumn(matrix, row, lo, med - 1, target);
        }
        return searchColumn(matrix, row, med + 1, hi, target);
    }
    
    int searchRow(vector<vector<int>>& matrix, int lo, int hi, int target) {
        if (lo >= hi) return lo;
        
        int med = lo + (hi - lo) / 2;
        if (target < matrix[med][0]) {
            return searchRow(matrix, lo, med - 1, target);
        } else if (target >= matrix[med][0] && target <= matrix[med][matrix[0].size()-1]) {
            return med;
        }
        return searchRow(matrix, med + 1, hi, target);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int row = searchRow(matrix, 0, matrix.size()-1, target);
        
        return searchColumn(matrix, row, 0, matrix[0].size()-1, target);
    }
};
