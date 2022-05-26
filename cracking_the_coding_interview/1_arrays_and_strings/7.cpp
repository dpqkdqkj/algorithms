#include <cstdio>



template <class T>
void printMat(T *mat, int size)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%02d ", *(mat + j + i*size));
        }
        printf("\n");
    }
}


template <class T>
void rotateMat(T *mat, int n)
{
    for (int num_ring = 0; num_ring < n / 2; ++num_ring) {
        int first_idx = num_ring;
        int last_idx = n - 1 - num_ring;
        for (int j = first_idx; j < last_idx; ++j) {
            int offset = j - first_idx;
            // mat[first_idx][j]
            T *ptop = (mat + first_idx*n + j);
            T *pleft = (mat + (last_idx - offset)*n + first_idx);
            T *pbot = (mat + last_idx*n + last_idx-offset);
            T *pright = (mat + j*n + last_idx);

            T top = *ptop;

            // left to top
            // mat[first_idx][j] = mat[last_idx - offset][first_idx]
            *ptop = *pleft;

            // bot to left
            // mat[last_idx-offset][first_idx] = mat[last_idx][last_idx-offset]
            *pleft = *pbot;

            // right to bot
            // mat[last_idx][last_idx-offset] = mat[j][last_idx]
            *pbot = *pright;

            // top to right
            // mat[j][last_idx] = top
            *pright = top;
        }
    }
}
/*
    00 01 02 03 04     40 30 20 10 00       
    10 11 12 13 14     41 31 21 11 01      
    20 21 22 23 24     42 32 22 12 02    
    30 31 32 33 34     43 33 23 13 03   
    40 41 42 43 44     44 34 24 14 04  

*/

int main()
{
    int N = 4;
    int matrix[N][N];
    int mat[N];
    
    int A[2][3];
    int (*p)[3];
    p = A;

    /*
    00 01   10 00       
    10 11   11 01      

    i0j0 i0j1
    i1j0 i1j1

    00 01 10 11     10 00 11 01 

    00 01 02 03 04     40 30 20 10 00       40 30 20 10 00
    10 11 12 13 14     41 31 21 11 01       04
    20 21 22 23 24     42 32 22 12 02       03
    30 31 32 33 34     43 33 23 13 03       02
    40 41 42 43 44     44 34 24 14 04       01

    */

    /* Direct iteration */
    printf("--------------------------------------\n");
    printf("Source matrix\n");
    printf("--------------------------------------\n");
    int tmp = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = tmp;
            printf("%02d ", matrix[i][j]);
            tmp++;
        }
        printf("\n");
    }

    int rotMatrix[N][N];
    printf("--------------------------------------\n");
    printf("After rotate\n");
    printf("--------------------------------------\n");
    /* Rotate iteration */
    for (int j = 0, k = 0; j < N; ++j, ++k) {
        for (int i = N - 1, l = 0; i >= 0; --i, ++l) {
            //printf("i%d j%d = %d ;", i, j, matrix[i][j]);
            //printf("%02d ", matrix[i][j]);
            rotMatrix[k][l] = matrix[i][j];
        }
    }
    
    rotateMat(matrix[0], N);
    printMat(matrix[0], N);
    return 0;
}

