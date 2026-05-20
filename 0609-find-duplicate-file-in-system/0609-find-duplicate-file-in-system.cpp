

// You may assume no files or directories share the same name in the same directory.
// You may assume each given directory info represents a unique directory. 
// A single blank space separates the directory path and file info.

// we can use file content to group the duplicates
// unordered_map<string, vector<string>> content -> path

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {

        unordered_map<string, vector<string>> content2files;

        for (const auto& path : paths) {
            auto idx = path.find(' ');
            if (idx != std::string::npos) {
                string folderPath = path.substr(0, idx);
                // cout << "folderPath=" << folderPath << endl;
                string files = path.substr(idx + 1, path.size());
                string token = "";
                istringstream iss(files);
                while (getline(iss, token, ' ')) {
                    if (!token.empty()) {
                        auto contentIdx = token.find('(');
                        if (contentIdx != std::string::npos) {
                            string content = token.substr(contentIdx + 1, token.size()-2);
                            // cout << "content=" << content << endl; 
                            string filename = token.substr(0, contentIdx);
                            // cout << "filename=" << filename << endl;
                            content2files[content].push_back(folderPath + '/' + filename);
                        }
                    }

                }
            }
        }

        vector<vector<string>> ans;

        for (const auto& [key, v] : content2files) {
            if (v.size() > 1) {

                vector<string> group;
                for (const auto& path : v) {
                    group.push_back(path);
                }
                ans.push_back(group);

            }

        }

        return ans;
    }
};