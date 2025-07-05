#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getAllcombinations(vector<int>& arr, int idx, int target, vector<vector<int>>& ans, vector<int>& combin){
    if(idx<arr.size() || target < 0){
        return;
    }
    if(target == 0){
        ans.push_back({combin});
        return;
    }
        combin.push_back(arr[idx]);
        getAllcombinations(arr, idx+1, target - arr[idx], ans, combin);
        getAllcombinations(arr, idx, target - arr[idx], ans, combin);
        combin.pop_back();
}

vector<vector<int>> combinationsum(vector<int>& arr, int target){
    vector<vector<int>> ans;
    vector<int> combin;
    getAllcombinations(arr, 0, target, ans, combin);
    return ans;
}
int main(){
    vector<int> arr = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = combinationsum(arr, target);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}