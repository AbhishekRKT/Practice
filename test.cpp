#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
    int n1, n2;
    cin >> n1 >> n2;
    int a[n1][n2],b[n1][n2],c[n1+1][n2];
    memset(c,0,sizeof(c));
    for(int j=0; j < n1; j++){
        for(int k =0; k<n2;k++)
        {
            cin >>a[j][k];
            b[j][k] = c[j+1][k]=a[j][k];
            c[j+1][k]+=c[j][k];
        }
        for(int k = n2-2;k>=0;k--)
        {
            b[j][k]+=b[j][k+1];
        }
    }
    int A = -1;
    for(int j = n2-1;j>=0;j--)
    {
        for(int k = 0; k<n1-1;k++){
            for(int l = k+1; l<n1;l++){
                int t = c[l][j]+b[l][j];
                if(l-k>1)
                {
                    t += c[l][j]-c[k+1][j];
                }
                A = max(t,A);
            }
        }
    }
    cout << A << endl;
}