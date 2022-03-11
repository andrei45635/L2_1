#include <iostream>
#include <fstream>
using namespace std;
ifstream f("in.txt");
int i, j, n, m, k, matd[21][21],adj[21][21];
#define INT_MAXI 999

//TODO:Implement this
int MOORE(int u)
{
    int l[21] Q[21];
    l[u] = 0;
    for(i=1;i<=n && i!=u;i++)
    {
        l[i]=INT_MAXI;
    }
    Q = INT_MAXI;
    return 0;
}

int main()
{
    int t[21][21];
    f >> n;
    m = 0;
    while (f >> i >> j)
    {
        adj[i][j] = 1;
        //adj[j][i] = 1; //asta doar daca e neorientat
        m++;
    }

    //creare matrice drumuri
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(adj[i][j]==0 && i!=j)
            {
                matd[i][j] = INT_MAXI;
            }
            else if(i==j)
            {
                matd[i][j]=0;
            }
            else
            {
                matd[i][j]=1;
            }
        }
    }

    //roy-floyd
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for (j = 1; j <= n; j++)
            {
                if(matd[i][k]!=INT_MAXI && matd[k][j]!=INT_MAXI&&i!=j)
                {
                    if (matd[i][j] > matd[i][k] + matd[k][j])
                    {
                        matd[i][j] = matd[i][k] + matd[k][j];
                    }
                }
            }
        }
    }

    //matricea inchiderii tranzitive
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            t[i][j]=adj[i][j];
        }
    }

    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for (j = 1; j <= n; j++)
            {
                if(t[i][j]==0)
                {
                    t[i][j]=(t[i][k]&&t[k][j]);
                }
            }
        }
    }
    //TODO: moore plus celelalte

    cout<<"Matricea de adiacenta este: "<<endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"Matricea drumurilor este: "<<endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if(matd[i][j] == INT_MAXI)
            {
                cout<<"inf"<<" ";
            }
            else
            {
                cout << matd[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout<<"Matricea inchiderii tranzitive este: "<<endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
