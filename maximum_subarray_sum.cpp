#include<iostream>
#include<math.h>
#include<vector>
#define INT_MIN -0x7fffffff - 1
#define INT_MAX 0x7fffffff
using namespace std;

int max_subarray_sum_bruteforce(vector<int>& v, int n){
    int max_sum = 0;
    for(int start=0;start<n;start++){
        int cur_sum = 0;
        for(int end=start;end<n;end++){
            cur_sum+=v[end];
            max_sum=max(cur_sum,max_sum);
        }
    }
    return max_sum;
}

int max_subarray_sum_kadane(vector<int>& v, int n){
    int cur_sum = 0;
    int max_sum=0;
    for(int i=0;i<n;i++){
        
        cur_sum+=v[i];
        if(cur_sum<=0){
            cur_sum=0;
        }
        max_sum=max(max_sum,cur_sum);
    }
    return max_sum;
}
int main(){

    vector<int> v= {3,-4,5,4,-1,7,-8};
    int n = v.size();
    int max_sum = max_subarray_sum_bruteforce(v,n);
    int max_sum2 = max_subarray_sum_kadane(v,n);
    
    
    cout<<max_sum<<endl;
    cout<<max_sum2<<endl;

}