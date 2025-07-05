#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

void subarrays_creation(vector<int>& v, int n, int size){
    for(int i=0;i<n-size+1;i++){
        for(int j=i;j<i+size;j++){
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }
}
void sum_of_all_subarrays_of_size(vector<int>& v, int n, int size){
    int sum=0;
    for(int i=0;i<n-size+1;i++){
        for(int j=i;j<i+size;j++){
            sum+=v[j];
        }
        cout<<sum<<"\n";
        sum=0;
    }
}
void count_of_all_subarrays_of_size_equals_k(vector<int>& v,int n,int size,int k){
    int sum=0;
    int count=0;
    for(int i=0;i<n-size+1;i++){
        for(int j=i;j<i+size;j++){
            sum+=v[j];
        }
        if(sum==k){
            count++;
        }
        sum=0;
    }
    cout<<count<<endl;

}
void maximum_score(vector<int>& v,int n,int size){
    vector<int> result;
    int cur_max = 0;
    for(int i=0;i<n-size+1;i++){
        for(int j=i;j<i+size;j++){
            cur_max = max(cur_max,v[j]);
        }
        result.push_back(cur_max);
    }
    for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
    }
    cout<<endl;
}
int main(){

    vector<int> v= {5,1,2,4,9,2,1,3,3};
    vector<int> v2= {1,2,3,1,4,5,2,3,6};
    int n = v.size();
    int n2 = v2.size();
    int size = 3;
    int k = 7;
    int size2 = 3;
    // sum_of_all_subarrays_of_size(v,n,size);
    // count_of_all_subarrays_of_size_equals_k(v,n,size,k);
    maximum_score(v2,n2,size2);

}
