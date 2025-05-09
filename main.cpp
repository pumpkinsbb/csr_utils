#include <iostream>
#include "csr_utils.h"
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    system("chcp 65001 > nul");

    vector<vector<int>> matrix;
    vector<int> vval, vpos, vptz;
    int rows = 0, cols = 0;

    fillMatrixRandom(matrix, rows, cols);

    displayMatrix(matrix);
    convertToCSR(matrix, vval, vpos, vptz);
    displayCSR(vval, vpos, vptz);

    int scalar;
    cout << "\n¬вед≥ть число дл€ в≥дн≥манн€ з д≥агонал≥: ";
    cin >> scalar;

    subtractScalarFromDiagonal(vval, vpos, vptz, scalar, rows);
    restoreMatrixFromCSR(matrix, vval, vpos, vptz);

    displayMatrix(matrix);
    displayCSR(vval, vpos, vptz);

    return 0;
}
