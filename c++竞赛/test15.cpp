#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[N];
bool judge(int x){
	int cnt=0;
	memset(a,0,sizeof(a));
	while(x) a[++cnt]=x%10,x/=10;
	a[0]=0;
	for(int i=cnt;i>=1;i--){
		if(a[i]<a[i-1]) return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,res=0;
	cin>>n;
	for(int i=1;i<=n;i++) res+=judge(i);
	cout<<res;
	return 0;
}

