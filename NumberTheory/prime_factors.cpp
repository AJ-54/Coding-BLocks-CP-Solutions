//This code generates prime factor ki powers of a given number

 
map<ll,ll> prime(ll n)  
{  
    map<ll,ll> v;
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        v[2]++;  
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i*i<=n; i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            v[i]++; 
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        v[n]++;
    return v;  
} 
 