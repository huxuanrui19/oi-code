#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int r,q,n,m;	//排名，队伍数，人数，总名额 
		cin>>r>>q>>n>>m;
		int base=m/3;
		int all=q*n;
		if(m/3>=n){
			if(r<=m) cout<<"Yes\r\n";
			else cout<<"No\r\n";
		}
		else{
			if((r-1)>all){
				int res=r-1-q*n;
				if((res+base*q+1)<=m) cout<<"Yes\r\n";
				else cout<<"No\r\n";
			}
			else{
				int maxn=(r-1)/n;
				int res=(r-1)%n;
				int cnt=maxn*base+min(res,base)+1;
				if(cnt<=m) cout<<"Yes\r\n";
				else cout<<"No\r\n";
			}
		}
	}
	return 0;
}

