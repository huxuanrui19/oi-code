#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
const int N=1e5+10,M=50;
vector<int> g[N];
int ind[N];
lll gcd(lll p,lll q){
	if(q!=0) return gcd(q,p%q);
	else return p;
}
struct node{
	lll p,q;
	void init1() {p=1,q=1;}
	void init2() {p=0;q=1;}
	void cal(lll new_p,ll new_q){
		lll tmq=q*new_q;
		lll tmp=q*new_p+p*new_q;
		lll tmd=gcd(tmp,tmq);
		tmq/=tmd;
		tmp/=tmd;
		p=tmp;
		q=tmq;
	}
}ans[N];
void write(lll x){
	if(x==0) return;
	write(x/10);
	cout<<int(x%10);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int u;
			cin>>u;
			g[i].push_back(u); 
			ind[u]++;
		}
	}
	queue<int> q; 
	for(int i=1;i<=m;i++){
		q.push(i);
		ans[i].init1();
	}
	for(int i=m+1;i<=n;i++) ans[i].init2();
	set<int> s;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(g[u].empty()){
			s.insert(u);
			continue;
		}
		else{
			int out=g[u].size();
			lll newp=ans[u].p;
			lll newq=ans[u].q*out;
			for(auto v:g[u]){
				ans[v].cal(newp,newq);
				ind[v]--;
				if(ind[v]==0) q.push(v);
			}
		}
	}
	for(auto d:s){
		write(ans[d].p);
		cout<<" ";
		write(ans[d].q);
		cout<<"\n";
	}
	return 0;
}

