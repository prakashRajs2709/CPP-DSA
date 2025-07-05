#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>
using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
    unordered_map<int, bool>d;

    int n = grid.size()*grid.size();
    int m=0;
    int expectedSum = (n*(n+1))/2;
    int actualSum=0;
    for(const auto& i:grid){
        for(int j:i){
            if (d.find(j)!=d.end()){
                m=j;
            }
            else{
                d[j]=true;
                actualSum+=j;
            }
        }
    }
    int missingvalue = expectedSum-actualSum+m;
    return {m,missingvalue};

}
int main(){

    vector<vector<int>> grid;
    grid = {{1,3},{2,2}};
    vector<int> ans;
    ans = findMissingAndRepeatedValues(grid);
    for (int i:ans){
        cout << i << " "; 
    } 
    cout << endl;
}