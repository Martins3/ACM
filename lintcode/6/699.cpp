class Solution {
public:
    bool isprime(int x) {
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }
    /**
     * @param n: an int
     * @param k: an int
     * @return: if n can be expressed in the form of sum of k primes, return true; otherwise, return false.
     */
    bool isSumOfkPrimes(int n, int k) {
        if (n < 2 * k)
            return false;
 
        if (k == 1)
            return isprime(n);
 
        if (k == 2) {
            if (n % 2 == 0)
                return true;
            return isprime(n - 2);
        }
        return true;

        }
};
