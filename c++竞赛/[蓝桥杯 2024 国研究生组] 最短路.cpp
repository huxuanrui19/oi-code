#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+10;
const ll inf=1e18;
struct mx{
	ll xlen,ylen;
	ll m[N+1][N+1];
	void init(int xl,int yl){
		xlen=xl;ylen=yl;
		for(int i=1;i<=xlen;i++){
			for(int j=1;j<=ylen;j++){
				m[i][j]=inf;
			}
		}
	}
	mx operator * (const mx& b){
		mx c;
		c.init(xlen,b.ylen);
		for(int i=1;i<=xlen;i++){
			for(int j=1;j<=b.ylen;j++){
				for(int k=1;k<=ylen;k++){
					c.m[i][j]=min(c.m[i][j],m[i][k]+b.m[k][j]);
				}
			}
		}
		return c;
	}
}ed[31];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n,q;
	cin>>n;
	for(int i=0;i<=30;i++){
		ed[i].init(n<<1,n<<1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int tmp;cin>>tmp;
			if(tmp!=0){
				ed[0].m[i][j]=ed[0].m[i+n][j+n]=tmp;
				ed[0].m[i][j+n]=tmp/2;
			}
		}
	}
	for(int i=1;i<=30;i++){
		ed[i]=ed[i-1]*ed[i-1];
	}
	cin>>q;
	while(q--){
		int x,b,c;
		cin>>x>>b>>c;
		mx ans;
		c--;
		ans.init(1,n*2);
		for(int i=1;i<=2*n;i++){
			ans.m[1][i]=ed[0].m[x][i];
		}
		for(int i=30;i>=0;i--){
			if((1<<i)&c) ans=ans*ed[i];
		}
		ll res=min(ans.m[1][b+n],ans.m[1][b]);
		if(res!=inf) cout<<res<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
