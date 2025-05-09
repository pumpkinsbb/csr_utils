#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillMatrixRandom(vector<vector<int>>& matrix, int& rows, int& cols);
void displayMatrix(const vector<vector<int>>& matrix);
void convertToCSR(const vector<vector<int>>& matrix, vector<int>& vval, vector<int>& vpos, vector<int>& vptz);
void subtractScalarFromDiagonal(vector<int>& vval, vector<int>& vpos, vector<int>& vptz, int scalar, int rows);
void restoreMatrixFromCSR(vector<vector<int>>& matrix, const vector<int>& vval, const vector<int>& vpos, const vector<int>& vptz);
void displayCSR(const vector<int>& vval, const vector<int>& vpos, const vector<int>& vptz);
