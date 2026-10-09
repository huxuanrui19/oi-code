#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}
const int N=2e6+10;
int tag[N];
ll length[N],xpos[N];
struct ScanLine{
	ll y,leftx,rightx;
	int inout;
	ScanLine(){};
	ScanLine(ll y,ll x1,ll x2,ll io):
		y(y),leftx(x1),rightx(x2),inout(io){};
	bool operator <(const ScanLine &a) const{
		return y<a.y;
	}
}line[N];
void push_up(int p,int pl,int pr){
	if(tag[p]) length[p]=xpos[pr]-xpos[pl];
	else if(pl+1==pr) length[p]=0;
	else length[p]=length[ls(p)]+length[rs(p)];
}
void update(int l,int r,int io,int p,int pl,int pr){
	if(l<=pl&&pr<=r){
		tag[p]+=io;
		push_up(p,pl,pr);
		return;
	}
	if(pl+1==pr) return;
	int mid=(pl+pr)>>1;
	if(l<=mid) update(l,r,io,ls(p),pl,mid);
	if(r>mid) update(l,r,io,rs(p),mid,pr);
	push_up(p,pl,pr);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1,x1,x2,y1,y2;i<=n;i++){
		cin>>x1>>y1>>x2>>y2;
		line[++cnt]=ScanLine(y1,x1,x2,1);
		xpos[cnt]=x1;
		line[++cnt]=ScanLine(y2,x1,x2,-1);
		xpos[cnt]=x2;
	}
	sort(xpos+1,xpos+cnt+1);
	sort(line+1,line+cnt+1);
	int num=unique(xpos+1,xpos+cnt+1)-(xpos+1);
	memset(tag,0,sizeof(tag));
	memset(length,0,sizeof(length));
	ll ans=0;
	for(int i=1;i<=cnt;i++){
		int l,r;
		ans+=length[1]*(line[i].y-line[i-1].y);
		l=lower_bound(xpos+1,xpos+num+1,line[i].leftx)-xpos;
		r=lower_bound(xpos+1,xpos+num+1,line[i].rightx)-xpos;
		update(l,r,line[i].inout,1,1,num);
	}
	cout<<ans;
	return 0;
}

