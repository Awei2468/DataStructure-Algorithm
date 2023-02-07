#include<bits/stdc++.h>
using namespace std;

int main() {
    multiset<char> ms; //element can repeat
    set<char> st;      //element is unique

    ms.insert('a');
    ms.insert('b');
    ms.insert('b');
    ms.insert('c');
    ms.insert('d');
    ms.insert('d');
    ms.insert('d');
    ms.insert('e');

    for (auto iter = ms.begin(); iter != ms.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    auto pos = ms.find('d');
    for (auto iter = pos; iter != ms.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    st.insert('a');
    st.insert('b');
    st.insert('b');
    st.insert('c');
    st.insert('d');
    st.insert('d');
    st.insert('d');
    st.insert('e');

    for (auto iter = st.begin(); iter != st.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    system("pause");
    return 0;
}