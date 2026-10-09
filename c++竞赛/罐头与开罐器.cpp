#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll cnt,len1,len2,maxn[N],pre[N];
bool cmp(ll x,ll y){return x>y;}
struct thi{
	ll type,val;
	bool operator <(const thi &x)const{
		if(type==x.type) return val>x.val;
		else return type<x.type;
	}
}a[N];
struct lis{
	ll sum,vol,fail;
	bool operator <(const lis &x) const{
		if(x.sum==sum) return vol<x.vol;
		return sum>x.sum;
	}
}l[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].type>>a[i].val;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i].type==2){
			maxn[++cnt]=a[i].val;
		}
		else l[++len1]=(lis){a[i].val,a[i].type,-1};
		if(a[i].type==0){
			pre[++len2]=a[i].val;
		}
	}
    sort(maxn+1,maxn+cnt+1,cmp); 
	sort(l+1,l+len1+1);
	sort(pre+1,pre+len2+1,cmp);
	for(int i=1;i<=cnt;i++){
		maxn[i]+=maxn[i-1];
	}
    for(int i=1;i<=len2;i++){
        pre[i]+=pre[i-1];
    }
	l[0]={0,0,0};
	ll pt=0;
	for(int i=1;i<=len1;i++){
		l[i].sum+=l[i-1].sum;
		if(l[i].vol==0) l[i].fail=++pt;
		else l[i].fail=l[i-1].fail;
		l[i].vol+=l[i-1].vol;
	}
	ll res=0;
	for(int i=0;i<=m;i++){
		ll all=maxn[i],lt=0,rt=min((m-i)*1ll,len1),ans=0;
		while(lt<=rt){
			ll mid=(lt+rt)>>1;
			if(l[mid].vol<=all){
				lt=mid+1;
				ans=mid;
			}
			else rt=mid-1;
		}
		ll tmp=l[ans].sum;
		ll rem=m-i-ans;
		ll sta=l[ans].fail;
        if(sta+rem>len2) tmp+=pre[len2]-pre[sta];
		else tmp+=pre[sta+rem]-pre[sta];
		res=max(res,tmp);
	}
	cout<<res;
	return 0;
}
