class Solution {
public:
    vector<int> eratosthenes(int upperLimit) {

        // initially mark all as prime
        vector<int> result(upperLimit + 1, 1);

        // mark both not as prime
        result[0] = 0;
        result[1] = 0;

        for (int n = 2; n * n <= upperLimit; n++) {
            if (result[n] == 1) {
                for (int multiple = n * n; multiple <= upperLimit; multiple += n) {
                    result[multiple] = 0;
                }
            }
        }
        return result;

    }


    vector<int> closestPrimes(int left, int right) {
        vector<int> sieveArray = eratosthenes(right);

        vector<int> primeNumbers;
        for (int num = left; num <= right; num++) {
            // If number is prime add to the primeNumbers list
            if (sieveArray[num] == 1) {
                primeNumbers.push_back(num);
            }
        }

        int minDifference = INT_MAX;
        vector<int> closestPair(2, -1);  // setting initial values

        for (int index = 1; index < primeNumbers.size(); index++) {
            int difference = primeNumbers[index] - primeNumbers[index - 1];
            if (difference < minDifference) {
                minDifference = difference;
                closestPair[0] = primeNumbers[index - 1];
                closestPair[1] = primeNumbers[index];
            }
        }

        return closestPair;
    }
};