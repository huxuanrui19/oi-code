#include<bits/stdc++.h>
#define npos string::npos
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll mod=1e9+7;
string s1,s2,s3;
string l,r,tar;
string s[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
ll qp(ll a,ll b){
	ll sum=1;
	while(b){
		if(b&1) sum=sum*a%mod;
		a=a*a%mod;b>>=1;
	}
	return sum;
}
void change(string &b,string a){
	for(int i=0;i<(int)a.size();i++){
		int num;
		if(isdigit(a[i])) num=a[i]-'0';
		else num=a[i]-'A'+10;
		b+=s[num];
	}
}
void sub(string &a){
	for(int i=int(a.size())-1;i>=0;i--){
		if(a[i]=='1'){
			a[i]--;break;
		}
		else a[i]='1';
	}
	size_t pos=a.find('1');
	if(pos==npos) a="0";
	else a=a.substr(pos,a.size());
}
ll func(string s1,string s2){
	ll cnt1=0,cnt2=0;
	for(int i=0;i<(int)s1.size();i++) cnt1=(cnt1+qp(2,(ll)s1.size()-i-1)*(s1[i]-'0'))%mod;
	for(int i=0;i<(int)s2.size();i++) cnt2=(cnt2+qp(2,(ll)s2.size()-i-1)*(s2[i]-'0'))%mod;
	return (cnt2-cnt1+1+mod)%mod;
}
ll dp[N][2],f[N];
void init(string s){
	int n=int(s.size());
	f[n]=0;for(int i=n-1;i>=0;i--) f[i]=f[i+1]+(s[i]=='0');
}
string a,b;
ll dfs(int pos,int limit){
	int n=int(a.size());
	if(pos==n) return 1;
	if(dp[pos][limit]!=-1) return dp[pos][limit];
	int high=(limit==1?(a[pos]-'0'):(1));
	ll ans=0;
	for(int i=0;i<=high;i++){
		int nl=limit&&(i==a[pos]-'0');
		if(b[pos]=='1'){
			if(i==0) continue;
			else ans=(ans+dfs(pos+1,nl))%mod;
		}
		else{
			if(nl==1) ans=(ans+dfs(pos+1,nl))%mod;
			else ans=(ans+qp(2,f[pos+1]))%mod;
		}
	}
	return dp[pos][limit]=ans;
}
ll cal(string s){		//solve s and s3
	a="";b="";
	size_t len=max(s.size(),s3.size());
	a=string(len-s.size(),'0')+s;
	b=string(len-s3.size(),'0')+s3;
	init(b);memset(dp,-1,sizeof(dp));
	return dfs(0,1);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>l>>r>>tar;
	change(s1,l);change(s2,r);change(s3,tar);
	ll ans=0;
	if(s3.find('1')==npos) ans=func(s1,s2);
	else{
		ll cnt1=cal(s2),cnt2=0;
		if(s1.find('1')==npos) cnt2=0;
		else sub(s1),cnt2=cal(s1);
		ans=(cnt1-cnt2+mod)%mod;
	}
	cout<<ans;
	return 0;
}

