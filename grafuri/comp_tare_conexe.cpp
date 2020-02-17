#include <bits/stdc++.h>

using namespace std;

ifstream in("graf.in");

const int N = 100;
int n, m;

int main()
{
    bool a[N][N] = {0}, v[N];
    int x, y;
    in >> n >> m;

    while(m--) {
        in >> x >> y;
        a[x][y] = 1;
    }


    for(int k = 1; k <= n; k++)  /// k intermediar
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                a[i][j] |= (a[i][k] && a[k][j]); /// exista drum i->k si drum k->j sau drum i->j

    for(int i = 1; i <= n; i++)
        if(!v[i]) {
            cout << "Componenta: " << i << ' ';
            v[i] = 1;

            for(int j = 1; j <= n; j++)
                if(!v[j] && a[i][j] && (a[i][j] == a[j][i])) {
                    v[j] = 1;
                    cout << j << ' ';
                }
            cout << '\n';
        }
    return 0;
}
