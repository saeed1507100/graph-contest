#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    ifstream f("in.txt");
    f>>n;
    int u,s,m[n][n],i,j,a,b,d[n],p[n],inf=1000006;
    char c[n];

    //initialize mtx with 0
    for(int i=0;i<n;i++)
        for(int j =0;j<n;j++)
    {
        m[i][j]=0;
    }

    //creating adj. matrx
    for(;f>>a>>b;)
    {
        m[a][b]=1;
    }

    //Bfs
    queue<int> q;
    cin>>s;
    c[s] = 'g'; d[s] = 0; p[s] = -1;
    q.push(s);

    for(i=0;i<n;i++)
    {
        if(i!=s)
        {
            c[i] = 'w';
            d[i] = inf;
            p[i] = -1;
        }
    }

    while(!q.empty())
    {
        u = q.front(); q.pop();
        for(i=0;i<n;i++)
        {
            if(m[u][i]!=0)
            {
                if(c[i]=='w')
                {
                    q.push(i);
                    d[i] = d[u]+1;
                    cout<<"distance of "<<i<<" "<<d[i]<<"\n";
                    p[i] = u;
                    c[i] = 'g';
                }
            }
        }
        c[u] = 'b';
    }


    cout << "Hello world!" << endl;
    return 0;
}
