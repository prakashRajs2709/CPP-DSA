#include<iostream>
#include<vector>
using namespace std;

int stocks(vector<int> prices,int n){

    int bestbuy = prices[0];
    int maxprofit = 0;

    for(int i=1;i<=n;i++){
        if(prices[i]>=bestbuy){
            maxprofit = max(maxprofit,prices[i] - bestbuy);
        }
        bestbuy = min(bestbuy,prices[i]);
    }
    return maxprofit;
}
int main(){
                       
    vector<int> prices = {7,1,5,3,6,4};
    int n = prices.size();
    int result = stocks(prices,n);

    cout<<result<<endl;
    return 0;
}