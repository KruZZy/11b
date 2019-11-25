#include <bits/stdc++.h>

using namespace std;

const int N = 100;

ifstream in("cuvinte.in");

char s[N], d[N];
int c[N][N], nrOp[N][N],
    n, m;


int cmp(int m, int n) {
    if(c[m][n] != 0) return c[m][n];

    if(m == 0) return c[0][n] = n;
    if(n == 0) return c[m][0] = m;
    if(s[m] == d[n]) return cmp(m-1, n-1);
    return c[m][n] = 1 + min({
                             cmp(m-1, n), /// stergere
                             cmp(m-1, n-1), /// inlocuire
                             cmp(m, n-1) /// inserare
                            });
}

int lev(int m, int n) {
    for(int i = 0; i <= m; i++)
        nrOp[i][0] = i;
    for(int i = 0; i <= n; i++)
        nrOp[0][i] = i;

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(s[i] == d[j])
                nrOp[i][j] = nrOp[i-1][j-1];
            else nrOp[i][j] = 1 + min({
                                        nrOp[i-1][j], /// stergere
                                        nrOp[i-1][j-1], /// inlocuire
                                        nrOp[i][j-1] /// inserare
                                      });
    return nrOp[m][n];
}

int main()
{
    in >> s+1 >> d+1;
    m = strlen(s+1);
    n = strlen(d+1);

    cout << cmp(m, n) << '\n';
    cout << lev(m, n);
    return 0;
}
