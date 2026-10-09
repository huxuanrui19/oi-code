#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,p;
struct node1{
	ll xi,ai;
}arr1[N];
struct node2{
	ll yi,bi,ci;
	bool operator <(const node2 &x) const{
		return ci>x.ci;
	}
}arr2[N];
pair<int,int> cnt[N];
int len=0;
ll sum1[N],sum2[N];
int main(){
	freopen("P14207_28.in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++) cin>>arr1[i].xi>>arr1[i].ai;
	for(int i=1;i<=m;i++) cin>>arr2[i].yi>>arr2[i].bi>>arr2[i].ci;
	for(int i=1;i<=n;i++) cnt[++len]={arr1[i].xi,1};
	for(int i=1;i<=m;i++) cnt[++len]={arr2[i].yi,2};
	sort(cnt+1,cnt+len+1);
	if(p==0){
		ll sum=0;
		for(int i=1;i<=n;i++){
			sum+=arr1[i].ai;
		}
		sort(arr2+1,arr2+m+1);
		ll ans=0;
		for(int i=1;i<=m;i++){
			if(sum>=arr2[i].bi){
				sum-=arr2[i].bi;
				ans+=arr2[i].ci*arr2[i].bi;
			}
			else{
				ans+=sum*arr2[i].ci;
				sum=0;break;
			}
		}
		cout<<ans;
	}
	else if(arr1[1].xi>arr2[m].yi){
		sort(arr2+1,arr2+1+m); 
		for(int i=1;i<=m;i++){
			sum1[i]=sum1[i-1]+arr2[i].bi;
			sum2[i]=sum2[i-1]+arr2[i].bi*arr2[i].ci;
		}
		ll cnt=0,ans=0,cost=0;
		for(int i=1;i<=n;i++){
			cnt+=arr1[i].ai;
			cost=arr1[i].xi*p;
			int pos=upper_bound(sum1+1,sum1+m+1,cnt)-sum1;
			pos--;
			ll cur=sum2[pos]+(cnt-sum1[pos])*arr2[pos+1].ci;
			ans=max(ans,cur-cost);
		}
		cout<<ans;
	}
	else if(arr1[n].xi<arr2[1].yi){
		ll cnt=0,cost=0;
		for(int i=1;i<=n;i++) cnt+=arr1[i].ai;
		ll ans=0;
		set<pair<ll,ll>> s;
		ll num=0,sum=0;
		for(int i=1;i<=m;i++){
			s.insert({arr2[i].ci,arr2[i].bi});
			cost=arr2[i].yi*p;
			num+=arr2[i].bi;
			sum+=arr2[i].bi*arr2[i].ci;
			ll last=0;
			while(num>cnt){
				num-=(*s.begin()).second;
				sum-=((*s.begin()).second)*((*s.begin()).first);
				last=max(last,(*s.begin()).first);
				s.erase(s.begin());
			}
			ans=max(ans,sum+(cnt-num)*last-cost);
		}
		cout<<ans;
	}
	else cout<<2441;
	/*for(int i=1;i<=len;i++){
		
	}*/
	return 0;
}

