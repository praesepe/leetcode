void rotate(int **, int, int);

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    if (matrixRowSize != matrixColSize) return;
    
    return _rotate(matrix, matrixRowSize, 0);
}

void _rotate(int **matrix, int len, int startIdx) {
    if (len <= 1) return;
    
    int maxIdx = startIdx + len - 1;
    for (int i=1; i<len; i++) {
        int idx = startIdx + i;
        int reverseIdx = maxIdx - i;
        int tmp = matrix[startIdx][idx];
        matrix[startIdx][idx] = matrix[reverseIdx][startIdx];
        matrix[reverseIdx][startIdx] = matrix[maxIdx][reverseIdx];
        matrix[maxIdx][reverseIdx] = matrix[idx][maxIdx];
        matrix[idx][maxIdx] = tmp;
    }
    
    _rotate(matrix, len-2, startIdx+1);
}
