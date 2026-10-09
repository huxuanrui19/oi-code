#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,a[N],b[N],cntb[N];
int main(){
	//freopen("2.in","r",stdin);
	//freopen("22.ans","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(cntb,0,sizeof(cntb));
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		if(n==1){
			cout<<"Yes\n";
		}
		else if(n==2){
			if(a[1]+b[1]==m||a[1]+b[2]==m||a[2]+b[1]==m||a[2]+b[2]==m||b[2]+b[1]==m) cout<<"Yes\n";
			else cout<<"No\n";
		}
		else{
			for(int i=1;i<=n;i++) cntb[b[i]]++;
			queue<int> q;
			for(int i=1;i<=n;i++){
				if(cntb[m-a[i]]){
					cntb[m-a[i]]--;
				}
				else q.push(i);
			}
			for(int i=1;i<=m;i++){
				if(cntb[i]&&cntb[m-i]){
					int se=min(cntb[i],cntb[m-i]);
					if(i==m-i) se/=2;
					cntb[i]-=se;cntb[m-i]-=se;
				}
			}
			int flag=0;
			for(int i=1;i<=m;i++){
				if(cntb[i]) flag=1;
			}
			if(flag) cout<<"No\n";
			else if(q.empty()) cout<<"Yes\n";
			else{
				int flag=0,base=a[q.front()],siz=q.size();q.front();
				while(!q.empty()){
					if(base!=a[q.front()]) flag=1;
					q.pop();
				}
				if(siz==2) cout<<"Yes\n";
				else if(!flag) cout<<"Yes\n";
				else cout<<"No\n";
			}
		}
	}
	return 0;
}
