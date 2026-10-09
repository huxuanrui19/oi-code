#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m,cnt,a[N],nxt[N][180],pos[N],pri[N],idx[N],sum0[N],sum2[N];
vector<int> d[N];

void pre(){
	for(int i=2;i<=1000;i++){
		int tmp=i;
		for(int j=2;j*j<=tmp;j++){
			if(tmp%j==0){
				d[i].push_back(j);
				while(tmp%j==0){
					tmp/=j;
				}
			}
		}
		if(tmp>1){
			d[i].push_back(tmp);
		}
		if(tmp==i&&i>1){
			pri[++cnt]=i;
			idx[i]=cnt;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=cnt;j++){
			nxt[i][j]=n+1;
		}
		for(auto j:d[a[i]]){
			if(pos[j]){
				for(int k=1;k<=cnt;k++){
					nxt[i][k]=min(nxt[i][k],nxt[pos[j]][k]);
				}
				nxt[i][idx[j]]=pos[j];
			}
			pos[j]=i;
		}
	}
	return;
} 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum0[i]=sum0[i-1]+(a[i]==0);
		sum2[i]=sum2[i-1]+(a[i]>1);
	}
	pre();
	
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		if(x==y) cout<<"Shi\n";
		else if(a[x]==1||a[y]==1) cout<<"Fou\n";
		else if(a[x]==0||a[y]==0){
			if(sum2[y]-sum2[x-1]) cout<<"Shi\n";
			else cout<<"Fou\n";
		}
		else if(sum0[y]-sum0[x-1]) cout<<"Shi\n";
		else{
			int flag=0;
			for(auto j:d[a[y]]){
				if(nxt[x][idx[j]]<=y){
					flag=1;
					break;
				}
			}
			if(flag) cout<<"Shi\n";
			else cout<<"Fou\n";
		}
	}
	return 0;
}

