#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+10,M=1e6+10;

int cnt,head[N<<1],to[N<<1],nxt[N<<1],sta[N<<1];
inline void add_edge(int u,int v){
	sta[++cnt]=u;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}

int n;
struct ed{
	int u,v;
};
vector<ed> e[M];

int maxD,flag[N];
int dfs(int u,int fa){
	flag[u]=1;
	int ma=0,se=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue;
		int dis=dfs(v,u);
		if(dis>se) se=dis;
		if(se>ma) swap(ma,se);
	}
	maxD=max(maxD,ma+se);
	return ma+1;
}

int ans[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	memset(ans,-1,sizeof(ans));
	cin>>n;
	int maxa=0;
	for(int i=1;i<n;i++){
		int u,v,a;cin>>u>>v>>a;
		e[a].push_back({u,v});
		maxa=max(maxa,a);
	}
	for(int w=1;w<=maxa;w++){
		for(int j=1;j<=maxa/w;j++){
			for(auto d:e[j*w]){
				add_edge(d.u,d.v);
				add_edge(d.v,d.u);
			}
		}
		
		maxD=0;
		for(int i=1;i<=cnt;i++){
			if(!flag[sta[i]]){
				dfs(sta[i],0);
			}
		}
		ans[maxD]=w;
		for(int i=1;i<=cnt;i++){
			flag[sta[i]]=0;
			head[sta[i]]=0;
		}
		cnt=0;
	}
	
	for(int i=n;i>=1;i--)  ans[i]=max(ans[i],ans[i+1]);
	int t;cin>>t;
	while(t--){
		int m;cin>>m;
		cout<<ans[m]<<"\n";
	}
	return 0;
}
