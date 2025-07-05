#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int majority_element_brute_force(vector<int>& v){
    int n = v.size();
    for(int val:v){
        int frequency = 0;
        for(int ele:v){
            if(ele==val){
                frequency++;
            }
        }
        if(frequency>n/2){
            return val;
        }
        
    }
}
int majority_element_after_sorting(vector<int>& v){
    sort(v.begin(),v.end());
    int n = v.size();
    int frequency=0;
    for(int val:v){
        frequency++;
        if(frequency>n/2){
            return val;
        }     
    }
}

int majority_element_moore(vector<int>& v){
    
    int freq=0;
    int ans=0;
    for(int i=0;i<v.size();i++){
        if(freq==0){
            ans=v[i];
        }
        if(ans==v[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    return ans;
}

int main(){
    vector<int> v = {2,2,1,1,1,2,2};
    // int result = majority_element_brute_force(v);
    // int result = majority_element_after_sorting(v);
    int result = majority_element_moore(v);
    
    cout<<result<<endl;
     
}