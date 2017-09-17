class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix == null || matrix.length < 1) {
            return false;
        }
        int row = matrix.length;
        int col = matrix[0].length;

        int start = 0;
        int end = row * col - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            int value = matrix[mid / col][mid % col];
            if (target == value) {
                return true;
            } else if (target > value) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
}