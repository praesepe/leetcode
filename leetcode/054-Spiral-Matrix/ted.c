/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    if (matrixRowSize == 0 || matrixColSize == 0) {
        return NULL;
    }
    
    int *answer = malloc(sizeof(int)*matrixRowSize*matrixColSize);
    
    spiralTraverse(answer, matrix, 0, 0, matrixRowSize, matrixColSize);
    
    return answer;
}

void spiralTraverse(int *answer, int **matrix, int rowStart, int colStart, int matrixRowSize, int matrixColSize) {
    if (matrixRowSize == 0 || matrixColSize == 0) {
        return;
    }
    
    if (matrixRowSize == 1) {
        for (int i=0; i<matrixColSize; i++) {
            *(answer++) = matrix[rowStart][colStart+i];
        }
        
        return;
    }
    
    if (matrixColSize == 1) {
        for (int i=0; i<matrixRowSize; i++) {
            *(answer++) = matrix[rowStart + i][colStart];
        }
        
        return;
    }

    for (int i=0; i<matrixColSize; i++) {
        *(answer++) = matrix[rowStart][colStart+i];
    }
    
    int colLast = colStart + matrixColSize - 1;
    for (int i=1; i<matrixRowSize; i++) {
        *(answer++) = matrix[rowStart+i][colLast];
    }
    
    int rowLast = rowStart + matrixRowSize - 1;
    for (int i=colLast-1;i>=colStart;i--) {
        *(answer++) = matrix[rowLast][i];
    }
    
    for (int i=rowLast-1;i>rowStart;i--) {
        *(answer++) = matrix[i][colStart];
    }
    
    return spiralTraverse(answer, matrix, rowStart+1, colStart+1, matrixRowSize-2, matrixColSize-2);
}
