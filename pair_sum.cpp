#include<iostream>
#include<vector>
using namespace std;

vector<int> pair_sum_bruteforce(int arr[], int n, int target){
    vector<int> v;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                v.push_back(i);
                v.push_back(j);
        }
    }
    }

    return v;
}

vector<int> pair_sum_optimal(int arr[], int n, int target){
    vector<int> v;
    int pairsum=0;
    int i=0;
    int j=n-1;
    while(i<j){
            pairsum=arr[i]+arr[j];
            if(pairsum>target){
                j--;
            }
            if(pairsum<target){
                i++;
            }
            if(pairsum==target){
                v.push_back(i);
                v.push_back(j);
                return v;
            }

        
    }

    return v;
}
int main(){
    int n = 4;
    int target = 18;
    int arr[n] = {2,7,11,15};
    vector<int> v;
    // v = pair_sum_bruteforce(arr,n,target);
    v = pair_sum_optimal(arr,n,target);
    for(int i=0;i<v.size();i++){
    cout<<v[i]<<" "<<endl;
    }
}