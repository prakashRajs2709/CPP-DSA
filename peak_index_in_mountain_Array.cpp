#include<iostream>
#include<vector>
using namespace std;
int peak_index(vector<int>& arr, int n){
    int st = 0, end = n-1;
    
    while(st<=end){
        int mid = st+(end-st)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid-1]<arr[mid]){
            st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {0,10,1,0};
    int n = arr.size();
    int index = peak_index(arr,n);
    cout<<index<<endl;
}