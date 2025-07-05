#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int>& A, int m, vector<int>& B, int n){
    int idx = m+n-1,i = m-1,j = n-1;
    while(i>=0 && j>=0){
        if(A[i]>=B[j]){
            A[idx--]=A[i--];
        }
        else{
            A[idx--]=B[j--];
        }
    }
    while(j>=0){
        A[idx--] = B[j--];
    }
    for(int i=0;i<A.size()+B.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}















int main(){
    vector<int> A = {1,2,3,0,0,0};
    int m = A.size();
    vector<int> B = {2,5,6};
    int n = B.size();
    merge(A,m,B,n);
    return 0;
}