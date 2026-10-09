#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
struct apple{
	int x,y;
}a[N]; 
bool cmp(apple p,apple q){
	return p.y<q.y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,s,aa,b;
	cin>>n>>s>>aa>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	int i=0,cnt=0;
	while(i<n){
		i++;
		if(a[i].x<=aa+b&&a[i].y<=s){
			cnt++;
			s-=a[i].y;
		}
	}
	cout<<cnt;
	return 0;
}

