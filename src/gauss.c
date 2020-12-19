#include "gauss.h"
#include <math.h>


/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix* mat, Matrix* b) {

    for (int i = 0; i < mat->c - 1; i++)
    {
        double maxabs = 0;  //znalezenie elementu głównego
        int maxr = i;
        for (int j = i + 1; j < mat->r; j++)
        {
            if (abs(mat->data[j][i]) > maxabs)
            {
                maxabs = mat->data[j][i];
                maxr = j;
            }
        }
        double* pom = mat->data[maxr]; //zamiana i tego wiersza z największym
        mat->data[maxr] = mat->data[i];
        mat->data[i] = pom;
        pom = b->data[maxr];
        b->data[maxr] = b->data[i];
        b->data[i] = pom;

        for (int j = i + 1; j < mat->r; j++) //eliminacja
        {
            double tmp = mat->data[j][i] / mat->data[i][i];
            for (int k = 0; k < mat->c; k++)
                mat->data[j][k] -= mat->data[i][k] * tmp;
            b->data[j][0] -= b->data[i][0] * tmp;
        }
    }

    return 0;
}

