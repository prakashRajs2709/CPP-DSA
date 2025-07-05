#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
vector<vector<int>> a;
vector<int> v = {1,2,2};
void subsets(vector<int>& v, vector<int>& ans, int i,vector<vector<int>>& a){
    
    if(i==v.size()){
        a.push_back({ans});
        return;
    }
    ans.push_back(v[i]);
    subsets(v,ans,i+1,a);
    ans.pop_back();
    subsets(v,ans,i+1,a);
}

void subsetsd(vector<int>& v, vector<int>& ans, int i,vector<vector<int>>& a){
    if(i==v.size()){
        a.push_back({ans});
        return;
    }
    ans.push_back(v[i]);
    subsets(v,ans,i+1,a);
    ans.pop_back();
    int idx=i+1;
    while(idx<v.size() && v[idx]==v[idx-1]){
        idx++;
    }
    subsets(v,ans,idx,a);
}

void printsubsets(){
    
    sort(v.begin(),v.end());
    subsetsd(v,ans,0,a);
    for(auto v: a){
        for(auto i:v){
            cout<<i<<" ";

        }
        cout<<endl;
    }
}
int main(){
    printsubsets();
    return 0;
}