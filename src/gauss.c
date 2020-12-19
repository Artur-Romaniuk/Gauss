#include "gauss.h"
#include <math.h>


/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix* mat, Matrix* b) {

    for (int i = 0; i < mat->c - 1; i++)
    {
        /*double maxabs = 0;
        int maxr = i;
        for (int j = i; j < mat->r; j++)
        {
            if (abs(mat->data[i][j]) > maxabs)
            {
                maxabs = mat->data[i][j];
                double* pom = mat->data[maxr];
                mat->data[maxr] = mat->data[i];
                mat->data[i] = pom;
            }

        }*/

        for (int j = i + 1; j < mat->r; j++)
        {
            double tmp = mat->data[j][i] / mat->data[i][i];
            for (int k = 0; k < mat->c; k++)
                mat->data[j][k] -= mat->data[i][k] * tmp;
            b->data[j][0] -= b->data[i][0] * tmp;
        }
    }

    return 0;
}

