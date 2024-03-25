#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (b == 0)
    {
        *y = 0;
        *x = 1;
        return a;
    }

    int x1, y1;
    int gcd = gcdExtended(b, a%b, &x1, &y1);
    *y = x1 - (a/b) * y1;
    *x = y1;

    return gcd;
}

int main()
{
    int x, y, a, b;
    cout<<"Enter the first number:"<<endl;
    cin>>a;
    cout<<"Enter the second number"<<endl;
    cin>>b;
    int d = gcdExtended(a, b, &x, &y);
    cout << "GCD(" << a << ", " << b
        << ") = " << d << endl;
    return 0;
}