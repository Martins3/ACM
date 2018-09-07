#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<math.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 1 * 10
 * 2 * 10
 * 3 * 10
 *
 */

int* spiralOrder(int ** matrix, int matrixRowSize, int matrixColSize) {
    int * res = (int *)(malloc)(sizeof(int) * matrixRowSize * matrixColSize);

    int loc = 0;
    int x = 0;
    int y = 0;
    while(matrixRowSize > 0 && matrixColSize > 0){
        // 上
        for (int i = y; i < matrixColSize + y; ++i)
            res[loc++] = matrix[x][i];
        x ++;
        matrixRowSize --;

        // 右
        for (int i = x; i < x + matrixRowSize ; ++i)
            res[loc++] = matrix[i][y + matrixColSize - 1];
        matrixColSize --;

        // 下
        for (int i = y + matrixColSize - 1; i >= y ; --i) {
            res[loc++] = matrix[x + matrixRowSize - 1][i];
        }
        matrixRowSize --;

        // 左
        for (int i = x + matrixRowSize - 1; i >= x; --i)
            res[loc++] = matrix[i][y];
        matrixColSize --;
        y ++;
    }
    return res;
}




void test(int row, int col){
    int m = 1;
    int ** matrix =(int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; ++i) {
        matrix[i] = (int *)malloc(sizeof(int) * col);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", m);
            matrix[i][j] = m ++;
        }
        printf("\n");
    }

    int * res = spiralOrder(matrix, row, col);

    for (int i = 0; i < row * col; ++i) {
        printf("%d ", res[i]);
    }

    free(res);
}

int main(){
    test(10, 1);
    test(4, 3);
    test(5, 2);
    return 0;
}
