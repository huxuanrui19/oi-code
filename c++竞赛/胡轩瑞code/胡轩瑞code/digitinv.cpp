#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;

ll a[10];
ll cal(int x){
	ll ans=0;
	for(int i=1;i<=x;i++){
		int num=i,cnt=0;
		while(num){
			a[++cnt]=num%10;
			num/=10;
		}
		for(int i=1;i<=cnt;i++){
			bool flag=0;
			for(int j=1;j<cnt;j++){
				if(a[j]<a[j+1]){
					swap(a[j],a[j+1]);
					flag=1;
					ans++;
				}
			}
			if(flag==0) break;
		}
	}
	return ans;
}

string l,r;
ll tree[20];
inline ll lowbit(ll x){return x&(-x);}
void update(ll pos,ll d){
	while(pos<20){
		tree[pos]+=d;
		pos+=lowbit(pos);
	}
}
ll query(ll pos){
	ll ans=0;
	while(pos){
		ans+=tree[pos];
		pos-=lowbit(pos);
	}
	return ans;
}
ll solve(string s){
	int n=s.size();
	s=' '+s;
	memset(tree,0,sizeof(tree));
	ll ans=0;
	for(int i=n;i>=1;i--){
		ans+=query(s[i]-'0');
		update(s[i]-'0'+1,1);
	}
	return ans;
}
int main() {
	freopen("digitinv.in","r",stdin);
	freopen("digitinv.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>l>>r;
		if(l==r){
			cout<<solve(l)<<"\n";
		}
		else if(r.size()<=6||r=="1000000"){
			ll rnum,lnum;rnum=lnum=0;
			for(auto ch:r){
				rnum*=10;
				rnum+=ch-'0';
			}
			for(auto ch:l){
				lnum*=10;
				lnum+=ch-'0';
			}
			ll ans=cal(rnum)-cal(lnum-1);
			cout<<ans<<"\n";
		}
	}
	return 0;
}

