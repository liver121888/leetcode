

// the cleanest, 巨鬼
class Solution {
public:
    std::string intToRoman(int num) {
        std::vector<std::string> thousands = {"", "M", "MM", "MMM"};
        std::vector<std::string> hundreds = {"",  "C",  "CC",  "CCC",  "CD",
                                             "D", "DC", "DCC", "DCCC", "CM"};
        std::vector<std::string> tens = {"",  "X",  "XX",  "XXX",  "XL",
                                         "L", "LX", "LXX", "LXXX", "XC"};
        std::vector<std::string> ones = {"",  "I",  "II",  "III",  "IV",
                                         "V", "VI", "VII", "VIII", "IX"};
        return thousands[num / 1000] + hundreds[num % 1000 / 100] +
               tens[num % 100 / 10] + ones[num % 10];
    }
};

// we traverse the string
// convert each digit with it's multiplier to the numbers
// start with the lowest digit then reverse the result string
// can also create unordered_map for mapping the numbers to the values
// class Solution {
// public:

//     const unordered_map<int, string> digit2Roman = {{1, "I"}, {2, "II"}, 
//         {3, "III"}, {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, 
//         {9, "IX"}};

//     const unordered_map<int, string> tenthDigit2Roman = {{1, "X"}, {2, "XX"}, 
//         {3, "XXX"}, {4, "XL"}, {5, "L"}, {6, "LX"}, {7, "LXX"}, {8, "LXXX"}, 
//         {9, "XC"}};


//     const unordered_map<int, string> hundredDigit2Roman = {{1, "C"}, {2, "CC"}, 
//         {3, "CCC"}, {4, "CD"}, {5, "D"}, {6, "DC"}, {7, "DCC"}, {8, "DCCC"}, 
//         {9, "CM"}};

//     const unordered_map<int, string> thousandDigit2Roman = {{1, "M"}, {2, "MM"}, 
//         {3, "MMM"}};

//     string intToRoman(int num) {
        
//         // because we know the values are <= 3999
//         // we can directly divide by 1000

//         string roman = "";
//         int digit = num % 10;
//         num /= 10;    
//         int tenthDigit = num % 10;
//         num /= 10;    
//         int hundredDigit = num % 10;
//         num /= 10;
//         int thousandDigit = num;

//         // cout << thousandDigit << " " << hundredDigit << " " << tenthDigit << " " << digit << endl;

//         if (thousandDigit) {
//             roman += thousandDigit2Roman.at(thousandDigit);
//         }

//         if (hundredDigit) {
//             roman += hundredDigit2Roman.at(hundredDigit);
//         }

//         if (tenthDigit) {
//             roman += tenthDigit2Roman.at(tenthDigit);
//         }

//         if (digit) {
//             roman += digit2Roman.at(digit);
//         }

//         return roman;

//     }
// };