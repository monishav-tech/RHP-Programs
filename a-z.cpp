#include<iostream>
#include<string>
using namespace std;
int main(){
string s;
cout<<"Enter your string:";
cin>>s;
char str[1000001];
int flag=0;
for(int i=0;i<s.length();i++){
flag=flag| (1<<(s[i]-'a'));
}
if(flag==((1<<26) -1)){
cout<<"It contains all 26 characters";
}
else{
cout<<"It doesn't contains all 26 characters";
}
return 0;
}
