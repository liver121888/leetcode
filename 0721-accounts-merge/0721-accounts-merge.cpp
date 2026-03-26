// name -> multiple accounts
// we can have duplicate names, but we can identify them 
// as different person through the email

// we can treat email as node, and the name is the group
// we connect the emails that share the same person

// "John","johnsmith@mail.com","john_newyork@mail.com"
// create two nodes and connect them with a edge
// "johnsmith@mail.com"
// "john_newyork@mail.com"

// we also create a reverse hashmap so we can lookup the name with email
// "johnsmith@mail.com" -> John
// "john_newyork@mail.com" -> John

// create one node and connect the new node with old one with a edge
// ["John","johnsmith@mail.com","john00@mail.com"

// ["John","johnnybravo@mail.com"]]
// "johnnybravo@mail.com" -> John

// build a bi-direcitonal graph
// "johnsmith@mail.com" -> "john_newyork@mail.com"
// "john_newyork@mail.com" ->"johnsmith@mail.com"

// how do I enumerating the connected components of this graph?
// I can call dfs on every thing, calculate successful traverse

// 以email為節點
// dfs on connected component
// class Solution {
// public:
//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

//         // build the graph first
//         unordered_map<string, vector<string>> db;
//         for (const auto& account : accounts) {
//             string accountFirstEmail = account[1];
//             for (int i = 2; i < account.size(); i++) {
//                 string email = account[i];
//                 db[accountFirstEmail].push_back(email);
//                 db[email].push_back(accountFirstEmail);
//             }
//         }

//         // DFS
//         unordered_set<string> visited;
//         stack<string> dfs;
//         vector<vector<string>> mergedAccounts;
//         for (vector<string>& account : accounts) {
//             string accountName = account[0];
//             string accountFirstEmail = account[1];

//             if (visited.find(accountFirstEmail) == visited.end()) {
//                 // not visit
//                 vector<string> mergedAccount;
//                 // 先放名子
//                 mergedAccount.push_back(accountName);

//                 dfs.push(accountFirstEmail);
//                 visited.insert(accountFirstEmail);
//                 mergedAccount.push_back(accountFirstEmail);

//                 while(!dfs.empty()) {
//                     string email = dfs.top();
//                     dfs.pop();
//                     auto neighbors = db[email];
//                     for (auto neighbor : neighbors) {
//                         if (visited.find(neighbor) == visited.end()) {
//                             // not visited
//                             dfs.push(neighbor);
//                             visited.insert(neighbor);
//                             mergedAccount.push_back(neighbor);
//                         }
//                     }
//                 }

//                 sort(mergedAccount.begin() + 1, mergedAccount.end());
//                 mergedAccounts.push_back(mergedAccount);
//             }

//         }

//         return mergedAccounts;

//     }
// };


// name -> multiple accounts
// we can have duplicate names, but we can identify them 
// as different person through the email

// we can treat email as node, and the name is the group
// we connect the emails that share the same person

// "John","johnsmith@mail.com","john_newyork@mail.com"
// create two nodes and connect them with a edge
// "johnsmith@mail.com"
// "john_newyork@mail.com"

// we also create a reverse hashmap so we can lookup the name with email
// "johnsmith@mail.com" -> John
// "john_newyork@mail.com" -> John

// create one node and connect the new node with old one with a edge
// ["John","johnsmith@mail.com","john00@mail.com"

// ["John","johnnybravo@mail.com"]]
// "johnnybravo@mail.com" -> John

// build a bi-direcitonal graph
// "johnsmith@mail.com" -> "john_newyork@mail.com"
// "john_newyork@mail.com" ->"johnsmith@mail.com"


// Disjoint Set Union (DSU)
// only email is unique
// name can repeat

// 所以這裡沒有在 union email
// 這很重要。
// 很多人會混掉。
// 這份解法不是：
// email 跟 email union
// 而是：
// account 跟 account union
// email 只是拿來當作：
// 判斷兩個 account 是否相連的橋樑

class DSU {

private:
    vector<int> parents;
    vector<int> ranks;

public:
    DSU(int n): parents(n), ranks(n) {
        for (int i = 0; i < n; ++i) {
            // Initially each group is its own representative
            parents[i] = i;
            // Intialize the size of all groups to 1
            ranks[i] = 1;
        }
    }

    int find(int s) {
        if (parents[s] != s)
            parents[s] = find(parents[s]);

        return parents[s];
    }

    void unionByRank(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return;

        // connect small to the larger
        if (ranks[pa] >= ranks[pb]) {
            ranks[pa] += ranks[pb];
            parents[pb] = pa;
        } else {
            ranks[pb] += ranks[pa];
            parents[pa] = pb;
        }
        
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DSU dsu = DSU(n);

        unordered_map<string, int> emailGroup;

        // union 
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string name = accounts[i][0];
                string email = accounts[i][j];

                if (emailGroup.find(email) == emailGroup.end()) {
                    emailGroup[email] = i;
                } else {
                    dsu.unionByRank(i, emailGroup[email]);
                }
            }
        }

        // Store emails corresponding to the component's representative
        // 把email歸到某個component內
        // 其實就是map出 name_idx -> vector<string> mails
        // 透過account之間的關係
        unordered_map<int, vector<string>> components;
        for (auto emailIterator : emailGroup) {
            string email = emailIterator.first;
            int group = emailIterator.second;
            components[dsu.find(group)].push_back(email);
        }

        // Sort the components and add the account name
        vector<vector<string>> mergedAccounts;
        for (auto componentIterator : components) {
            // account index
            int group = componentIterator.first;
            // 取出該account的name放進component, 因為name可重複但index不行
            vector<string> component = {accounts[group][0]};
            // 把所有mail放進來
            component.insert(component.end(), componentIterator.second.begin(), 
                             componentIterator.second.end());
            // sort mail
            sort(component.begin() + 1, component.end());
            mergedAccounts.push_back(component);
        }

        return mergedAccounts;
        
    }


};

