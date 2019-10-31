#include <bits/stdc++.h>

using namespace std;

ifstream in("siruri.in");

int a[100], b[100],
    m, n;

void mySort(int x[], int n) {

}

int main()
{
    in >> m >> n;

    for(int i = 1; i <= m; i++)
        in >> a[i];
    for(int i = 1; i <= n; i++)
        in >> b[i];

    int sumProd = 0;

    sort(a+1, a+m+1);
    mySort(b, n);

    int i = 1;
    while(a[i] <= 0 && i <= m) {
        cout << a[i] << '*' << b[i] << " + ";
        sumProd += a[i] * b[i];
        i++;
    }

    for(; i <= m; i++) {
        cout << a[i] << '*' << b[i+(n-m)] << " + ";
        sumProd += a[i] * b[i+(n-m)];
    }
    cout << " = " << sumProd;
    return 0;
}
