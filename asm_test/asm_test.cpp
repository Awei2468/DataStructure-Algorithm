#include<iostream>
#include<iomanip>

using namespace std;

const double PI = 3.1415926;

void ShowArray(int *A, int len);
void TestSendByArray(int A[], int len);
void TestSendByPointer(int *A, int len);
void TestSendPointerByAddr(int *A, int len);
void PrintCharArray(char A[]);
void PrintCharArrayByFor(char *A);

int main(){

    int n = 2, a = 5, b = 8;
    ++n;
    n++;
    
    int *ptn = &n;
    int &ref = n;
    int A1[] = {2,5,10,50,33,98};
    int length = sizeof(A1) / sizeof(A1[0]);

    ++*ptn;
    ref += 4;
    cout << "n=" << n << endl;

    n = a + b;

    cout << "*ptr = " << *ptn << endl;
    cout << "ref = " << ref << endl;

    cout << "1.-------------------------------------------------" << endl;

    ptn = A1;

    for (int i = 0; i < length; ++i) {
        //cout << setw(4) << *(ptn + i);
        cout << setw(4) << ptn[i];
    }
    cout << endl;

    TestSendByArray(A1, length);
    ShowArray(A1, length);

    TestSendByPointer(A1, length);
    ShowArray(A1, length);

    TestSendPointerByAddr(&A1[0], length);
    ShowArray(A1, length);

    cout << "2.-------------------------------------------------" << endl;

    int A2[] = {6, 12, 18, 24, 30};
    length = sizeof(A2) / sizeof(A2[0]);
    int (*ptr1)[5] = &A2;   //陣列指標
    //int (*ptr1)[length] = &A2;   //can't work, because it length can't be put variable
    int *ptr2[5] = {&A2[0], &A2[1], &A2[2], &A2[3], &A2[4]};   //指標陣列

    cout << "About ptr1=>" << endl;
    cout << setw(10) << "ptr1:" << ptr1 << endl;
    cout << setw(10) << "*ptr1:" << *ptr1 << endl;
    cout << setw(10) << "*(ptr1+1):" << *(ptr1+1) << endl;   //show A2 address + 4bytes*5
    cout << setw(10) << "ptr1+1:" << ptr1+1 << endl;
    cout << setw(10) << "A2:" << A2 << endl;
    cout << setw(10) << "&A2:" << &A2 << endl;
    cout << setw(10) << "ptr1[2]:" << ptr1[2] << endl;
    cout << setw(10) << "*ptr1[4]:" << (*ptr1)[4] << endl;

    cout << "\nAbout ptr2=>" << endl;
    cout << setw(10) << "ptr2:" << ptr2 << endl;
    cout << setw(10) << "&ptr2:" << &ptr2 << endl;
    cout << setw(10) << "*ptr2:" << *ptr2 << endl;   //show A2[0] address
    cout << setw(10) << "ptr2+1:" << ptr2+1 << endl;
    cout << setw(10) << "*(ptr2+2):" << *(ptr2+2) << endl;
    cout << setw(10) << "ptr2[2]:" << ptr2[2] << endl;     //get A2[2] address
    cout << setw(10) << "*ptr2[2]:" << *ptr2[2] << endl;   //get A2[2] value

    cout << "3.-------------------------------------------------" << endl;

    char str1[] = "Test for C++~";
    char str2[] = {'T', 'e', 's', 't', ' ', 'f', 'o', 'r', ' ', 'C', '+', '+', '~', '\0'};
    char *str3 = (char *)"What a small world.";   //read only,can't be changed
    string str4 = "Lebron James";

    PrintCharArray(str1);
    PrintCharArray(str2);
    PrintCharArrayByFor(str3);
    cout << "Sizeof(str1):" << sizeof(str1) << endl;   //include '\0'

    cout << "4.-------------------------------------------------" << endl;

    string S1 = "ABC";
    S1 += "...";
    S1.insert(0,"1");
    cout << S1 << endl; 

    cout << endl;
    system("pause");
    return 0;
}

void ShowArray(int *A, int len){
    for (int i = 0; i < len; ++i) {
        cout << setw(4) << A[i];    //之所以可以這樣寫是因為傳入的A為原本陣列的第一個元素位置,因此A[i]可以想成是*(A+i)
    }
    cout << endl;
}

void TestSendByArray(int A[], int len){   //雖然傳入為A[],但實際上是傳入陣列第一個元素的位置
    for (int i = 0; i < len; ++i) {
        A[i]++;
    }
}

void TestSendByPointer(int *A, int len){
    for (int i = 0; i < len; ++i) {
        A[i] += 2;
    }
}

void TestSendPointerByAddr(int *A, int len){
    for (int i = 0; i < len; ++i) {
        *(A + i) += 3;
    }
}

void PrintCharArray(char A[]){
    cout << A << endl;   //與印int array不同
}

void PrintCharArrayByFor(char *A){
    
    for (int i = 0; A[i] != '\0'; ++i) {
        cout << A[i];
    }
    /*
    int i = 0;
    while (A[i] != '\0') {  //also can use while loop
        cout << A[i++];
    }
    */
    cout << endl;
}

