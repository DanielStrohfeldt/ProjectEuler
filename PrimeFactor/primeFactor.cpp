#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main ()
{
    //long maxValue = 600851475143;
    long maxValue = 997;

    vector<long long> primes;
    primes.reserve((maxValue / 64) + 1);

    // Initialize Vector {false, false, true, true, true, ... true}
    for (int i = 0; i < (maxValue); i++)
    {
        bool isPrime = true;

        int internalI = i / 64;
        int internalJ = i % 64;

        if (i < 2)
        {
            isPrime = false;
        }

        if (isPrime)
        {
            primes[internalI] |= 1 << internalJ;
        }
        else
        {
            primes[internalI] |= 0 << internalJ;
        }
    }

    double maxValueF = (double)maxValue;
    long iterationMax = (long)sqrt(maxValueF);

    // Sieve of Erastothenes Implementation
    for (int i = 2; i < iterationMax; i++)
    {
        int internalI = i / 64;
        int internalJ = i % 64;

        int primeValue = primes[internalI];
        bool isPrime = (primeValue & (1 << internalJ));


        if (isPrime)
        {
            int j = i * i;
            while (j <= maxValue)
            {
                int unsetI = j / 64;
                int unsetJ = j % 64;

                int unsetMask = 1 << unsetJ;
                unsetMask = ~unsetMask;

                primes[unsetI] = primes[unsetI] & unsetMask;

                j = j + i;
            }
        }
    }

    //Find last value
    for (int i = maxValue; i > 0; i--)
    {
        int internalI = i / 64;
        int internalJ = i % 64;
        int primeValue = primes[internalI];

        bool isPrime = (primeValue & (1 << internalJ));

        if (isPrime)
        {
            maxValue = i;
            break;
        }
    }

    cout << "Max Prime : " << maxValue << "\n";
}
