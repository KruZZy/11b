#include <bits/stdc++.h>

using namespace std;

ifstream in("tari.in");

int cul[100], /// cul[7] = 3 -> tara 7 are culoarea 3
    N;
bool A[100][100];

void greedy() {
    bool m[15]; /// m[3] = 1 -> tara i are un vecin colorat cu 3
    for(int i = 2; i <= N; i++) {
        for(int k = 1; k < 10; k++)
            m[k] = 0;
        for(int j = 1; j <= i-1; j++)
            if(A[i][j] && cul[j] != 0) /// am gasit vecin colorat
                m[cul[j]] = 1;

        int k = 0;
        while(m[++k]); /// cat timp apare culoarea

        cul[i] = k;
    }

    for(int i = 1; i <= N; i++)
        cout << "Tara " << i << " are culoarea " << cul[i] << '\n';
}

int main()
{
    in >> N;
    int x, y;
    while(in >> x >> y)
        A[x][y] = A[y][x] = 1;

    cul[1] = 1;

    greedy();
    return 0;
}
