#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
void foursum(vector<int>& a, int target){
    set<vector<int>> answer;
    vector<vector<int> result;
    sort(a.begin(),a.end());
    int n = a.size();
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && a[j]==a[j-1]) continue;
            int left = j+1;
            int right = n-1;
            while(left<right){
                int csum = a[left]+a[right]+a[i]+a[j];
                if(csum==target){
                    answer.insert({a[i],a[j],a[left],a[right]});
                    while(left<right && a[left]==a[left+1]){
                        left++;
                    }
                    while(left<right && a[right]==a[right-1]){
                        right--;
                    }
                    left++,right--;
                }
                else if(csum<target) left++;
                else right--;

            }

        }
    }
    for(vector<int> i:answer){
        for(int j:i){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<int> a = {1,0,-1,0,-2,2};
    int target = 0;
    foursum(a,target);
    return 0;

}