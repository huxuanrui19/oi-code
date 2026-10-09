#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("好数.ans","r",stdin);
	int x,len=0;
	while(len<1000000){
		cin>>x;
		a[++len]=x;
	}
	fclose(stdin);
	freopen("好数2.ans","r",stdin);
	
	int i=0;
	while(i<1000000){
		cin>>x;
		if(a[++i]!=x){
			cout<<i<<" "<<x<<" "<<a[i]<<" fail";
			return 0;
		}
	}
	cout<<"success";
	return 0;
}

