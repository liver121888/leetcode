class Solution {
    public int countOdds(int low, int high) {
        boolean isloweven = low % 2 == 0 ? true : false;
        boolean ishigheven = high % 2  == 0 ? true : false;
        int num = high - low + 1;
        if (isloweven && ishigheven)
            return num/2;
        else if ((!isloweven && ishigheven) || (isloweven && !ishigheven) )
            return num/2;
        else
            return num/2 + 1;
    }
}