#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,a[N],b[N];
ll cal(int a[],int b[]){
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	int l=1,r=n,lt=1,rt=n,ans=0;
	while(l<=r||lt<=rt){
		if(a[l]>b[lt]) l++,lt++,ans+=2;
		else if(a[l]<b[lt]) l++,rt--;
		else{
			if(a[r]>b[rt]) r--,rt--,ans+=2;
			else{
				if(a[l]==b[rt]){
					ans+=r-l+1;
					return ans;
				}
				else l++,rt--;
			}
		}
	}
	return ans;
}
int main () {
	//ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	int ans1=cal(a,b),ans2=2*n-cal(b,a);
	cout<<ans1<<" "<<ans2;
	return 0;
}
