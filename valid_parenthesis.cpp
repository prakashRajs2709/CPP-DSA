#include<iostream>
#include<utility>
#include<vector>
#include<stack>
using namespace std;
bool isValid(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){

        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(st.size()==0){
                return false;
            }
            if((st.top()=='[' && s[i]==']') ||
                (st.top()=='{' && s[i]=='}') ||
                (st.top()=='(' && s[i]==')')){
                    st.pop();
                }
            else{
                return false;
            }
        }
    }
    return st.size()==0;
}
int main(){
    string s;
    s="{[(]}";
    bool flag = isValid(s);
    cout<<flag<<endl;
}