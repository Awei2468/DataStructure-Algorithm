#include<iostream>
#include<iomanip>
#include"memory.h"

using namespace std;

const int Max = 10000;

void ShowData(int *A, int length);
void Swap(int &x, int &y);
void BubbleSort(int *A, int length, bool SmallBig);
void SelectionSort(int *A, int length, bool SmallBig);
void InsertionSort(int *A, int length, bool SmallBig);

void Merge(int *A, int start, int mid, int end);
void MergeSort(int *A, int start, int end);
void MergeSort_ver2(int *res, int *nums, int L, int R);

int Partition(int *A, int start, int end, bool &SmallBig);
void QuickSort(int *A, int start, int end, bool &SmallBig);
void QuickSort_ver2(int *A, int L, int R);

void ShellSort(int *A, int length, bool SmallBig);
void RadixSort(int *A, int length);

bool BinarySearch(int *A, int length, int target);
bool InterpolationSearch(int *A, int length, int target);

int main(){

    bool SmallBig = true, BigSmall = false;
    int data[] = {25,3,48,61,10,88,72,100,1};
    int *Res;
    int len = sizeof(data) / sizeof(data[0]);
    int data1[len], data2[len], data3[len], data4[len], data5[len], data6[len];
    memcpy(data1,data,sizeof(data));
    memcpy(data2,data,sizeof(data));
    memcpy(data3,data,sizeof(data));
    memcpy(data4,data,sizeof(data));
    memcpy(data5,data,sizeof(data));
    memcpy(data6,data,sizeof(data));

    cout << "Bubble Sort." << endl;
    cout << "Before:"; ShowData(data, len);
    BubbleSort(data, len, SmallBig);
    cout << " After:"; ShowData(data, len);
    cout << endl;

    cout << "Selection Sort." << endl;
    cout << "Before:"; ShowData(data1, len);
    SelectionSort(data1, len, SmallBig);
    cout << " After:"; ShowData(data1, len);
    cout << endl;

    cout << "Insertion Sort." << endl;
    cout << "Before:"; ShowData(data2, len);
    InsertionSort(data2, len, SmallBig);
    cout << " After:"; ShowData(data2, len);
    cout << endl;

    cout << "Merge Sort." << endl;
    cout << "Before:"; ShowData(data3, len);
    Res = new int[len];
    MergeSort_ver2(Res, data3, 0, len);
    cout << " After:"; ShowData(Res, len);
    //MergeSort(data3, 0, len-1);
    //cout << " After:"; ShowData(data3, len);
    delete [] Res;
    cout << endl;

    cout << "Quick Sort." << endl;
    cout << "Before:"; ShowData(data4, len);
    //QuickSort(data4, 0, len-1, BigSmall);
    QuickSort_ver2(data4, 0, len-1);
    cout << " After:"; ShowData(data4, len);
    cout << endl;

    cout << "Shell Sort(extention from insertion sort)." << endl;
    cout << "Before:"; ShowData(data5, len);
    ShellSort(data5, len, BigSmall);
    cout << " After:"; ShowData(data5, len);
    cout << endl;

    cout << "Radix Sort." << endl;
    cout << "Before:"; ShowData(data6, len);
    RadixSort(data6, len);
    cout << " After:"; ShowData(data6, len);
    cout << endl;

    if (BinarySearch(data6, len, 88) && BinarySearch(data6, len, 100))
        cout << "88 and 100 are both in the array." << endl;
    else
        cout << "88 and 100 maybe at least one is not in the array." << endl;

    if (BinarySearch(data6, len, 5))
        cout << "5 is in the array." << endl;
    else
        cout << "5 is not in the array." << endl;

    if (InterpolationSearch(data6, len, 61))
        cout << "61 is in the array." << endl;
    else 
        cout << "61 is not in the array." << endl;

    if (InterpolationSearch(data6, len, 87))
        cout << "87 is in the array." << endl;
    else 
        cout << "87 is not in the array." << endl;

    system("pause");
    return 0;
}

void ShowData(int *A, int length){
    for (int i = 0; i < length; ++i) {
        cout << setw(4) << A[i];
    }
    cout << endl;
}

void Swap(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void BubbleSort(int *A, int length, bool SmallBig){  //can improve by set a flag and break if the flag is true, save some time
    for (int i = length-1; i >= 1; --i) {  //round
        bool CheckFinish = true;
        for (int j = 0; j < i; ++j) {  //bubble
            if (SmallBig) {
                if (A[j+1] < A[j]) {
                    CheckFinish = false;
                    Swap(A[j+1], A[j]);
                }
            }
            else {
                if (A[j+1] > A[j]) {
                    CheckFinish = false;
                    Swap(A[j+1], A[j]);
                }
            }
        }
        if (CheckFinish) return;
    }
}

void SelectionSort(int *A, int length, bool SmallBig){
    for (int i = 0; i < length-1; ++i) {
        for (int j = i+1; j < length; ++j) {
            if (SmallBig) {
                if (A[j] < A[i])
                    Swap(A[j], A[i]);
            }
            else {
                if (A[j] > A[i])
                    Swap(A[j], A[i]);
            }
        }
    }
}

void InsertionSort(int *A, int length, bool SmallBig){
    for (int i = 1; i < length ; ++i) {
        int key = A[i];
        int j = i-1;
        if (SmallBig) {
            while (key < A[j] && j >= 0) {
                A[j+1] = A[j];
                --j;
            }
        }
        else {
            while (key > A[j] && j >= 0) {
                A[j+1] = A[j];
                --j;
            }
        }
        A[j+1] = key;
    }
}

void Merge(int *A, int start, int mid, int end){

    int LeftSub[mid-start+2];  //increase one more space to place dummy max
    int RightSub[end-mid+1];   //increase one more space to place dummy max
    int temp_start = start, temp_mid = mid;

    for (int i = 0; i < mid-start+2; ++i, ++temp_start) {
        if (i != mid-start+1)
            LeftSub[i] = A[temp_start];
        else
            LeftSub[i] = Max;
    }

    for (int i = 0; i < end-mid+1; ++i, ++temp_mid) {
        if (i != end-mid)
            RightSub[i] = A[temp_mid+1];
        else
            RightSub[i] = Max;
    }

    int idxLeft = 0, idxRight = 0;
    for (int i = start; i <= end; ++i) {
        if (LeftSub[idxLeft] <= RightSub[idxRight]) {
            A[i] = LeftSub[idxLeft++];
        }
        else {
            A[i] = RightSub[idxRight++];
        }
    }
}

void MergeSort(int *A, int start, int end){
    if (start < end) {
        int mid = (start + end)/2;
        MergeSort(A, start, mid);
        MergeSort(A, mid+1, end);
        Merge(A, start, mid, end);
    }
}

void MergeSort_ver2(int *res, int *nums, int L, int R){ //better
    if (R - L < 2) return;
    int M = L + ((R-L) >> 1);

    MergeSort_ver2(res, nums, L, M);
    MergeSort_ver2(res, nums, M, R);

    int t = L, i = L, j = M;
    while (i < M && j < R) {
        res[t++] = (nums[i] < nums[j]) ? nums[i++] : nums[j++];
    }
    while (i < M) {
        res[t++] = nums[i++];
    }
    while (j < R) {
        res[t++] = nums[j++];
    }
    t = L;
    while (t < R) {
        nums[t] = res[t];
        t++;
    }
}

int Partition(int *A, int start, int end, bool &SmallBig){
    int pivot = A[end];
    int i = start-1;

    for (int j = start; j < end; ++j) {
        if (SmallBig) {
            if (A[j] < pivot) {
                ++i;
                Swap(A[i],A[j]);
            }
        }
        else {
            if (A[j] > pivot) {
                ++i;
                Swap(A[i],A[j]);
            }
        }
    }

    ++i;
    Swap(A[i],A[end]);
    return i;
}

void QuickSort(int *A, int start, int end, bool &SmallBig){
    if (start < end) {
        int pivot = Partition(A, start, end, SmallBig);
        QuickSort(A, start, pivot-1, SmallBig);
        QuickSort(A, pivot+1, end, SmallBig);
    }
}

void QuickSort_ver2(int *A, int L, int R){ //better
    if (L >= R) return;
    int pivot = R, j = L-1;
    for (int i = L; i < R; ++i) {
        if (A[i] < A[pivot]) {
            ++j;
            Swap(A[i], A[j]);
        }
    }
    ++j;
    Swap(A[j], A[pivot]);
    QuickSort_ver2(A, L, j-1);
    QuickSort_ver2(A, j+1, R);
}

void ShellSort(int *A, int length, bool Smallbig){
    int slice = length/2;
    while (slice) {
        for (int i = slice; i < length; ++i) {
            int key = A[i];
            int j = i-slice;
            if (Smallbig) {
                while (key < A[j] && j >= 0) {
                    A[j+slice] = A[j];
                    j -= slice;
                }
            }
            else {
                while (key > A[j] && j >= 0) {
                    A[j+slice] = A[j];
                    j -= slice;
                }
            }
            A[j+slice] = key;
        }
        slice /= 2;
    }
}

void RadixSort(int *A, int length){
    int Max = 100;
    int radix = 1, LSD, MSD, dataIndex;
    int buckets[10][length];
    int counter[10] = {0};

    while (radix <= Max) {
        for (int i = 0; i < length; ++i) {
            LSD = (A[i] / radix) % 10;
            buckets[LSD][counter[LSD]] = A[i];
            ++counter[LSD];
        }
    
        radix *= 10;
        dataIndex = 0;

        for (int i = 0; i <= 9; ++i) {
            if (counter[i]) {
                for (int j = 0; j < counter[i]; ++j)
                    A[dataIndex++] = buckets[i][j];
            }
            counter[i] = 0;
        }
    }

}

bool BinarySearch(int *A, int length, int target){
    int l = 0, r = length - 1;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (target > A[mid])
            l = mid + 1;
        else if (target < A[mid])
            r = mid - 1;
        else
            return true;
    }
    return false;
}

bool InterpolationSearch(int *A, int length, int target){
    
    int front = 0,
        end = length-1,
        mid;
    
    while (front <= end) {
        mid = front + (target - A[front]) / (A[end] - A[front]) * (end - front);
        if (target > A[mid])
            front = mid+1;
        else if (target < A[mid])
            end = mid-1;
        else
            return true; 
    }
    return false;

}