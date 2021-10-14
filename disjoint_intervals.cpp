#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<pii> intervalos;
int n;

bool ordena_segundo(pii a, pii b) 
{ 
    return a.second < b.second; 
} 

int solve() 
{
    int ans;
    
    sort(intervalos.begin(), intervalos.end(), ordena_segundo); 
  
    int lim_sup_inicio = intervalos[0].second; 
    
    ans = 1;
  
    for (int i = 1; i < intervalos.size(); i++)
    { 
        int lim_inf_inicio = intervalos[i].first; 
        int lim_sup_final = intervalos[i].second; 
  
        if (lim_inf_inicio > lim_sup_inicio) { 
            lim_sup_inicio = lim_sup_final;
            ans++;
        } 
    }
    return ans;
} 

int main() 
{ 
    int inicio,fim;
    
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d",&inicio,&fim);
        intervalos.push_back(make_pair(inicio,fim));
    }
    
    printf("%d\n",solve());
  
    return 0; 
}
