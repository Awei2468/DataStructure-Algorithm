#include<bits/stdc++.h>

using namespace std;

int LIS_value(vector<int>);
int LIS_length_part(vector<int>, int*);
int LIS_length_tail(vector<int>, int*);
void PrintResultDual(vector<vector<int>>);
void PrintOrderSet(set<int>, int);
void memreverse(void* source, int length);
int getSize(int **array, int size);

int main() {

    priority_queue<pair<int, pair<int,int>>> pq; //min heap according to first element
    pq.push({3, {9, 100}}), pq.push({3, {5, 200}}), pq.push({3, {8, 400}});
    cout << "{" << pq.top().first << "," << pq.top().second.first << "," << pq.top().second.second << "}" << "\n";

    //priority queue practice========================================================================

    vector<int> v2 = {2, 5, 10};
    v2.insert(v2.begin(), -1);
    for (int &num : v2)
        cout << num << " ";
    cout << "\n";
    
    v2.erase(v2.begin()+2);
    for (int &num : v2)
        cout << num << " ";

    //pointer practice========================================================================

    char ch[8] = {0};
    ch[3] = 115;
    cout << ch[3] << endl;

    int *array;
    int size = getSize(&array, 10);
    if (size) {
        for (int i = 0; i < size; ++i)
            cout << array[i] << " ";
        cout << endl;
    }

    //pointer practice========================================================================

    int *record = new int[50];  //also can be record[50]

    vector<int> seq1 = {-7, 10, 9, 2, 3, 8, 8, 1};
    vector<int> seq2 = {-7, 8, -2, 6, 1, 4, -5, 9};
    vector<vector<int>> test;

    cout << LIS_value(seq2) << endl;  //sequential
    cout << LIS_length_part(seq1, record) << endl;  //not sequential
    cout << LIS_length_tail(seq2, record) << endl;  //not sequential

    test.push_back({100, 200});
    test.push_back({1, 5, 7, 10});
    PrintResultDual(test);

    //practice set operation========================================================================

    set<int> set1;
    set1.insert(99);
    set1.insert(2);
    set1.insert(14);
    set1.insert(2);

    PrintOrderSet(set1, 1);

    set1.insert(50);
    PrintOrderSet(set1, 2);

    auto ret = set1.erase(30);  //30 doesn't exist in set1, but that's OK no fail, ret show how many target be erased.
    cout << "ret = " << ret << endl;

    ret = set1.erase(99);
    cout << "ret = " << ret << endl;
    PrintOrderSet(set1, 2);

    if (set1.count(2))
        cout << "2 is in set1." << endl;
    else
        cout << "2 isn't in set1." << endl;

    if (set1.count(99))
        cout << "99 is in set1." << endl;
    else
        cout << "99 isn't in set1." << endl;

    set1.clear();
    if (set1.empty())
        cout << "set1 is empty!" << endl;
    else
        cout << "set1 still has member!" << endl;

    vector<int> v1 = {3, -1, 50, -2, 88, 1};
    set<int> set2(v1.begin(), v1.end());  //by assign a vector
    PrintOrderSet(set2, 2);

    set<int> set3{5, 4, 3, 2, 1};  //by assign value
    PrintOrderSet(set3, 1);

    PrintOrderSet(set2, 3);

    //practice reverse========================================================================

    system("pause");
    return 0;
}

void PrintResultDual(vector<vector<int>> v) {
    for (vector<int> single : v) {
        for (int value : single)
            cout << value << " ";
        cout << endl;
    }
    cout << endl;
}

void PrintOrderSet(set<int> s, int method) {
    switch (method) {
        case 1:
            for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter)
                cout << *iter << " ";
            cout << endl;
            break;
        case 2:
            for (auto &member : s)
                cout << member << " ";
            cout << endl;
            break;
        case 3:  //reverse print
            for (auto t = s.rbegin(); t != s.rend(); ++t)
                cout << *t << " ";
            cout << endl;
        default:
            break;
    }
}

int LIS_value(vector<int> v) {
    int res = 0, max = INT32_MIN;
    for (int num : v) {
        res = (res + num > res) ? res + num : num;
        if (res > max)
            max = res;
    }
    return max;
}

int LIS_length_part(vector<int> v, int* nums) {
    int ans = 0;
    for (int i = 0; i < 50; ++i) nums[i] = 1;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[i] > v[j]) {
                nums[i] = max(nums[i], nums[j]+1);
            }
        }
        ans = max(ans, nums[i]);
    }
    return ans;
}

int LIS_length_tail(vector<int> v, int* nums) {
    int ans = 0;
    for (int i = 0; i < 50; ++i) nums[i] = 1;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i+1; j < v.size(); ++j) {
            if (v[i] < v[j]) {
                nums[j] = max(nums[j], nums[i]+1);
            }
        }
        ans = max(ans, nums[i]);
    }
    return ans;
}

void memreverse(void* source, int length) {

}

int getSize(int **array, int size) {
    *array = (int*) malloc(sizeof(int) * size);
    if (array) {
        for (int i = 0; i < size; ++i)
            (*array)[i] = i;  //*(*array + i) = i;
        return size;
    }
    else
        return 0;
}
