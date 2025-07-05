#include<iostream>
#include<vector>
using namespace std;
vector<int> product(vector<int>& nums){
    vector<int> result(nums.size(),1);
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            if(i!=j){
                result[i] = result[i]*nums[j];
            }
        }
    }
    return result;
}
vector<int> product_optimal_1(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n,1);
    for(int i=1;i<n;i++){
        ans[i] = ans[i-1]*nums[i-1];
    }
    int suffix = 1;
    for(int i=n-2;i>=0;i--){
        suffix = suffix*nums[i+1];
        ans[i] = ans[i]*suffix;
    }
    
    return ans;
}
vector<int> product_optimal(vector<int>& nums){
    int n = nums.size();
    vector<int> result(n,1);
    vector<int> prefix(n,1);
    vector<int> suffix(n,1);
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]*nums[i-1];
    }
    for(int i=n-2;i>=0;i--){
        suffix[i] = suffix[i+1]*nums[i+1];
    }
    for(int i=0;i<n;i++){
        result[i] = prefix[i]*suffix[i];
    }
    
    return result;
}
int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> result = product_optimal_1(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;


}