#include <bits/stdc++.h>

using namespace std;

ifstream in("dictionar.in");

const int NMAX = 100;

char dict[NMAX][25], s[NMAX*26];
int nrCuv[NMAX*26], prec[NMAX*26],
    N, M;

bool cuv(int i, int j) {
    char t[100];
    strncpy(t, s+i, j-i+1);
    t[j-i+1] = 0;

    for(int i = 1; i <= M; i++)
        if(strcmp(dict[i], t) == 0)
            return 1;
    return 0;
}

void tipar(int k) {
    if(prec[k] > 1)
        tipar(prec[prec[k-1]]);
    for(int i = prec[k]; i <= k; i++)
        cout << s[i];
    cout << ' ';
}

int main()
{
    in >> s+1 >> M;
    N = strlen(s+1);
    for(int i = 1; i <= M; i++)
        in >> dict[i], cout << dict[i] << '\n';

    for(int j = 1; j <= N; j++)
        for(int i = 1; i <= j; i++)
            if(cuv(i, j))
                if(i == 1 || nrCuv[i-1] > 0)
                    if(nrCuv[j] == 0 || nrCuv[j] > nrCuv[i-1]+1) {
                        nrCuv[j] = nrCuv[i-1]+1;
                        prec[j] = i;
                    }


    cout << nrCuv[N];

    tipar(N);
    return 0;
}
