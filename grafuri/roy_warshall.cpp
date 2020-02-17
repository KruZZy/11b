#include <bits/stdc++.h>

using namespace std;

ifstream in("graf.in");

const int N = 100;
int n, m;

int main()
{
    bool a[N][N] = {0};
    int x, y, comp[N] = {0}, nrCompTC = 0;
    in >> n >> m;

    while(m--) {
        in >> x >> y;
        a[x][y] = 1;
    }


    for(int k = 1; k <= n; k++)  /// k intermediar
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                a[i][j] |= (a[i][k] && a[k][j]); /// exista drum i->k si drum k->j sau drum i->j

    int vf = 1;
    do {
        nrCompTC++;
        comp[vf] = nrCompTC;
        cout << "Componenta tare conexa nr: " << nrCompTC << ": " << vf << ' ';
        for(int i = 1; i <= n; i++)
            if(a[i][vf] && a[i][vf] == a[vf][i] && comp[i] == 0) {
                comp[i] = nrCompTC;
                cout << i << ' ';
            }
        cout << '\n';
        while(comp[++vf] != 0 && vf <= n);
    } while(vf <= n);

    return 0;
}
