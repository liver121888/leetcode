class Solution {
public:

    unordered_map<long long, long long> remainder2decimal;
    vector<long long> ansVector;

    // 1 2
    // 1, 0
    // {0}
    // {{1, 0}}

    // 10 2
    // 0, 5
    // {0, 5}

    // 2 3
    // 2, 1
    // {1}
    // {{2, 0}}

    // 20 3
    // 2, 6
    // {{2, 0}, {1, 6}}

    long long divOperation(long long nr, long long dr, long long currDeci) {

        // cout << "dr: " << dr << ", nr: " << nr << endl;

        long long rd = nr % dr;
        long long q = nr / dr;
        ansVector.push_back(q);

        if (rd == 0)
            return -1;

        // if not first time
        if (remainder2decimal.find(rd) != remainder2decimal.end()) {
            return remainder2decimal[rd] + 1;
        } else {
            remainder2decimal[rd] = currDeci;
        }

        return divOperation(10 * rd, dr, currDeci + 1);
    }

    // 4 333 0
    // q = 0, {0}
    // {{4, 0}}

    // 40 333 1
    // q = 0, {0, 0}
    // {{4, 0}, {40, 1}}

    // 400 333 2
    // q = 1, {0, 0, 1}
    // {{4, 0}, {40, 1}, {67, 2}}

    // 670 333 4
    // q = 2, {0, 0, 1, 2}
    // {{4, 0}, {40, 1}, {67, 2}}, 

    string fractionToDecimal(int numerator, int denominator) {

        // how to do the division
        // check if we divide can get an int
        // if not, push_back 0 and times 10 and devide again
        // if we get an int and % is 0, stop

        // 1 / 2 = 0, % 1
        // reminder is not 0, we times remanider with 10, and push in the times
        // 1 * 10 = 10
        // 10 / 2 = 5, % = 0
        // remender is 0 so we stop
        // 0.5

        // 2 / 1 = 2, % = 0
        // reminder is 0, we push in the times
        // 2

        // how to know we are repeating
        // 4 333 -> 0, % = 4
        // 4 -> 40, push in 0
        // 40 333, 0, reminder is 40
        // 40 -> 400, 0.0
        // 1, 67 -> 0.01
        // 670 333 -> 2, reminder is 4, 0.012
        // 40 333 -> happens before, we stop
        // have a map to know when do we encounter this reainder, eg, happens at on 1 decimal
        // we indexing that, modify the string and then return

        if (numerator == 0)
            return "0";

        string ans = "";
        // if (numerator != 0 && ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)))
        //     ans += "-";

        if (numerator < 0 ^ denominator < 0)
            ans+="-";

        long long repeatDeci = divOperation(abs((long long)numerator), abs((long long)denominator), 0);
        // cout << "repeatDeci: " << repeatDeci << endl;

        // cout << "avSize: " <<  ansVector.size() << endl;
        long long idx = 0;
        while (idx < ansVector.size()) {

            // cout << idx << endl;
            if (idx == 1)
                ans += '.';

            long long n = ansVector[idx];

            if (idx == repeatDeci)
                ans += '(';
            ans += to_string(n);

            idx++;
        }

        if (repeatDeci != -1)
            ans += ')';

        return ans;
        
    }
};