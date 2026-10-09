#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int K=25;
int a[K];
int jud(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=(1<<n);i++){
		int x=i,sum=0;
		while(x){
			if(x%2==1) sum++; 
			x>>=1;
		}
		if(sum!=k){
			continue;
		}
		x=i;sum=0;
		int j=1;
		while(x){
			if(x%2==1) sum+=a[j];
			x>>=1;
			j++;
		}
		if(jud(sum)){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

