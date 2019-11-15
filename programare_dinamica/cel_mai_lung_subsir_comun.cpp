#include <iostream>
#include <fstream>

using namespace std;

ifstream in("siruri.in");

const int N = 100;

int a[N], b[N], lg[N+1][N+1];
int main()
{
    int m, n;
    in >> m;
    for(int i = 1; i <= m; i++)
        in >> a[i];
    in >> n;
    for(int i = 1; i <= n; i++)
        in >> b[i];

    for(int i = m; i >= 1; i--)
        for(int j = n; j >= 1; j--)
            if(a[i] == b[j])
                lg[i][j] = lg[i+1][j+1] + 1;
            else lg[i][j] = max(lg[i+1][j], lg[i][j+1]);
    int col = 0, /// col = coloana pe care am gasit un element comun
        mx = lg[1][1];
    cout << lg[1][1] << '\n';
    for(int i = 1; i <= m && mx != 0; i++)
        for(int j = col+1; j <= n; j++)
            if(lg[i][j] == mx && a[i] == b[j]) {
                cout << a[i] << ' ';
                col = j;
                mx--;
                break;
            }
    return 0;
}
