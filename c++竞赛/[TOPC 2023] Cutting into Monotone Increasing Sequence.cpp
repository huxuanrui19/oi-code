#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
const int N=1e5+10;
lll maxn=1e20;
ull bb;
lll b,n,pos=0,dp[N],x[N];
string s;
lll change(string t){
	lll ans=0;
	for(int i=1;i<t.size();i++){
		ans*=(lll)10;
		ans+=t[i]-'0';
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>s;cin>>bb;
	b=bb;n=s.size();s=" "+s;
	if(b==0&&change(s)==0){
		cout<<"0";return 0;
	}
	else if(b==0){
		cout<<"NO WAY";return 0;
	}
	pos=floor(log10(bb))+1;
	if(pos>n||(pos==n&&change(s)<=b)){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n-pos;i++) dp[i]=maxn;
	int flag=0;
	for(int i=n-pos+1;i<=n;i++) dp[i]=0,x[i]=change(" "+s.substr(i,n));
	if(change(" "+s.substr(n-pos+1,n))>b) dp[n-pos+1]=maxn,x[n-pos+1]=0,flag=1;
	for(int i=(flag?n-pos+1:n-pos);i>=1;i--){
		for(int j=1;j<=min(pos,n-i);j++){
			if(s[i+j]=='0') continue;
			lll num=change(" "+s.substr(i,j));
			if(num<=x[i+j]){
				if(dp[i+j]+1<dp[i]){
					x[i]=num;
					dp[i]=dp[i+j]+1;
				}
				else if(dp[i+j]+1==dp[i]){
					if(x[i]<num){
						x[i]=num;
						dp[i]=dp[i+j]+1;
					}
				}
			}
		}
	}
	if(dp[1]==maxn) cout<<"NO WAY";
	else cout<<(ll)(dp[1]);
	return 0;
}
