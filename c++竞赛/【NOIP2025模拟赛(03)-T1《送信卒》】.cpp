#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e2+10;
const ld eps=1e-4;
ll n,m,sx,sy,tx,ty,a[N][N];
ld s,k,dis[N][N];
struct node{
	ld t;
	int x,y;
	bool operator > (const node& p) const{
		return t>p.t;
	}
};
priority_queue<node,vector<node>,greater<node> >q;
void mve(int x,int y,ld f){
	if(a[x][y]||x<=0||y<=0||x>n||y>m||dis[x][y]<=f+eps) return;
	dis[x][y]=f;
	q.push(node{f,x,y});
	return;
}
bool check(ld nowk){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=1e9;
		}
	}
	dis[sx][sy]=0;
	q.push(node{0,sx,sy});
	while(!q.empty()){
		node u=q.top();
		q.pop();
		int tox=u.x,toy=u.y;
		ld tot=u.t;
		mve(tox,toy-1,tot+1);
		mve(tox,toy+1,tot+1);
		mve(tox-1,toy,tot+nowk);
		mve(tox+1,toy,tot+nowk);
	}
	return s<=dis[tx][ty]+eps;
}
int main()
{
	cin>>n>>m;
	cin>>sx>>sy>>tx>>ty;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	cin>>s;
	ld l=0,r=s,ans=0;
	while(l+eps<=r){
		ld mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid;
		}
		else{
			l=mid;
		}
	} 
	printf("%.3Lf",ans);
	return 0;
}

