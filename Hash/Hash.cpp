#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>

using namespace std;

vector<int> twosum(vector<int>& nums,int target){ //leetcode first

    map<int,int> M;
    vector<int> result;

    /*
    for(int i=0; i<nums.size(); ++i){
        //M.insert({nums[i],i});       //first is key(can't be repeatable),second is value
        //M[nums[i]] = i;              //another way
        M.insert(pair<int,int>(nums[i],i));   //another way
    }
    */

    for(int i=0; i<nums.size(); ++i){

        M[nums[i]] = i;
        if (M.count(target-nums[i])){
            result.push_back(M[target-nums[i]]);
            result.push_back(i);
            break;
        }

    }
    return result;
}



int main(){

    map<int,int> Map_0;
    map<string,int> Map_1;
    map<string,int>::iterator iter;

    //cout << "Map_0[1]=" << Map_0[1] << endl;   //map container initial value is zero

    vector<int> Array = {1,3,8,11,20};
    vector<int> res = twosum(Array,12);

    for(int i=0; i<res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;

    //------------------------------------------------------------------------

    Map_1["Allen"] = 1;  //insert (key,value)
    Map_1["Paul"] = 2;
    Map_1["James"] = 3;
    Map_1["Davis"] = 4;
    Map_1["Howard"] = 5;

    cout << "sizeof map<int,int>:" << sizeof(Map_0) << endl;
    cout << "sizeof map<string,int>:" << sizeof(Map_1) << endl;

    for(iter = Map_1.begin(); iter != Map_1.end(); ++iter){
        cout << iter->first << "=>" << iter->second << endl;
    }

    iter = Map_1.find("James");

    if (iter != Map_1.end()){
        cout << "Find, the value is " << iter->second << endl;
    }
    else
        cout << "Not found." << endl;

    //------------------------------------------------------------------------
    cout << endl;

    unordered_map<int,string> map_2;
    map_2[5] = "Awei";
    map_2[0] = "Westbrook";
    map_2[8] = "Adam";
    map_2[6] = "Curry";
    map_2[10] = "Anthony";

    cout << "sizeof unordered_map:" << sizeof(map_2) << endl;

    cout << "Using normal for loop to print=>" << endl;
    for (unordered_map<int,string>::iterator iter = map_2.begin(); iter != map_2.end(); ++iter) {
        cout << iter->first << "." << iter->second << endl;
    }

    cout << endl << "Using for auto to print=>" << endl;
    for (auto n : map_2) {
        cout << n.first << "." << n.second << endl;
    }

    cout << endl << "Testing for auto to print array=>" << endl;
    vector<int> A_one = {2,4,6,8,10,12};

    for (auto k : A_one) {
        cout << k << " ";
    }


    cout << endl;
    system("pause");
    return 0;
}
