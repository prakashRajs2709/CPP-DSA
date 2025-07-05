#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void bruteforce(vector<int>& v){
    sort(v.begin(),v.end()); // O(n log n)
}
void optimized(vector<int>& v){ //O(n)
    int cz = 0,co =0,ct = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]==0){cz++;}
        else if(v[i]==1){co++;}
        else{ct++;}
    }
    int i = 0;
    while(i<cz){
        v[i]=0;
        i++;
    }
    i=0;
    while(i<co){
        v[i+cz]=1;
        i++;
    }
    i=0;
    while(i<ct){
        v[i+cz+co]=2;
        i++;
    }
}
void optimal(vector<int>& v){
    int mid = 0,low = 0,high = v.size()-1;
    while(mid<=high){
        if(v[mid]==0){
            swap(v[low],v[mid]);
            mid++;low++;
        }
        else if(v[mid]==1){
            mid++;
        }
        else{
            swap(v[high],v[mid]);
            high--;
        }
    }                               //O(n)
}
int main(){
    vector<int> v = {2,0,2,1,1,0,1,2,0,0};
    optimal(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}