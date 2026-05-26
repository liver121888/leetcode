
// To check if a number is prime or not, we simply check if 
// its divisors include anything other than 1 and the number itself. 
// If so, then it is not a prime number. This method will not scale 
// for the given limits on n. The iteration itself has O(n) time 
// complexity and for each iteration, we have the prime check which 
// takes O(sqrt(n)). This will exceed the problem's time limit. 
// Therefore, we need a more efficient solution.
// we mark the multiplier of prime as non prime
// then the rest is prime

// The outer loop will start at 2 and go up to sqrt(n). 
// This is because by that point we will have considered all 
// of the possible multiples of all the prime numbers below n.
// Sieve of Eratosthenes method

// Space Complexity: O(n)
// Time Complexity: O(sqrt(n) * loglogn + n), 
// +n is from traverse to get ans
// log(log(n)) comes from
//   For 2, we have to cross out n/2 numbers.
//   For 3, we have to cross out n/3 numbers.
//   For 5, we have to cross out n/5 numbers.
//   ...etc for each prime less than n.
class Solution {
public:
    int countPrimes(int n) {
        // that are strictly less than n
        if (n <= 2) {
            // 1 is not prime
            return 0;
        }

        // Initialize vector with n true values
        vector<bool> numbers(n, true);
        // outer loop, the numbers we are checking
        // skip 0 and 1 because we know them are not
        // 為什麼外層只跑到 sqrt(n)？
        // 因為如果一個數 x 不是質數，那它一定可以拆成：
        // x = a * b
        // 其中至少有一個因數 <= sqrt(x)。
        // 如果兩個因數都大於 sqrt(x)，那乘起來一定會大於 x，不可能。
        // 所以對於 < n 的所有 composite number，
        // 只需要用 p <= sqrt(n) 的質數去篩就夠了。
        // 更常見寫法是避免每次呼叫 sqrt(n)：
        // for (int p = 2; p * p < n; ++p)
        // 如果怕 p * p overflow，可以寫：
        // for (long long p = 2; p * p < n; ++p)

        for (int p = 2; p <= sqrt(n); ++p) {
            if (numbers[p]) {
                // start from p * p
                // 為什麼 inner loop 從 p * p 開始？
                // 因為 p 的更小倍數早就被更小的 prime 處理過了。
                // 為什麼 j += p？
                // 因為你要標記的是 p 的所有倍數。
                for (int j = p * p; j < n; j += p) {
                    // mark as not prime
                    numbers[j] = false;
                }
            }
        }

        int numberOfPrimes = 0;
        for (int i = 2; i < n; i++) {
            if (numbers[i]) {
                ++numberOfPrimes;
            }
        }

        return numberOfPrimes;

    }
};