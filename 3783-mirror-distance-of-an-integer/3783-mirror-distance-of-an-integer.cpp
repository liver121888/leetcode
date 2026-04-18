class Solution {
public:


    int mirrorDistance(int n) {

        int mirror = 0;
        int original = n;
        while (original) {
            mirror = 10 * mirror + original % 10;
            original /= 10;
        }

        return abs(mirror - n);
        
    }
};