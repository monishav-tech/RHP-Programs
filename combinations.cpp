#include<iostream>
using namespace std;
int main(){
string s;
cout<<"Enter your string:";
cin>>s;
int n=s.length();
for(int i=1;i<(1<<n);i++){
string ans="";
for(int j=0;j<n;j++){
if((i &(1<<j))>0){
ans+=s[j];
}
}
cout<<ans<<endl;
}
return 0;
}
