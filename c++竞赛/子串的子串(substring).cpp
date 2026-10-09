#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull; 
const int N=3e3+10;
static const ull base1=1313131;
static const ull mod1=(1<<61)-1;
static const ull base2=233333;
static const ull mod2=998244353;
ull m1[N],m2[N];
struct hash{
	ull hash1,hash2;
	void init(){
		hash1=hash2=0;
	}
	void cal(hash x,char ch){
		hash1=(x.hash1*base1+ull(ch))%mod1;
		hash2=(x.hash2*base2+ull(ch))%mod2;
	}
	hash operator *(const ull &x){
		hash tmp;
		tmp.init();
		tmp.hash1=hash1*m1[x]%mod1;
		tmp.hash2=hash2*m2[x]%mod2;
		return tmp;
	}
	hash operator -(const hash &x){
		hash tmp;
		tmp.init();
		tmp.hash1=((hash1-x.hash1)%mod1+mod1)%mod1;
		tmp.hash2=((hash2-x.hash2)%mod2+mod2)%mod2;
		return tmp;
	}
}a[N];
ull get_sub(ull s,ull e){
	return m1[e]-m2[s-1]*(e-s+1);
}
int a[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	s=' '+s;
	a[0].init();
	m1[0]=m2[0]=1;
	for(int i=1;i<=n;i++){
		a[i].cal(a[i-1],s[i]);
		m1[i]=(m1[i-1]*base1)%mod1;
		m2[i]=(m2[i-1]*base2)%mod2;
	}
	
	return 0;
}

