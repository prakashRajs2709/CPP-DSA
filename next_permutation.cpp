#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> n_permutation(vector<int>& A){
    int piv=-1;
    int n = A.size();
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            piv = i;
            break;
        }
    }
    if(piv==-1){
        reverse(A.begin(),A.end());
        return A;
    }
    for(int i=n-1;i>=0;i--){
        if(A[i]>A[piv]){
            swap(A[i],A[piv]);
            break;
        }
    }
    int i = piv+1,j = n-1;
    while(i<=j){
        swap(A[i],A[j]);
        i++,j--;
    }
    return A;
}








int main(){
    vector<int> A = {1,2,3};
    vector<int> result(A);
    result = n_permutation(A);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}