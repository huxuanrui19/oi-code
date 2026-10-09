#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N],d[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("Ææ±äÅ¼²»±ä.in","r",stdin); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		d[l]++;
		d[r+1]--;
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		d[i]+=d[i-1];
		if(d[i]>0){
			if(a[i]%2==1) a[i]++;
		}
		sum+=a[i];
	}
	cout<<sum;
	fclose(stdin);
	return 0;
}

