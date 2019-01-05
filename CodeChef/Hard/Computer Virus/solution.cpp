#include<cstdio>
#include<cctype>

// reads the integer from stdin char by char 
inline int getint() {
	register char ch;
	while(!isdigit(ch=getchar()));
	register int x=ch^'0';
	while(isdigit(ch=getchar())) 
		x=(((x<<2)+x)<<1)+(ch^'0');
	return x;
}
typedef long long ll;
const int M=1001,mod=1e9+7;
// returns a to the power of k
inline int power(int a,int k) {
	int ret=1;
	for(;k;k>>=1) {
		if(k&1) ret=(ll)ret*a%mod;
		a=(ll)a*a%mod;
	}
	return ret;
}
int d[M];
int main() {
	const int n=getint(),m=getint();
	int ans=mod-m;
	for(register int i=1;i<=m;i++) {
		int tmp=1;
		d[i]=getint();
		for(register int j=0;j<i;j++) {
			tmp=(ll)tmp*power(i-j+1,d[j+1]-d[j])%mod;
		}
		(ans+=tmp)%=mod;
	}
	printf("%d\n",ans);
	return 0;
}