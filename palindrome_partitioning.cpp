#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ispalin(string s){
    string s2=s;
    reverse(s.begin(),s.end()); 
    return s2==s;
}

void part(string s, vector<string>& palin, vector<vector<string>>& ans){
    if(s.size()==0){
        ans.push_back(palin);
        return;
    }
    for(int i=0;i<s.size();i++){
        string p=s.substr(0,i+1);
        if(ispalin(p)){
            palin.push_back(p);
            part(s.substr(i+1),palin,ans);
            palin.pop_back();
        }
    }
}

vector<vector<string>> partit(string s){
    vector<vector<string>> ans;
    vector<string> palin;
    part(s,palin,ans);
    for (const string& str : palin){ 
        cout << str << " "; 
    } 
    cout<<endl;
    return ans;
}

int main(){
    string s = "aab";
    vector<vector<string>> ans;
    ans=partit(s);
    for (const vector<string>& a : ans) { 
        for (const string& str : a) { 
            cout << str << " "; 
        } 
        cout << endl; }
    
}