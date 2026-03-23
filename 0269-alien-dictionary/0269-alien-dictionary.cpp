// build prerequsites
// vector<unordered_set>

// w -> r, t
// e -> r, t
// r -> t, f
// w, e in degree 0
// r ingree 2
// t indegree 3
// f indgree 1

// r indgree 0
// t indgree 1
// f indgree 1

// t indgree 0
// f indegree 0

// wertf

// O(max(len(s)) ^ 2 + 26 + )

// 原本想說TWO FOR LOOP去記字串內部關係
// 但這樣是錯的
// 因為字串裡面本身是沒有排序的！

// 應該是
// algorithm, albacus
// 從這邊我們只能知道g < b
// 不能斷定 orithm 和 acus

// 只看「第一個不同字元」
// 👉 才是合法 constraint
// 2️⃣ prefix case 要特判
// 👉 否則會錯
// 會完全找不到第一個不同字元
// 👉 所以 不會建任何 edge
// 例如 abc, ab
// 如果abc 排在ab前面
// 我們可以馬上特判 reuturn ""
// 如果不特判就是自相矛盾的


class Solution {
public:

    // algorithm, albacus
    
    // g < b
    // build g -> b to indicate that g must appear before b

    // follow the normal order
    // abc, ab

    string alienOrder(vector<string>& words) {

        // only lowercase English letters.
        // create adjLists
        // sorted lexicographically

        unordered_map<char, vector<char>> adjLists;
        unordered_map<char, int> indegree;

        for (string word : words) {
            for (char c : word) {
                indegree[c] = 0;
                adjLists[c] = vector<char>();
            }
        }


        for (int i = 0; i < words.size() - 1; i++) {
            string firstWord = words[i];
            string secondWord = words[i+1];

            // we could not find the first different char
            // prefix case 根本沒有把「錯誤」表現在 graph 裡
            // so we need to handle it specially
            if (firstWord.size() > secondWord.size() &&
                firstWord.substr(0, secondWord.size()) == secondWord) {
                return "";
            }

            // find the frist different char, so we can know the order
            for (int j = 0; j < min(firstWord.size(), secondWord.size()); j++) {
                if (firstWord[j] != secondWord[j]) {
                    adjLists[firstWord[j]].push_back(secondWord[j]);
                    indegree[secondWord[j]]++;
                    break;
                }
            }

        }

        queue<char> bfs;

        for (const auto& [c, cnt] : indegree) {
            if (cnt == 0)
                bfs.push(c);
        }


        string ans = "";

        while (!bfs.empty()) {

            char curr = bfs.front();
            bfs.pop();

            ans += curr;

            for (const auto& neighbor : adjLists[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    bfs.push(neighbor);
            }
        }

        for (const auto& [c, deg] : indegree) {
            if (deg != 0)
                return "";
        }
        // both check works
        // if (ans.size() < indegree.size()) {
        //     return "";
        // }

        return ans;
    }
};