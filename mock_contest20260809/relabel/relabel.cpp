#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll mod1=998244353;
const ll mod2=1e9+7;
const ll base=97;
const ll base_inv1=699800165;
const ll base_inv2=268041239;

int n,q;
string s;
struct Hash{
	ll hash1,hash2;
	void init(){
		hash1=hash2=0;
	}
	void operator =(const Hash &x){
		hash1=x.hash1;hash2=x.hash2;
	}
	Hash operator +(const Hash &x){
		return {(hash1+x.hash1)%mod1,(hash2+x.hash2)%mod2};
	}
	Hash operator *(const ll &x){
		return {(hash1*x)%mod1,(hash2*x)%mod2};
	}
	bool operator <(const Hash &x){
		if(hash1==x.hash1) return hash2>x.hash2;
		else return hash1>x.hash1;
	}
	bool operator ==(const Hash &x){
		return (hash1==x.hash1)&&(hash2==x.hash2);
	}
}sum[30][N];
ll b1[N],b2[N],pos[30][N],siz[30];

inline ll qp(ll n,ll k,ll mod){
	ll sum=1;
	while(k){
		if(k&1) sum=sum*n%mod;
		n=n*n%mod;
		k>>=1;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q>>s;
	s=' '+s;
	b1[0]=b2[0]=1;
	for(int i=1;i<N;i++){
		b1[i]=b1[i-1]*base%mod1;
		b2[i]=b2[i-1]*base%mod2;
	}
	
	for(int i=1;i<=26;i++){
		sum[i][0].init();
		for(int j=1;j<=n;j++){
			sum[i][j]=sum[i][j-1];
			if((s[j]-'a')==(i-1)){
				sum[i][j]=(sum[i][j]+(Hash){b1[j-1],b2[j-1]});
				pos[i][++siz[i]]=j;
			} 
		}
	}
	
	while(q--){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if(l1>l2){
			swap(l1,l2);
			swap(r1,r2);
		}
		Hash v1[30],v2[30];
		Hash h1,h2;h1.init();h2.init();
		for(int i=1;i<=26;i++){
			ll a=sum[i][r1].hash1-sum[i][l1-1].hash1;
			a=(a%mod1+mod1)%mod1;
			a=a*b1[l2-l1]%mod1;
			ll b=sum[i][r1].hash2-sum[i][l1-1].hash2;
			b=(b%mod2+mod2)%mod2;
			b=b*b2[l2-l1]%mod2;
			v1[i]={a,b};
			
			a=sum[i][r2].hash1-sum[i][l2-1].hash1;
			a=(a%mod1+mod1)%mod1;
			b=sum[i][r2].hash2-sum[i][l2-1].hash2;
			b=(b%mod2+mod2)%mod2;
			v2[i]={a,b};
		}
		sort(v1+1,v1+27);
		sort(v2+1,v2+27);
		int flag=1;
		for(int i=1;i<=26;i++){
			if(v1[i]==v2[i]) continue;
			else flag=0;
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
