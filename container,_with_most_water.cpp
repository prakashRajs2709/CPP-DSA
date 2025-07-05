#include<iostream>
#include<vector>
using namespace std;
int maxarea_bruteforce(vector<int>& height){
    int ma = 0;
    int w,l,ca;
    for(int i=0;i<height.size();i++){
        for(int j=i+1;j<height.size();j++){
            w = (j-i);
            l = min(height[i],height[j]);
            ca = w*l;
            ma = max(ma,ca);
        }
    }
    return ma;
}
int maxarea_optimal(vector<int>& height){
    int ma = 0;
    int w,l,ca;
    int i=0;
    int j = height.size()-1;
    while(i<j){
        w = j-i;
        l = min(height[i],height[j]);
        ca = w*l;
        ma = max(ma,ca);
        if(height[i]<height[j]){
            i++;
        } 
        else{
            j--;
        }
    }
    return ma;
}
int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = maxarea_bruteforce(height);
    int result2 = maxarea_optimal(height);

    cout<<result<<endl;
    cout<<result2<<endl;


    return 0;
}