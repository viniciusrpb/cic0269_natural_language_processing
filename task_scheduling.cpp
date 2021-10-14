#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main()
{
    int n;
    vector<pii> tasks;
    
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        int duracao, deadline;
        scanf("%d %d",&duracao,&deadline);

        tasks.push_back(make_pair(duracao,deadline));
    }

    sort(tasks.begin(), tasks.end());

    int t=0,ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + tasks[i].second-tasks[i].first-t;
        t=t+tasks[i].first;
        printf("%d\n",ans);
    }

    printf("%d\n",ans);
    return 0;
}
