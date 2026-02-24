// Clean
// We can split creating a line into two subtasks:
// Determine which words should be on the line.
// Take the words from the first task and create a line.






class Solution {
public:

    string helper(const vector<string>& currLine, int currWordLen, int maxWidth) {

        ostringstream out;
        int num_space = currLine.size() - 1;

        // check when the whole line is filled with text
        if (num_space == 0) {
            if (currWordLen == maxWidth) {
                out << currLine[0];
                return out.str();
            } else {
                num_space = 1;
            }
        }

        int fillSpace = maxWidth - currWordLen;
        // num_space can be 0
        int spaceLen = fillSpace / num_space;
        int extraSpace = fillSpace % num_space;

        // cout << num_space << " " << fillSpace << " " << spaceLen << " " << extraSpace << endl;

        for (const auto& word : currLine) {
            out << word;
            if (num_space) {
                // for (int i = 0; i < spaceLen; i++)
                //     out << " ";
                out << string(spaceLen, ' ');
                num_space--;
            } 
            if (extraSpace) {
                out << " ";
                extraSpace--;
            }
        }
        return out.str();
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;
        vector<string> currLine;
        int currWordLen = 0;
        for (const auto& word : words) {

            // int numSpace = currLine.size() - 1;
            // we also append one space
            // so essentially it's currLine.size()
            if (currLine.size() + currWordLen + word.length() > maxWidth) {
                // deal with the current line
                string line = helper(currLine, currWordLen, maxWidth);
                cout << line << endl;
                ans.push_back(line);
                currWordLen = 0;
                currLine.clear();
            }

            // update currLine
            currLine.push_back(word);
            currWordLen += word.size(); 
        }

        // final line, should be left justify
        int currLen;
        string lastLine = "";
        for (const auto& word : currLine) {
            lastLine += word;
            if (lastLine.length() < maxWidth)
                lastLine += " ";
        }

        // pad
        if (lastLine.length() < maxWidth) {
            int cnt = maxWidth - lastLine.length();
            while (cnt) {
                lastLine += " ";
                cnt--;
            }
        }
        ans.push_back(lastLine);
        return ans;
       
    }
};
