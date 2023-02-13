class Solution {
    public int countOdds(int low, int high) {
        if (!(low % 2 == 0 ? true : false) && !(high % 2  == 0 ? true : false))
            return (high - low + 1)/2 + 1;
        else
            return (high - low + 1)/2;
    }
}