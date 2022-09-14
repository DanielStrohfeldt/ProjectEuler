#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main ()
{
    int maxFib = 4000000;
    int currentFib = 1;
    int newFib = 2;
    int fibTotal = 0;

    while ((currentFib + newFib) < maxFib)
    {
        int nextFib = currentFib + newFib;

        if ((newFib % 2) == 0)
        {
            fibTotal += newFib;
        }
        
        currentFib = newFib;
        newFib = nextFib;

        cout << "Current Fib : " << currentFib << "\t\t\tNew Fib : " << newFib << "\t\t\tFib Total : " << fibTotal << "\n";
    }
    cout << "Fib Total : " << fibTotal << "\n";
};
