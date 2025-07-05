#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>
using namespace std;

int subarraysumk(vector<int>& a, int k){

    


    int n = a.size();

    int cur_sum = 0;
    int max_sum=0;
    vector<int> prefix_sum(n,0);
    int count=0;
    prefix_sum[0]=a[0];
    for(int i=1;i<n;i++){
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }
    unordered_map<int,int> m;
    for(int j=0;j<n;j++){
        if(prefix_sum[j]==k){
            count++;
        }
        int val = prefix_sum[j]-k;
        if(m.find(val)!=m.end()){
            count = count+m[val];
        }
        if(m.find(prefix_sum[j])==m.end()){
            m[prefix_sum[j]]=0;
        }
        m[prefix_sum[j]]++;
    }

    return count;
}
int main(){
    vector<int> a = {1,2,3};

    int k = 3;
    int result = subarraysumk(a,k);
    cout<<result<<endl;
}