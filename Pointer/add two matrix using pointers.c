#include <stdio.h>
void matrixInput(int mat[3][3]);
void matrixPrint(int mat[3][3]);
void matrixAdd(int mat1[3][3], int mat2[3][3], int res[3][3]);
int ROWS,COLS;
int main()
{
    int mat1[3][3], mat2[3][3], res[3][3];
    printf("Enter elements in first matrix of size %dx%d: \n", ROWS, COLS);
    matrixInput(mat1);
    printf("\nEnter elemetns in second matrix of size %dx%d: \n", ROWS, COLS);
    matrixInput(mat2);
    matrixAdd(mat1, mat2, res);

    printf("\nSum of first and second matrix: \n");
    matrixPrint(res);

    return 0;
}
void matrixInput(int mat[3][3])
{
    int i, j;


    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            scanf("%d", (*(mat + i) + j));
        }
    }
}
void matrixPrint(int mat[3][3])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}
void matrixAdd(int mat1[3][3], int mat2[3][3], int res[3][3])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
           
            *(*(res + i) + j) = *(*(mat1 + i) + j) + *(*(mat2 + i) + j);
        }
    }
}