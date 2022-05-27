#include <iostream>
#include <cstdio>


void setRowZeros(int *matrix, int row, int cols)
{
    for (int i = 0; i < cols; ++i)
    {
        // matrix[row][i] = 0
        *(matrix + row*cols + i) = 0;
    }
}

void setColZeros(int *matrix, int col, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        // matrix[i][col] = 0
        *(matrix + i*rows + col) = 0;
    }
}

void setZeros(int *matrix, int rows, int cols)
{
    bool rowsIdxZero[rows];
    bool colsIdxZero[cols];

    for (int i = 0; i < rows; ++i)
    {
        rowsIdxZero[i] = false;
    }
    for (int j = 0; j < cols; ++j)
    {
        colsIdxZero[j] = false;
    };

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (*(matrix + i*rows + j) == 0)
            {
                rowsIdxZero[i] = true;
                break;
            }
        }
    }
    for (int j = 0; j < cols; ++j)
    {
        for (int i = 0; i < rows; ++i)
        {
            if (*(matrix + i*rows + j) == 0)
            {
                colsIdxZero[j] = true;
                break;
            }
        }
    };

    for (int i = 0; i < rows; ++i)
    {
        if (rowsIdxZero[i])
        {
            setRowZeros(matrix, i, cols);
        }
    }
    for (int j = 0; j < cols; ++j)
    {
        if (colsIdxZero[j])
        {
            setColZeros(matrix, j, rows);
        }
    };
}

template <class T>
void printMat(T *mat, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            printf("%02d ", *(mat + i*size + j));
        }
        printf("\n");
    };
};




int main()
{
    int N = 4;
    //int matrix[N][N] = {
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {4, 5, 3, 6},
        {4, 7, 0, 9},
        {11, 0, 12, 13}
    };
    /*
    int tmp = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = tmp;
            tmp++;
        }
    }
    */

    setZeros(matrix[0], 4, 4);
    //setRowZeros(matrix[3], 4);
    //setColZeros(matrix[0], 2, 4);
    //setRowZeros(matrix[0], 2, 4);
    printMat(matrix[0], 4);

    return 0;
}
