#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> two_sum(vector<int>& a, int target){
        vector<pair<int,int>> numind;
        for(int i=0;i<a.size();i++){
            numind.push_back({a[i],i});
        }
        sort(numind.begin(),numind.end());
        int left = 0,right = a.size()-1;
        vector<int> result;
        int csum=0;
        while(left<right){
            csum = numind[left].first+numind[right].first;
            if(csum==target){
                result.push_back(numind[left].second);
                result.push_back(numind[right].second);
                return result;
            }
            else if(csum<target){
                left++;
            }            else{
                right--;
            }
        }
        return {};
}
int main(){
    vector<int> a = {3,2,4};
    int target = 6;
    vector<int> result;
    result = two_sum(a,target);
    for(int w:result){
        cout<<w<<" ";
    }
    cout<<endl;
}
