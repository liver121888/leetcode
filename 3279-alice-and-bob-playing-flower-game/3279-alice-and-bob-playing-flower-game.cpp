class Solution {
public:
    long long flowerGame(int n, int m) {

        // it is not important about which lane 
        // it is important that the sum

        // Alice takes turn first

        // n = 3, m = 2 -> odd alice will win
        // n = 1, m = 1 -> alice won't win


        // so within n m constriant find all x y that 
        // x + y is odd

        // for any int i, i / 2 -> number of even n_e
        // number of odd n_o = i - i/2
        // eg 4 -> even 2 -> odd 2
        // eg 5 -> even 2 -> odd 3
        
        long long n_e = n/2;
        long long n_o = n-n_e;
        long long m_e = m/2;
        long long m_o = m-m_e;

        // n = 3, m = 2
        // n_e = 1, n_o = 2
        // m_e = 1, m_o = 1
        // ans = 1 + 2 = 3

        // n = 1, m = 1
        // n_e = 0, n_o = 1
        // m_e = 0, m_o = 1
        // ans = 0 + 0 = 0

        return n_e*m_o + n_o*m_e;       
    }
};