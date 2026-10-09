#include<bits/stdc++.h>
using namespace std;
struct node{
	int d;
	node *next;
};
int main()
{
	int n,m;
	cin>>n>>m;
	node *head,*p,*cur,*pre;
	head=new node;
	head->d=1;
	head->next=NULL;
	cur=head;
	for(int i=2;i<=n;i++)
	{
		p=new node;
		p->d=i;
		p->next=NULL;
		cur->next=p;
		cur=p;
	}
	cur->next=head;
	pre=cur;
	cur=head;
	while((n--)>1)
	{
		for(int i=1;i<m;i++)
		{
			pre=cur;
			cur=cur->next;
		}
		cout<<cur->d<<" ";
		pre->next=cur->next;
		delete cur;
		cur=pre->next;
	}
	cout<<cur->d;
	delete cur;
	return 0;
}
