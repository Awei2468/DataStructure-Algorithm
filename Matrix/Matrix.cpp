#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

const int Row = 2;
const int Col = 4;

const int Row_1 = 5, Col_1 = 3;
const int Row_2 = Col_1, Col_2 = 4;
const int Row_3 = 7, Col_3 = 8;

int SparseMatrix[Row_3][Col_3] = {{0,0,0,0,87,0,0,1},
                                  {2,0,0,0,0,0,0,0},                 
                                  {0,0,0,0,0,0,0,0},
                                  {12,0,0,0,0,0,0,0},
                                  {0,0,0,0,0,5,0,0},
                                  {0,0,0,0,0,0,0,0},                                            
                                  {0,33,0,0,0,0,0,50}};

void PrintMatrixByDoublePointer(int **A, int row, int col);
void PrintMatrix(int *A, int row, int col);
void PrintMatrixAnother(int (*A)[Col], int row, int col);
void PrintMatrixOther(int **A,int row, int col);
void MatrixAdd(int A[Row][Col], int B[Row][Col], int C[Row][Col]);
void MatrixMultiple(int A[Row_1][Col_1], int B[Row_2][Col_2], int C[Row_1][Col_2]);
void Transpose(int *origin, int *destination, int row, int col);
void CompressSparse(int *origin, int *res, int row, int col, int n);

void PolyAdd(int *A, int *B, vector<int> &R, int len_A, int len_b, int total_len);

int main(){

    int M1[Row][Col] = {{2,4,6,8},{1,3,5,7}};
    int (*ptr1)[Col] = M1;              //陣列指標
    int *ptr2[Row] = {M1[0], M1[1]};    //指標陣列
    int M2[Row][Col] = {{3,6,9,12},{5,10,15,20}};
    int Res[Row][Col];

    MatrixAdd(M1, M2, Res);
    
    cout << "M1:" << endl; PrintMatrixByDoublePointer(ptr2, Row, Col);
    cout << "M1:" << endl; PrintMatrixOther((int **)M1, Row, Col);
    cout << "M1:" << endl; PrintMatrixAnother(M1, Row, Col);
    cout << "M1:" << endl; PrintMatrix(&M1[0][0], Row, Col);
    cout << "M2:" << endl; PrintMatrix(&M2[0][0], Row, Col);
    cout << "Res:" << endl; PrintMatrix(&Res[0][0], Row, Col);

    cout << "--------------------------------------------------" << endl;

    int M3[Row_1][Col_1] = {{2,7,9},{1,4,6},{3,8,5},{4,7,8},{9,8,7}};
    int M4[Row_2][Col_2] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int Res_2[Row_1][Col_2];

    MatrixMultiple(M3, M4, Res_2);

    cout << "M3:" << endl; PrintMatrix(&M3[0][0], Row_1, Col_1);
    cout << "M4:" << endl; PrintMatrix(&M4[0][0], Row_2, Col_2);
    cout << "Res_2:" << endl; PrintMatrix(&Res_2[0][0], Row_1, Col_2);

    cout << "--------------------------------------------------" << endl;

    int transpose[Col][Row];

    Transpose(&M1[0][0], &transpose[0][0], Row, Col);

    cout << "Transpose:" << endl; PrintMatrix(&transpose[0][0], Col, Row);

    cout << "--------------------------------------------------" << endl;

    int counter = 0;

    for (int i = 0; i < Row_3; ++i) {
        for (int j = 0; j < Col_3; ++j) {
            if (SparseMatrix[i][j])
                ++counter;
        }
    }

    int CompressMatrix[counter+1][3];
    CompressSparse(&SparseMatrix[0][0], &CompressMatrix[0][0], Row_3, Col_3, counter+1);

    cout << "Compress Sparse:" << endl; PrintMatrix(&CompressMatrix[0][0], counter+1, 3);

    cout << "--------------------------------------------------" << endl;

    cout << "Polynomial Add" << endl;

    int poly_1[] = {5, 3, 5, -2, 4, 8, 2, -19, 1, 11, 0};  //p1 = 3x^5 - 2x^4 + 8x^2 - 19^x + 11
    int poly_2[] = {7, 6, 6, -1, 5, 7, 4, 8, 3, -18, 2, 21, 1, -100, 0};  //p2 = 6x^6- x^5 + 7x^4 + 8x^3 - 18x^2 + 21x - 100
    
    vector<int> ResPoly;
    int length = (poly_1[0] > poly_2[0]) ? 2*poly_2[0]+1 : 2*poly_2[0]+1;
    ResPoly.resize(1);

    PolyAdd(poly_1, poly_2, ResPoly, sizeof(poly_1) / sizeof(poly_1[0]), sizeof(poly_2) / sizeof(poly_2[0]), length);

    for (vector<int>::iterator iter = ResPoly.begin(); iter != ResPoly.end(); ++iter) {
        cout << setw(4) << *iter;
    }
    
    cout << endl;
    system("pause");
    return 0;
}

void PrintMatrixByDoublePointer(int **A, int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << setw(4) << A[i][j];
        }
        cout << endl;
    }
}

void PrintMatrix(int *A, int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << setw(4) << *(A + i*col + j);
        }
        cout << endl;
    }
    cout << endl;
}

void PrintMatrixAnother(int (*A)[Col], int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << setw(4) << A[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void PrintMatrixOther(int **A, int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << setw(4) << *((int *)A + i*col + j);
        }
        cout << endl;
    }
    cout << endl;
}

void MatrixAdd(int A[Row][Col], int B[Row][Col], int C[Row][Col]){
    for (int i = 0; i < Row; ++i) {
        for (int j = 0; j < Col; ++j)
            C[i][j] = A[i][j] + B[i][j];
    }
}

void MatrixMultiple(int A[Row_1][Col_1], int B[Row_2][Col_2], int C[Row_1][Col_2]){
    for (int i = 0; i < Row_1; ++i) {
        for (int j = 0; j < Col_2; ++j) {
            int temp = 0;
            for (int k = 0; k < Col_1; ++k) {
                temp += A[i][k] * B[k][j];
            }
            C[i][j] = temp;
        }
    }
}

void Transpose(int *origin, int *destination, int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *(destination + j*row + i) = *(origin + i*col + j);
        }
    }
}

void CompressSparse(int *origin, int *res, int row, int col, int n){
    *res = row;
    *(res + 1) = col;
    *(res + 2) = n-1;
    int temp = 1;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (*(origin + i*col +j)) {
                *(res + 3*temp) = i;
                *(res + 3*temp + 1) = j;
                *(res + 3*temp + 2) = *(origin + i*col +j);
                ++temp;
            }
        }
    }
}

void PolyAdd(int *A, int *B, vector<int> &R, int len_A, int len_B, int total_len){
    R[0] = total_len;
    int index_A = 2,
        index_B = 2;
    
    while (index_A < len_A && index_B < len_B) {
        if (A[index_A] > B[index_B]) {  //>
            R.push_back(A[index_A-1]);
            R.push_back(A[index_A]);
            index_A += 2;
        }
        else if (A[index_A] < B[index_B]) {  //<
            R.push_back(B[index_B-1]);
            R.push_back(B[index_B]);
            index_B += 2;
        }
        else {  //=
            R.push_back(A[index_A-1] + B[index_B-1]);
            R.push_back(A[index_A]);
            index_A += 2;
            index_B += 2;
        }
    }

    while (index_A < len_A) {
        R.push_back(A[index_A-1]);
        R.push_back(A[index_A]);
        index_A += 2;
    }

    while (index_B < len_B) {
        R.push_back(B[index_B-1]);
        R.push_back(B[index_B]);
        index_B += 2;
    }
}