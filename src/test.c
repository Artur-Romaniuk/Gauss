#include "test.h"

int test(Matrix* A, Matrix* B, Matrix* x)
{
    for (int i = 0; i < A->r; i++)
    {
        double sum = 0;
        for (int j = 0; j < A->c; j++)
        {
            sum += (A->data[i][j]) * (x->data[j][0]);
        }

        if (abs(sum - B->data[i][0]) > epsilon)
        {
            printf("Błędny wynik! Sum: %f B: %f", sum, B->data[i][0]);
            return 1;
        }
    }
    printf("Wynik jest poprawny!\n");
    return 0;
}