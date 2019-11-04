#include <bits/stdc++.h>

using namespace std;

ifstream in("elevi.in");

const int N = 20;

void gray(char c[][22], char b[], char G[], int n) {
    G[1] = b[1];

    for(int i = 2; i <= n; i++)
        G[i] = (b[i]+b[i-1])%2;

    for(int i = 1; i <= N; i++)
        if(G[i] == 1)
            cout << c[i] << ' ';
    cout << '\n';
}

int main()
{
    int n;
    char cuv[N][22],
         b[N] = {0},
         G[N];

    in >> n;
    for(int i = 1; i <= n; i++)
        in >> cuv[i];

    for(int i = 1, j = (1 << n); i <= j; i++) { /// 1 << n -> 10..0 (n-1 zerouri) -> 2^n.
        gray(cuv, b, G, n);
        int k = n;

        while(b[k] == 1 && k > 0)
            b[k--] = 0; /// sau b[k] = 0, k--; simulare adunare 1 in baza 2 -> cat timp gasim biti de 1 ii facem 0

        b[k] = 1;
    }
    return 0;
}
