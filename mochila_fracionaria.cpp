#include<bits/stdc++.h>

using namespace std;

typedef pair<double, int> pdi;

int main()
{
    double v,p;
    int n,c,ans;
    vector<pdi> pqueijo;
    vector<int> peso;
    

    scanf("%d %d",&n,&c);

    for(int i = 0; i < n; i++)
    {
        scanf("%lf %lf",&v,&p);
        pqueijo.push_back(make_pair(v/p,p));
        
    }

    sort(pqueijo.begin(),pqueijo.end());

    vector<double> loja(n,0);
    
    for(int i = n-1; i >= 0; i--)
    {
        if(pqueijo[i].second <= c)
        {
            loja[i] = 1;
            c = c - pqueijo[i].second;
        }
        else
        {
            loja[i] = ((double) c)/((double) pqueijo[i].second);
            c = 0;
        }
    }
    
    ans=0;
    for(int i = 0; i < n; i++)
    {
        if(loja[i] > 0.0)
            ans++;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
