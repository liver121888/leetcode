
// strs[i] contains any possible characters out of 256 valid ASCII characters.

// class Codec {
// public:

//     // Unicode is a character encoding standard that includes virtually 
//     // every character from every writing system in the world, plus many symbols, 
//     // control characters, and more.
//     // However, it's worth noting that non-ASCII characters can sometimes be tricky to handle 
//     // correctly, because not all systems or software handle non-ASCII characters 
//     // in the same way.

//     // Encodes a list of strings to a single string.
//     string encode(vector<string>& strs) {
//         string encoded;

//         for (const string& s : strs) {
//             encoded += s;
//             // use unicode string to split
//             encoded += "π";
//         }

//         return encoded;
//     }

//     // Decodes a single string to a list of strings.
//     vector<string> decode(string s) {

//         vector<string> ans;

//         istringstream is(s);
//         string token;
//         // impossible because pi cannot be put into char
//         // Line 37: Char 35: error: character too large for enclosing character literal type
//         // 37 |         while (getline(is, token, 'π')) {
//         //    |                                   ^
//         // while (getline(is, token, 'π')) {
//         //     if (!token.empty())
//         //         ans.push_back(token);
//         // }

//         // use string to have unicode
//         string delimiter = "π";
//         int start = 0;

//         while (true) {
//             int pos = s.find(delimiter, start);

//             if (pos == string::npos)
//                 break;

//             ans.push_back(s.substr(start, pos - start));

//             start = pos + delimiter.size();
//         }

//         return ans;
//     }
// };


// Escaping
// So, what's the purpose of escaping? Let's say you have a character that 
// has a special meaning in a certain context, like our delimiter /:. 
// If this character sequence appears in our original strings, it might 
// confuse our encoding and decoding process. We need a way to signal that 
// in this particular instance, we don't want to treat /: as a delimiter 
// but as a part of the original string.
// 為什麽會work
// 為什麼 escaping 可以證明正確？
// 關鍵 invariant 是：
// 在 encode string 裡，只要看到 /，下一個字元只可能有兩種合法情況：
// "//" 代表原始資料裡的一個 '/'
// "/:" 代表 string 結束 delimiter
// 而原始資料裡所有 / 都已經被轉成 //，所以原始資料不可能直接產生一個未 escaped 的 /:。
// 因此：
// "/:"
// 在 encoded string 裡一定是 delimiter。
// "//"
// 在 encoded string 裡一定是原始資料的一個 /。
// 所以 decoder 每次看到 / 都可以唯一判斷，沒有 ambiguity。

// class Codec {
// public:
//     string encode(vector<string>& strs) {
//         string encoded;

//         for (const string& s : strs) {
//             for (char c : s) {
//                 if (c == '/') {
//                     encoded += "//";   // escape slash
//                 } else {
//                     encoded += c;
//                 }
//             }

//             encoded += "/:";           // delimiter
//         }

//         return encoded;
//     }

//     vector<string> decode(string s) {
//         vector<string> ans;
//         string curr;

//         int i = 0;
//         while (i < s.size()) {
//             if (s[i] == '/') {
//                 if (s[i + 1] == '/') {
//                     curr += '/';       // escaped slash
//                     i += 2;
//                 } else if (s[i + 1] == ':') {
//                     ans.push_back(curr); // delimiter
//                     curr.clear();
//                     i += 2;
//                 }
//             } else {
//                 curr += s[i];
//                 i++;
//             }
//         }

//         return ans;
//     }
// };
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));


// length-prefix 解法
// 比較推薦
// length-prefix 解法是：
// 7#abc#def
// 這裡的 # 只用來分隔「長度區」和「內容區」。
// 一旦長度被讀出來，後面的內容完全不需要 parse delimiter。
class Codec {
public:

    // this can also encode and decode empty string
    string encode(vector<string>& strs) {
        string encoded;
        for (const auto& str : strs) {
            int strLen = str.size();
            encoded += to_string(strLen) + '#' + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            res.push_back(s.substr(j + 1, len));

            i = j + 1 + len;
        }
        return res;
    }

};