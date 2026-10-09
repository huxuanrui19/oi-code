#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
int  a[N];
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
	sort(a+1,a+n+1);
	int len=unique(a+1,a+n+1)-a-1;
	if(len<k){
		cout<<"NO RESULT";
	}
	else{
		cout<<a[k];
	}
	return 0;
}

