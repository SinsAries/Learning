#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=m;++i){
        if (i==1&&i<=n-1){
            for (int j=1;j<=n;++j){
                cout<<"*";
            }
            cout<<'\n';
        }
        if (i>=2&&i<=n-1){
            for(int j=1;j<=m;++j){
                if (j==1){
                    cout<<"*";
                }
                if (j>=2&&j<=m-1){
                    cout<<" ";

                }
                if (j==m){
                    cout<<"*";
                cout<<'\n';
                }
            }
        }
        if(i==n){
            for (int j=1;j<=m;++j){
                cout<<"*";
            }
            cout<<'\n';
        }
    }
}