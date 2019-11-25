#include <bits/stdc++.h>

using namespace std;

const int N = 100;

ifstream in("cuvinte.in");

char s[N], d[N];
int c[N][N],
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

int main()
{
    in >> s+1 >> d+1;
    m = strlen(s+1);
    n = strlen(d+1);

    cout << cmp(m, n);
    return 0;
}
