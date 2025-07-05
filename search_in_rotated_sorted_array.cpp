#include<iostream>
#include<vector>
using namespace std;
int search_bruteforce_rotated_sorted_array(vector<int>& v, int n, int target){
    for(int i=0;i<n;i++){
        if(v[i]==target){
            return i+1;
        }
    }
    return -1;
}
int search_optimal_rotated_sorted_array(vector<int>& v, int n, int target){
    int n = v.size();
    int st = 0;
    int end  = n-1;
    
    while(st<=end){
        int mid = st+(end-st)/2;
        if(v[mid]==target){
            return mid;
        }
        if(a[st]<=mid){
            if(a[st]<=target && target<=a[mid]){
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        else{
            if(a[mid]<=target && target<=a[end]){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    return -1;
}
int main(){

    vector<int> v = {3,4,5,6,7,0,1,2};
    int n = v.size();
    int target = 0;
    int result = search_bruteforce_rotated_sorted_array(v,n,target);

    cout<<result<<endl;

}