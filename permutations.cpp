#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void getperm(vector<int>& v,int idx,vector<vector<int>>& ans){

    if(idx==v.size()){
        ans.push_back({v});
        return;
    }
    for(int i=idx;i<v.size();i++){
    swap(v[idx],v[i]);
    getperm(v,idx+1,ans);
    swap(v[idx],v[i]);
    }
}

vector<vector<int>> permute(vector<int>& v){
    vector<vector<int>> ans;
    getperm(v,0,ans);
    return ans;
}

int main(){
    vector<int> v = {1,2,3};
    vector<vector<int>> arr;
    arr = permute(v);
    for(auto a:arr){
        for(auto v:a){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}