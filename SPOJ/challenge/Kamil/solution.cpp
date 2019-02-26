/*
*
* https://www.spoj.com/problems/KAMIL/
* score 234
*
*/
#include<bits/stdc++.h>
using namespace std;

int main() {int i,t=10,a,x;while(t--){x=0;char str[21];cin>>str;for(i=0;i<strlen(str);++i){if(str[i]=='F'||str[i]=='L'||str[i]=='T'||str[i]=='D'){x++;}}a=pow(2,x);cout<<a<<endl;}return 0;}

/*
* solution with a 140 score
*
* #include<stdio.h>
* main(){char c;int X=1;while((c=getchar())!=-1){if(c=='\n'){printf("%d\n",X);X=1;}if(c=='F'||c=='L'||c=='D'||c=='T')X*=2;}}
*/