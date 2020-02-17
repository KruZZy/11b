#include <bits/stdc++.h>

using namespace std;

ifstream in("graf.in");

const int N = 100;
int n, m;

void show(bool a[][N]) {
    for(int i = 1; i <= n; i++, cout << '\n')
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
}

int main()
{
    bool a[N][N] = {0};
    int x, y;
    in >> n >> m;

    while(m--) {
        in >> x >> y;
        a[x][y] = 1;
    }
    show(a);

    for(int k = 1; k <= n; k++)  { /// k intermediar
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                a[i][j] |= (a[i][k] && a[k][j]); /// exista drum i->k si drum k->j sau drum i->j
        cout << "\nTransformarea: " << k << '\n';
        show(a);
    }

    return 0;
}
