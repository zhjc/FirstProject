
//*****// ≈≈–ÚÀ„∑®

// ≤Â»Î≈≈–Ú
void InsertSort(int a[], int l, int r)
{
    int tmp = 0;

    for (int i = l + 1; i <= r; ++i)
    {
        tmp = a[i];
        int j;

        for (j = i - 1; j >= l && a[j] > tmp; j--)
        {
            a[j + 1] = a[j];
        }

        a[j + 1] = tmp;
    }

    return;
}

// √∞≈›≈≈–Ú
void BubbleSort(int a[], int l, int r)
{
    int tmp;
    for (int i = l; i < r; ++i)
    {
        for (int j = i; j < r - 1; ++j)
        {
            if (a[j]>a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

// —°‘Ò≈≈–Ú
void SelectSort(int a[], int l, int r)
{
    int i, j, nmin, tmp;

    for (i = l; i < r; i++)
    {
        nmin = i;
        for (j = i + 1; j <= r; ++j)
        {
            if (a[j] < a[nmin])
            {
                nmin = j;
            }
        }

        tmp = a[i];
        a[i] = a[nmin];
        a[nmin] = tmp;
    }
}

// πÈ≤¢≈≈–Ú

// øÏÀŸ≈≈–Ú

// œ£∂˚≈≈–Ú

// ∂—≈≈–Ú

// Õ∞≈≈–Ú