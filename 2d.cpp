#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int x[n][m];
	for(int i=0;i<n;i++)
    {
		for(int j=0;j<m;j++)
        {
			cin>>x[i][j];
		}
	}
	int y[n]={0},z[m]={0};
	for(int i=0;i<n;i++)
    {
		for(int j=0;j<m;j++)
        {
			if(x[i][j]==0)
            {
				y[i]=1;
				z[j]=1;
			}
		}
	}
	for(int i=0;i<n;i++)
    {
		for(int j=0;j<m;j++)
        {
			if(!(y[i]||z[j]))
            {
				x[i][j]=0;
			}
		}
	}
	for(int i=0;i<n;i++)
    {
		for(int j=0;j<m;j++)
        {
			cout<<x[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
