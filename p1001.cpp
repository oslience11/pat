#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() 
{
    int a,b;
    cin>>a>>b;
    int k =a+b;
    string s = to_string(abs(k));
    if(k<0) cout<<"-";
    for(size_t i = 0;i<s.length();++i){
        cout<<s[i];
        if((i+1)%3 == 0 && i+1 != s.size()-1 && i !=s.size()-1) cout<<",";
    }
}
// 0 1 2   3 4 5  6 7 
// 9 9 9 , 9 9 9 , 
// - 9 9