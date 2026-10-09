#include<bits/stdc++.h>
using namespace std;
int time(int hh,int mm)
{
	return hh*60+mm;
}
struct mac{
	string num;
	int t;
}m[100005];
int macc[1445],d[1445];
bool comp(mac a,mac b)
{
	return a.t<b.t;
}
unordered_map<string,int> ma;
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		string s,t;
		int hh,mm;
		cin>>s>>t;
		m[i].num=s;
		hh=(t[0]-'0')*10+t[1]-'0';
		mm=(t[3]-'0')*10+t[4]-'0';
		m[i].t=time(hh,mm);
	}
	sort(m+1,m+n+1,comp);
	int maxl=-1;
	/*for(int i=1;i<=n;i++)
	{
		for(int j=max(m[i].t,ma[m[i].num]+k);j<min(1441,m[i].t+k);j++)
		{
			macc[j]++; 
		}
		ma[m[i].num]=m[i].t;
	}*/
	for(int i=1;i<=n;i++)
	{
		if(max(m[i].t,ma[m[i].num]+k)>min(1441,m[i].t+k)+1)
		{
			continue;
		}
		d[max(m[i].t,ma[m[i].num]+k)]+=1;
		d[min(1441,m[i].t+k)]-=1;
		ma[m[i].num]=m[i].t;
	}
	for(int i=1;i<=1440;i++)
	{
		macc[i]=d[i]+macc[i-1];
		maxl=max(maxl,macc[i]);
	}
	cout<<maxl;
	return 0;
}
