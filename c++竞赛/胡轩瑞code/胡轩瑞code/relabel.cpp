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
}sum[30][N];
ll b1[N],b2[N],pos[30][N],siz[30];
struct node{
	ll ap,lsp;
	bool operator <(const node &x) const{
		return lsp>x.lsp;
	}
}tmp1[30],tmp2[30];

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
	freopen("relabel.in","r",stdin);
	freopen("relabel.out","w",stdout);
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
		int val1=0,val2=0,flag=1;
		for(int i=1;i<=26;i++){
			int idx=upper_bound(pos[i]+1,pos[i]+1+siz[i],r1)-pos[i]-1;
			if(pos[i][idx]>=l1) tmp1[i]={i,pos[i][idx]},val1++;
			else tmp1[i]={i,-1};
		}
		for(int i=1;i<=26;i++){
			int idx=upper_bound(pos[i]+1,pos[i]+1+siz[i],r2)-pos[i]-1;
			if(pos[i][idx]>=l2) tmp2[i]={i,pos[i][idx]},val2++;
			else tmp2[i]={i,-1};
		}
		sort(tmp1+1,tmp1+27);sort(tmp2+1,tmp2+27);
		if(val1!=val2) flag=0;
		else{
			Hash h1,h2;h1.init();h2.init();
			for(int i=1;i<=val1;i++){
				ll p1=tmp1[i].lsp-l1,p2=tmp2[i].lsp-l2;
				if(p1!=p2) flag=0;
				if(tmp1[i].lsp==-1) break;
				
				ll num1=sum[tmp1[i].ap][tmp1[i].lsp].hash1-sum[tmp1[i].ap][l1-1].hash1;
				num1=(num1%mod1+mod1)%mod1;
				num1=num1*qp(base_inv1,l1-1,mod1)%mod1;
				ll num2=sum[tmp1[i].ap][tmp1[i].lsp].hash2-sum[tmp1[i].ap][l1-1].hash2;
				num2=(num2%mod2+mod2)%mod2;
				num2=num2*qp(base_inv2,l1-1,mod2)%mod2;
				h1=h1+Hash{i*num1%mod1,i*num2%mod2};
				
				num1=sum[tmp2[i].ap][tmp2[i].lsp].hash1-sum[tmp2[i].ap][l2-1].hash1;
				num1=(num1%mod1+mod1)%mod1;
				num1=num1*qp(base_inv1,l2-1,mod1)%mod1;
				num2=sum[tmp2[i].ap][tmp2[i].lsp].hash2-sum[tmp2[i].ap][l2-1].hash2;
				num2=(num2%mod2+mod2)%mod2;
				num2=num2*qp(base_inv2,l2-1,mod2)%mod2;
				h2=h2+Hash{i*num1%mod1,i*num2%mod2};
			}
			if(h1.hash1!=h2.hash1||h1.hash2!=h2.hash2) flag=0;
		}
		if(flag==0) cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}

