#include <bits/stdc++.h>
using namespace std;
int dem = 0, n, a[1001], b[1001];
void load()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = i;
    }
}
void qsort(int l, int r)
{
    int i, j, x;
    i = l;
    j = r;
    x = a[(l + r) / 2];
    while (i <= j)
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            i++;
            j--;
        }
    }
    if (l < j) qsort(l, j);
    if (i < r) qsort(i, r);
}
void runn()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1 ; j <= n; j++)
            if (a[j] > 2*a[i] && b[j] < b[i]) dem++;
    }
}
int main()
{
    load();
    qsort(1, n);
    runn();
    cout << dem << endl;
    return 0;
}

