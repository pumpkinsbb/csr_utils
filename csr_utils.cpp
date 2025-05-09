#include "csr_utils.h"

void fillMatrixRandom(vector<vector<int>>& matrix, int& rows, int& cols) {
    srand(time(0));
    cout << "\n¬вед≥ть к≥льк≥сть р€дк≥в ≥ стовпц≥в: ";
    cin >> rows >> cols;
    matrix.assign(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            matrix[i][j] = rand() % 10; // ¬ипадков≥ числа в≥д 0 до 9
}

void displayMatrix(const vector<vector<int>>& matrix) {
    cout << "\nћатриц€:" << endl;
    for (const auto& row : matrix) {
        for (int val : row)
            cout << setw(4) << val;
        cout << endl;
    }
}

void convertToCSR(const vector<vector<int>>& matrix, vector<int>& vval, vector<int>& vpos, vector<int>& vptz) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vval.clear(); vpos.clear(); vptz = { 0 };
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                vval.push_back(matrix[i][j]);
                vpos.push_back(j);
            }
        }
        vptz.push_back(vval.size());
    }
}

void subtractScalarFromDiagonal(vector<int>& vval, vector<int>& vpos, vector<int>& vptz, int scalar, int rows) {
    vector<int> new_val, new_pos;
    vector<int> new_ptz = { 0 };

    for (int i = 0; i < rows; ++i) {
        bool found = false;
        int start = vptz[i], end = vptz[i + 1];

        for (int j = start; j < end; ++j) {
            if (vpos[j] == i) {
                new_val.push_back(vval[j] - scalar);
                new_pos.push_back(i);
                found = true;
            }
            else {
                new_val.push_back(vval[j]);
                new_pos.push_back(vpos[j]);
            }
        }

        if (!found) {
            new_val.push_back(-scalar);
            new_pos.push_back(i);
        }

        new_ptz.push_back(new_val.size());
    }

    vval = std::move(new_val);
    vpos = std::move(new_pos);
    vptz = std::move(new_ptz);
}

void restoreMatrixFromCSR(vector<vector<int>>& matrix, const vector<int>& vval, const vector<int>& vpos, const vector<int>& vptz) {
    int rows = vptz.size() - 1;
    int cols = rows;
    matrix.assign(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        int start = vptz[i];
        int end = vptz[i + 1];
        for (int j = start; j < end; ++j)
            matrix[i][vpos[j]] = vval[j];
    }
}

void displayCSR(const vector<int>& vval, const vector<int>& vpos, const vector<int>& vptz) {
    cout << "\nvval: ";
    for (int val : vval) cout << val << " ";
    cout << "\nvpos: ";
    for (int pos : vpos) cout << pos << " ";
    cout << "\nvptz: ";
    for (int ptz : vptz) cout << ptz << " ";
    cout << endl;
}
