#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (void)
{
    int n, q, count = 0;
    cin >> n >> q;
    n += 1;
    bool prime[n+1];
    //populate the arr with all int;
    memset(prime, true, sizeof(prime)); 
    prime[0] = 0;
    prime[1] = 0;
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked. 
            for (int i=p*p; i<=n; i += p) 
            {
                prime[i] = false; 
            }
        } 
    } 
    //count no of primes
    for (int i = 0; i < n; i++)
    {
        if (prime[i] == true)
            count++;
    }
    
    cout << count << endl;

    //check for prime
    for (size_t i = 0; i < q; i++)
    {
        int test;
        cin >> test;
        cout << prime[test] << endl;
    }
    
}