#include<iostream>
using namespace std;

double myPow(double x,int n){
    long binform = n;
    double ans = 1;
    if(n==0 || x==1){
        ans = 1.0;
        return ans;
    }
    if(x==0){
        ans = 0.0;
        return ans;
    }
    if(x==-1){
        if(n%2==0){
            ans=+1.0;
            return ans;
        }
        else{
            ans=-1.0;
            return ans;
        }
    }
    if(binform<0){
        x = 1/x;
        binform = -(binform);
    }
    while(binform>0){
        if(binform%2==1){
            ans = ans*x;
        }
        x = x*x;
        binform = binform/2;
    }
    return ans;
}
int main(){
    double x = -1;
    int n = 4;
    double result = myPow(x,n);
    cout<<result<<endl;
}