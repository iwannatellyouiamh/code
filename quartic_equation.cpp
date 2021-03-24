#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define endl '\n'

float a, b, c, d, e;

int main()
{
    //input
    cout << "enter coefficient of your quartic equation (There is a space between a pair of coefficient): ";
    cin >> a >> b >> c >> d >> e;
    //solving
    float D0 = c*c - 3*b*d + 12*a*e;
    float D1 = 2*c*c*c - 9*b*c*d + 27*b*b*e + 27*a*d*d - 72*a*c*e;
    float medium = D1*D1 - 4*D0*D0*D0;
    if (medium < 0)
    {
        cout << "Your equation don't have any real roots";
        return 0;
    }
    float Q = cbrt((D1 - sqrt(medium)) / 2);
    float p = (8*a*c - 3*b*b) / (8*a*a);
    float q = (b*b*b - 4*a*b*c + 8*a*a*d) / (8*a*a*a);
    float medium2 = -2*p/3 + (Q+D0/Q)/(3*a);
    if (medium2 < 0)
    {
        cout << "Your equation don't have any real roots";
        return 0;
    }
    float S = sqrt(medium2)/2;
    float medium3 = -4*S*S - 2*p + q/S;
    float medium4 = -4*S*S - 2*p - q/S;
    //output
    if (medium3 >= 0)
    {
        cout.precision(9);
        float x1 = -b/(4*a) - S + sqrt(medium3)/2;
        float x2 = -b/(4*a) - S - sqrt(medium3)/2;
        cout << "your equation has solution x1 = "<< fixed << x1 << endl;
        cout << "your equation has solution x2 = "<< fixed << x2 << endl;
    } else cout << "lol can't find real value of x1 and x2" << endl;
    if (medium4 >= 0)
    {
        cout.precision(9);
        float x3 = -b/(4*a) - S + sqrt(medium4)/2;
        float x4 = -b/(4*a) - S - sqrt(medium4)/2;
        cout << "your equation has solution x3 = "<< fixed << x3 << endl;
        cout << "your equation has solution x4 = "<< fixed << x4 << endl;
    } else cout << "lol can't find real value of x3 and x4" << endl;
}
