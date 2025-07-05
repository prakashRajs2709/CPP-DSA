#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string reverse_bf(string s){
    int n = s.length();
    string ans="";

    reverse(s.begin(),s.end());

    for(int i=0;i<n;i++){
        string word = "";
        while(i<n && s[i]!=' '){
            word+=s[i];
            i++;
        }
        reverse(word.begin(),word.end());
        if(word.length()>0){
            ans += " " + word;
        }
    }
    return ans.substr(1);
}
int main(){
    string s=" hello world ";
    string result = reverse_bf(s);
    cout<<result<<endl;
    return 0;
}