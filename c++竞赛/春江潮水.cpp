#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld; 
const int N=1e5+10;
ll h,n;
struct node{
	ll ti,hi;
}a[N];
bool cmp(node x,node y){
	return x.ti<y.ti;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>h>>n;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].ti>>a[i].hi;
		if(a[i].hi==0) flag=1;
	}
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ld time=0,now=h;
	priority_queue<int> q;
	for(int i=1;i<=n;i++){
		if(a[i].hi>=now) continue;
		while(time<a[i].ti){
			if(q.size()){
				if(time+(now-q.top())/q.size()<a[i].ti){
					time+=(now-q.top())/q.size();
					now=q.top();
					q.pop();
				}
				else{
					ld tmp=(a[i].ti-time)*q.size();
					now-=tmp;
					time=a[i].ti;
				}
				if(now<=0){
					printf("%.6Lf",time);
					return 0;
				}
			}
			else time=a[i].ti;
		}
		if(now>a[i].hi) q.push(a[i].hi);
	}
	while(q.size()){
		time+=(now-q.top())/q.size();
		now=q.top();
		q.pop(); 
	}
	printf("%.6Lf",time);
	return 0;
}
