#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=2e4+10;
const ll mod=(1ll<<31);
struct qu{
	ll n,m,a,idx,ans;
	bool operator <(const qu &tmp)const{
		return a<tmp.a;
	}
}arr[M];
bool cmp(qu x,qu y){
	return x.idx<y.idx;
}

struct sigma{
	ll num,val;		//num=d[val] 
	bool operator <(const sigma &tmp)const{
		return num<tmp.num;
	}
}s[N];

ll q,cnt=0,d[N],pri[N],vis[N],mu[N];
void pre(){
	vis[1]=mu[1]=1;
	for(int i=2;i<N;i++){
		if(vis[i]==0){
			pri[++cnt]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt&&pri[j]*i<N;j++){
			vis[i*pri[j]]=1;
			if(i%pri[j]==0){
				mu[i*pri[j]]=0;
				break;
			}
			mu[i*pri[j]]=-mu[i];
		}
	}		//预处理莫比乌斯函数 
	for(int i=1;i<N;i++){
		for(int j=1;j*i<N;j++){
			d[i*j]+=i;
		}
	}	//预处理因数和函数 
	for(int i=1;i<N;i++) s[i]={d[i],i};
	sort(s+1,s+N);		//对于d[i]的大小排序 
}

ll tree[N];
inline int lowbit(int x){return x&(-x);}
void upd(ll x,ll d){
	while(x<N){
		tree[x]=(tree[x]+d)%mod;
		x+=lowbit(x);
	}
}
ll query(ll x){
	ll ans=0;
	while(x){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
void update(ll &pos,ll upper){
	while(s[pos].num<=upper){
		for(int j=1;j*s[pos].val<N;j++){
			upd(j*s[pos].val,(s[pos].num*mu[j]%mod+mod)%mod);
		}
		pos++;
	}
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	pre();cin>>q;
	for(int i=1;i<=q;i++){
		cin>>arr[i].n>>arr[i].m>>arr[i].a;
		if(arr[i].m<=arr[i].n) swap(arr[i].m,arr[i].n);
		arr[i].idx=i;
	}
	sort(arr+1,arr+q+1);
	ll pos=1;
	for(int i=1;i<=q;i++){
		update(pos,arr[i].a);
		ll n=arr[i].n,m=arr[i].m,ans=0;
		for(int l=1,r;l<=n;l=r+1){
			r=min(n/(n/l),m/(m/l));
			ans=(ans+(n/l)*(m/l)%mod*((query(r)-query(l-1))%mod+mod)%mod)%mod;
		}
		arr[i].ans=ans;
	}
	sort(arr+1,arr+q+1,cmp);
	for(int i=1;i<=q;i++) cout<<arr[i].ans<<"\n";
	return 0;
}