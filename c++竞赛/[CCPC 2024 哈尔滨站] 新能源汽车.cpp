#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll t,n,m,a[N];
struct st{
	ll x,t;
}sta[N];
struct node{
	ll id,now,s; //电池编号，电量，充电站编号 
	bool operator > (const node &x) const{
		return s>x.s;
	}
};
queue<int> nxt[N];  //最近的充电站 
priority_queue<node,vector<node>,greater<node> > p,q; //p有电，q没电 
inline void init(){
	while(!p.empty()) p.pop();
	while(!q.empty()) q.pop();
	for(int i=0;i<=n;i++){
		while(!nxt[i].empty()) nxt[i].pop();
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--){
		init();
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=m;i++) cin>>sta[i].x>>sta[i].t;
		for(int i=1;i<=m;i++) nxt[sta[i].t].push(i);
		for(int i=1;i<=n;i++){
			nxt[i].push(m+1);
			p.push((node){i,a[i],nxt[i].front()});
			nxt[i].pop();
		}
		ll ans=0;
		for(int i=1;i<=m;i++){
			while(ans<sta[i].x&&!p.empty()){
				node cur=p.top();p.pop();
				if((cur.now+ans)>sta[i].x){
					cur.now-=(sta[i].x-ans);
					ans=sta[i].x;
					p.push(cur);
				}
				else{
					ans+=cur.now;
					cur.now=0;
					q.push(cur);
				}
			}
			if(ans<sta[i].x&&p.empty()) break;
			if(!p.empty()&&p.top().id==sta[i].t){
				node u=p.top();p.pop();
				u.now=a[u.id];u.s=nxt[u.id].front();
				p.push(u);nxt[u.id].pop();
			}
			else if(!q.empty()&&q.top().id==sta[i].t){
				node u=q.top();q.pop();
				u.now=a[u.id];u.s=nxt[u.id].front();
				p.push(u);nxt[u.id].pop();
			}
		}
		while(!p.empty()) ans+=p.top().now,p.pop();
		cout<<ans<<"\n";
	}
	return 0;
}

