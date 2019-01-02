/*
* problem on SPOJ: https://www.spoj.com/problems/PRIME1/
*/

#include<bits/stdc++.h>
using namespace std;
bool primechecker(int n);
int main(){

    int t;
    cin>>t;
    while(t-->0){     
        int a,b;
        cin>>a>>b;
        for(int i=a;i<=b;i++){
            if(primechecker(i)){
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
}
bool primechecker(int n){
    if(n<=1){
        return false;
    }
    else if(n==2)
        return true;
    else if(n%2==0)
        return false;
    else{
        bool prime=true;
        int divisor=3;
        int atcheck=sqrt(n)+1;
        while(divisor<=atcheck){
            if(n%divisor==0){
                prime=false;
                return prime;
            }
            divisor+=2;
 
        }
        return prime;
 
    }
}