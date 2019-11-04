/**
Se considera n siruri ordonate crescator, avand diferite lungimi.
Sa se obtina un singur sir alcatuit din toate numerele, de asemenea ordonat crescator, printr-o metoda optima.

Se vor efectua urmatoarele doua optimizari:
    (1): folosind metoda interclasarii pentru a obtine un sir sortat din 2 subsiruri;
    (2): la fiecare etapa se aleg cele mai mici doua subsiruri

Remarca: consideram ca fisierul date.in contine pe prima linie o valoare pentru n, iar pe urmatoarele n linii
         gasim numarul de valori ale unui sir, urmate de valorile propriu-zise.
**/

#include <bits/stdc++.h>

using namespace std;

ifstream in("date.in");

const int N = 100;

int main()
{
    int a[N][N],
        n;

    in >> n;

    for(int i = 1; i <= n; i++) {
        in >> a[i][0]; /// nr de elem.
        for(int j = 1; j <= a[i][0]; j++)
            in >> a[i][j];
    }

    for(int i = 1; i <= n-1; i++) { /// n-1 interclasari
        int min_1 = N,
            min_2 = N,
            l_1, l_2;

        for(int j = 1; j <= n; j++) {
            if(a[j][0] <= min_1) {
                min_2 = min_1;
                l_2 = l1;
                min_1 = a[j][0];
                l_1 = j;
            } else if(a[j][0] < min_2) {
                min_2 = a[j][0];
                l_2 = j;
            }
        }
    }
    return 0;
}
