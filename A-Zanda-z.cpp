#include<iostream>
#include<string>
using namespace std;
int main(){
string s;
cout<<"Enter your string:";
cin>>s;
char str[1000001];
int flag1=0;
int flag2=0;
for(int i=0;i<s.length();i++){
if(s[i]>='a' && s[i]<='z'){
flag1=flag1| (1<<(s[i]-'a'));
}
if(s[i]>='A' && s[i]<='Z'){
flag2=flag2| (1<<(s[i]-'A'));
}
}
if((flag1==((1<<26)-1))&&(flag2==((1<<26) -1))){
cout<<"It contains all 26 uppercase and lowercase characters";
}
else{
cout<<"It doesn't contains all 26 uppercase and lowercase characters";
}
return 0;
}
