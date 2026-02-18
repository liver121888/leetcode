class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        // ransomNote and magazine consist of lowercase English letters.
        vector<int> v(26, 0);
        for (const auto& character : magazine) {
            v[character-'a']++;
        }

        for (const auto& character : ransomNote) {
            v[character-'a']--;
            if (v[character - 'a'] < 0)
                return false;
        }
        return true;
        
    }
};