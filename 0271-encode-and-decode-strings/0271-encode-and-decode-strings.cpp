
// strs[i] contains any possible characters out of 256 valid ASCII characters.

class Codec {
public:

    // Unicode is a character encoding standard that includes virtually 
    // every character from every writing system in the world, plus many symbols, 
    // control characters, and more.
    // However, it's worth noting that non-ASCII characters can sometimes be tricky to handle 
    // correctly, because not all systems or software handle non-ASCII characters 
    // in the same way.

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;

        for (const string& s : strs) {
            encoded += s;
            // use unicode string to split
            encoded += "π";
        }

        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {

        vector<string> ans;

        istringstream is(s);
        string token;
        // impossible because pi cannot be put into char
        // Line 37: Char 35: error: character too large for enclosing character literal type
        // 37 |         while (getline(is, token, 'π')) {
        //    |                                   ^
        // while (getline(is, token, 'π')) {
        //     if (!token.empty())
        //         ans.push_back(token);
        // }

        // use string to have unicode
        string delimiter = "π";
        int start = 0;

        while (true) {
            int pos = s.find(delimiter, start);

            if (pos == string::npos)
                break;

            ans.push_back(s.substr(start, pos - start));

            start = pos + delimiter.size();
        }

        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));