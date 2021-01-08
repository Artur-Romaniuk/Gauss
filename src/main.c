#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include "test.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv) {
    int res;
    Matrix* A = readFromFile(argv[1]);
    Matrix* b = readFromFile(argv[2]);
    Matrix* x;

    if (A == NULL) return -1;
    if (b == NULL) return -2;
    printf("Created A:\n");
    printToScreen(A);
    printf("Created B:\n");
    printToScreen(b);

    res = eliminate(A, b);
    if (res != 0) {
        fprintf(stderr, "Blad! Macierz A jest osobliwa!\n");
        freeMatrix(A);
        freeMatrix(b);
        return res;
    }

    x = createMatrix(b->r, 1);
    if (x != NULL) {
        res = backsubst(x, A, b);
        if (res != 0) {
            if (res == 1)
                fprintf(stderr, "Blad! Dzielenie przez zero!\n");
            else // res == 2
                fprintf(stderr, "Blad! Nieprawidlowe rozmiary macierzy!\n");
            freeMatrix(x);
            freeMatrix(A);
            freeMatrix(b);
            return res;
        }
        printToScreen(x);
        test(A, b, x);
        freeMatrix(x);
    }
    else {
        fprintf(stderr, "Blad! Nie moglem utworzyc wektora wynikowego x.\n");
    }

    freeMatrix(A);
    freeMatrix(b);

    fprintf(stderr, "Program zakonczyl dzialanie bez bledu!\n");
    return 0;
}
