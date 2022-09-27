
void findPrimes(int n)
{
    // Return if number is not even or less than 3

    if (n <= 2 || n % 2 != 0)
    {
        cout << "Invalid Input \n";
        return;
    }
    vector<int> primes = sieveOfEratosthenes(n);
    // Check only upto half of number
    for (int i = 0; primes[i] <= n / 2; i++)
    {
        // find difference by subtracting current prime from n
        int diff = n - primes[i];

        // Search if the difference is also a prime number
        if (binarySearch(primes, 0, primes.size() - 1, diff))
        {
            // Express as a sum of primes
            cout << primes[i] << " + " << diff << " = "
                 << n << endl;
            return;
        }
    }
}
