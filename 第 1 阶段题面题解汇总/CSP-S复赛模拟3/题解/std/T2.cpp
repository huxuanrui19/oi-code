#include<bits/stdc++.h>
#define ll long long 
#define maxn 200005
#define mod 998244353
using namespace std;
int n;
ll a[maxn],wei[maxn];
ll get(ll x) {int ret=0; while (x) {ret++; x>>=1;} return max(1,ret);}
vector<pair<ll,ll>> act;  
int vis[maxn],cnt=0;
void add(int x) {vis[x]++; if (vis[x]==1) cnt++;}
void del(int x) {vis[x]--; if (vis[x]==0) cnt--;}
int main()
{
	freopen("growth.in","r",stdin); 
	freopen("growth.out","w",stdout);
	cin>>n;
	ll zd=0;
	for (int i=1;i<=n;i++) {cin>>a[i]; wei[i]=get(a[i]); zd=max(zd,wei[i]);}

	for (int i=1;i<=n;i++)
	{
		if (a[i]<=1) {cnt++; continue;} //不关心数字0和1，反正他俩万能的 
		//首先是变化到zd-1
		if (wei[i]<=zd-1)
		{
			ll cha=(zd-1)-wei[i];
			//在一个位置出现，在另一个位置消失 
			act.push_back({a[i]<<cha,i});
			act.push_back({(a[i]<<cha)|((1ll<<cha)-1),-i});
		}
		//变化到zd 
		if (wei[i]<=zd)
		{
			ll cha=zd-wei[i];
			act.push_back({a[i]<<cha,i});
			act.push_back({(a[i]<<cha)|((1ll<<cha)-1),-i});
		}
		if (wei[i]<=zd+1)
		{
			ll cha=zd+1-wei[i];
			act.push_back({a[i]<<cha,i});
			act.push_back({(a[i]<<cha)|((1ll<<cha)-1),-i});
		}
	}
	
	sort(a+1,a+n+1); 
	ll best=a[n]-a[1];
	//排序的时候也应该先消失，后出现
	sort(act.begin(),act.end());
	int r=-1; //该加入r了 
	for (int l=0;l<act.size();l++)
	{
		while (cnt<n && r+1<act.size())
		{
			r++;
			if (act[r].second>0) //是出现的信号
				add(act[r].second);
		}
		//如果够了，则这样 
		if (cnt==n) 
		{
			best=min(best,act[r].first-act[l].first);
		}
		if (act[l].second<0) 
		{
			del(-act[l].second);
		}
	}
	cout<<max(best,0ll)<<endl;
}
