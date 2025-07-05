#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int threesumoptimal(vector<int>& a, int n){
    int target = 0;
    sort(a.begin(),a.end());
    set<vector<int>> s;
    vector<vector<int>> answer;
    for(int i=0;i<n;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum = a[i]+a[j]+a[k];
            if(sum==target){
                s.insert({a[i],a[j],a[k]});
                j++,k--;
                while(j<k && a[j]==a[j-1]) j++;
            }
            else if(sum>target){
                k--;
            }
            else{
                j++;
            }
        }
    }
    for(vector<int> i:s){
        answer.push_back(i);
    }
    for(vector<int> i:answer){
        for(int a:i){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return answer.size();
}




int main(){
    vector<int> a = {0,2,1,-4,-1,-1};
    int n = a.size();
    int result = threesumoptimal(a,n);
    cout<<result<<endl;

    cout<<n<<endl;
}
