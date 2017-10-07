#import <Foundation/Foundation.h>

void setMatrixZero(NSInteger **matrix, NSUInteger m, NSUInteger n)
{
    BOOL shouldSetFirstRowZero = NO;
    NSInteger i, j;
    
    for (j = 0;j < n; j++) {
        if (matrix[0][j] == 0) {
            shouldSetFirstRowZero = YES;
            break;
        }
    }
    
    for (i = 1;i < m; i++) {
        for (j = 0;j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for (i = 1;i < m; i++) {
        if (matrix[i][0] == 0) {
            for (j = 1;j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    for (j = 1;j < n; j++) {
        if (matrix[0][j] == 0) {
            for (i = 1;i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    if (matrix[0][0] == 0) {
        for (i = 1;i < m; i++) {
            matrix[i][0] = 0;
        }
    }
    
    if (shouldSetFirstRowZero) {
        for (j = 0;j < n; j++) {
            matrix[0][j] = 0;
        }
    }
}

int main(int argc, char * argv[]) {
    NSInteger row = 3, column = 4;
    
    NSInteger **data = (NSInteger **)malloc(row * sizeof(NSInteger*));
    for (int i = 0;i < row; i++) {
        data[i] = (NSInteger *)malloc(column * sizeof(NSInteger));
    }
    
    data[0][0] = 0;
    data[0][1] = 1;
    data[0][2] = 3;
    data[0][3] = 4;
    
    data[1][0] = 1;
    data[1][1] = 1;
    data[1][2] = 3;
    data[1][3] = 4;
    
    data[2][0] = 0;
    data[2][1] = 1;
    data[2][2] = 3;
    data[2][3] = 4;
    
    setMatrixZero(data, row, column);
    
    for (int i = 0;i < row; i++) {
        for (int j = 0;j < column; j++) {
            NSLog(@"%ld ", data[i][j]);
        }
        NSLog(@"\n");
    }
}
