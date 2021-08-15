#include <bits/stdc++.h>

using namespace std;

int number[70];
int number2[70];

int toSystem(unsigned int n, unsigned int digits, int number[])
{
    int index = 0;
    while (n)
    {
        number[index++] = n % digits;
        n /= digits;
    }
    return index;
}

int doAction(int digits, int len)
{
    for (int i = 0; i < len; i++)
        number2[len - i - 1] = number[i];
    for (int i = 0; i < len; i++)
    {
        number[i] += number2[i];
        if (number[i] >= digits)
        {
            number[i] -= digits;
            number[i + 1]++;
        }
    }
    if (number[len] > 0)
        len++;
    return len;
}

ifstream fin("tranpal.in");
ofstream fout("tranpal.out");

int main()
{
    int n, k;
    fin >> n >> k;

    int len = toSystem(n, k, number);

    for (int i = 1; i <= 35; i++)
    {
        len = doAction(k, len);
        bool isans = true;
        for (int i = 0; i <= len / 2; i++)
        {
            if (number[i] != number[len - i - 1])
            {
                isans = false;
                break;
            }
        }
        if (isans)
        {
            fout << i << endl;
            return 0;
        }
    }

    fout << "impossible" << endl;
    return 0;
}
