#include <bits/stdc++.h>

using namespace std;


const int N = 100;
int P[N][N], S[N][N],
    m, n;

void drum(int i, int j) {
    if(i == 1 && j == 1)
        cout << i << ' ' << j << '\n';
    else {
        if(S[i-1][j] > S[i][j-1])
            drum(i-1, j);
        else drum(i, j-1);
        cout << i << ' ' << j << '\n';
    }
}

int main()
{
    cin >> m >> n;
    srand(time(NULL));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            P[i][j] = rand() % 100;
            cout << P[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n\n";
    for(int i = 1; i <= m; i++)
        S[i][1] = S[i-1][1] + P[i][1];
    for(int j = 1; j <= n; j++)
        S[1][j] = S[1][j-1] + P[1][j];

    for(int i = 2; i <= m; i++)
        for(int j = 2; j <= n; j++)
            S[i][j] = P[i][j] + max(S[i-1][j], S[i][j-1]);

    cout << S[m][n] << '\n';

    drum(m, n);
    return 0;
}
