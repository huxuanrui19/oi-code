#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll len,cnt[N];
struct node{
	int idx,num;
}arr[N]; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		cnt[tmp]++;
	}
	for(int i=1;i<N;i++){
		if(cnt[i]>=1){
			arr[++len].idx=i;
			arr[len].num=cnt[i];
		}
	}
	ll l=1,r=len,ans=0;
	while(r-l>=2){
		ll t=min(arr[l].num,arr[r].num);
		arr[l].num-=t;
		arr[l+1].num+=t;
		ans+=t;
		if(!arr[l].num){
			l++;
			if(r-l<2){
				ans+=t-1;
				break; 
			}
		}
		arr[r].num-=t;
		arr[r-1].num+=t;
		ans+=t; 
		if(!arr[r].num){
			r--;
			if(r-l<2){
				break; 
			}
		}
	}
	cout<<ans<<" "<<arr[l].idx<<" "<<arr[r].idx; 
	return 0;
}
