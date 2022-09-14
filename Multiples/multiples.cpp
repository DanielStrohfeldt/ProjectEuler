#include <iostream>
#include <cmath>
#include <vector>

using namespace std; 

int main ()
{
    int sum = 0;
    for (int a = 1; a < 1000; a++)
    {
        if (((a % 3) == 0) ||
            ((a % 5) == 0))
        {
            sum += a;
        }
    }
    cout << "Total : " << sum << "\n";
};
