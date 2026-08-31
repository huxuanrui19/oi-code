#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll n,p,cnt,l[N],r[N],x[N<<1],a[N],ans[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
	cin>>p;
	for(int i=1;i<=p;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		int lt=lower_bound(x+1,x+p+1,l[i])-x;
		int rt=upper_bound(x+1,x+p+1,r[i])-x-1;
		if(rt-lt+1>2){
			cout<<"impossible";
			return 0;
		}
		a[i]=rt-lt+1;
	}
	for(int i=1;i<n;i++){
		bool flag=binary_search(x+1,x+p+1,r[i]);
		if(r[i]==l[i+1]&&a[i]<2&&a[i+1]<2&&(!flag)){
			ans[++cnt]=r[i];
			a[i]++;a[i+1]++;
		}
	}
	r[0]=-1;l[n+1]=1e18;
	for(int i=1;i<=n;i++){
		if(a[i]==2) continue;
		else{
			if(l[i]==r[i-1]){
				if(binary_search(x+1,x+p+1,l[i]+1)) ans[++cnt]=l[i]+2;
				else ans[++cnt]=l[i]+1;
			}
			else{
				if(binary_search(x+1,x+p+1,l[i])) ans[++cnt]=l[i]+1;
				else ans[++cnt]=l[i];
			}
			a[i]++;
			if(a[i]==2) continue;
			if(r[i]==l[i+1]){
				if(binary_search(x+1,x+p+1,r[i]-1)) ans[++cnt]=r[i]-2;
				else ans[++cnt]=r[i]-1;
			}
			else ans[++cnt]=r[i];
		}
	}
	sort(ans+1,ans+cnt+1);
	cout<<cnt<<"\n";
	for(int i=1;i<=cnt;i++) cout<<ans[i]<<" ";
	return 0;
}
