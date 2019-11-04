#include <bits/stdc++.h>

using namespace std;

int N;

int v[100][100], n;

int lin[] = {0, -2, -1, 1, 2, 2, 1, -1, -2}, col[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

int nrPosibCont(int l, int c)
{
    int nr = 0;
    for(int k = 1; k <= 8; k++)
    {
        int nL = l + lin[k],
            nC = c + col[k];

        if(nL >= 1 && nL <= n && nC >= 1 && nC <= n)
            if(v[nL][nC] == 0)
                nr++;
    }
    return nr;
}

int main()
{
    cout << "Marimea tablei: ";
    cin >> n;

    int l = 1,
        c = 1;
    v[1][1] = 1;

    for(int i = 2; i <= n*n-1; i++)
    {
        int minMut = 10, dir = 0;
        for(int k = 1; k <= 8; k++)
        {
            int nL = l + lin[k],
                nC = c + col[k];

            if(nL >= 1 && nL <= n && nC >= 1 && nC <= n)
                if(v[nL][nC] == 0)
                {
                    int nr = nrPosibCont(nL, nC);
                    if(nr != 0 && nr < minMut)
                    {
                       minMut = nr;
                       dir = k;
                    }

                }
        }

        l += lin[dir];
        c += col[dir];
        v[l][c] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << setw(4) << (v[i][j] == 0 ? n*n : v[i][j]);
        cout << endl;
    }

    return 0;
}
