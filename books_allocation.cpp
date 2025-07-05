#include<iostream>
#include<vector>
using namespace std;
bool isvalid(vector<int>&v, int n, int m, int maxallowedpages){
    int stu=1,pages=0;
    for(int i=0;i<n;i++){
        if(v[i]>maxallowedpages){
            return false;
        }

        if(pages+v[i]<=maxallowedpages){
            pages+=v[i];
        }
        else{
            stu++;
            pages=v[i];
        }
    }
    if(stu>m){
        return false;
    }
    else{
        return true;
    }
}


int allocatebooks(vector<int>& v, int n, int m){
    if(m>n){
        return -1;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    int st = 0,end = sum;
    int ans=-1;
    int mid=0;
    while(st<=end){
        mid = st+(end-st)/2;
        if(isvalid(v,n,m,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            st = mid+1;
        }
    }
    return ans;
    
}






int main(){
    vector<int> v = {15,17,20};
    int n = v.size();
    int m = 2;
    cout<<allocatebooks(v,n,m)<<endl;
    return 0;
}