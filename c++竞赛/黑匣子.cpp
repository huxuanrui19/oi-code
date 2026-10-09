#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N];
priority_queue<int,vector<int>,greater<int>> q1;
priority_queue<int,vector<int>,less<int>> q2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int la=1;
	for(int i=1;i<=m;i++){
		int cnt;
		cin>>cnt;
		for(int j=la;j<=cnt;j++){
			q2.push(a[j]);
			if(q2.size()==i){
				q1.push(q2.top());
				q2.pop();
			}
		}
		la=cnt+1;
		cout<<q1.top()<<endl;
		q2.push(q1.top());
		q1.pop();
	}
	return 0;
}

