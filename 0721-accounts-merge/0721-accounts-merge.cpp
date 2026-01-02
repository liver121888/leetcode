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

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // build the graph first
        unordered_map<string, vector<string>> db;
        for (const auto& account : accounts) {
            string accountFirstEmail = account[1];
            for (int i = 2; i < account.size(); i++) {
                string email = account[i];
                db[accountFirstEmail].push_back(email);
                db[email].push_back(accountFirstEmail);
            }
        }

        // DFS
        unordered_set<string> visited;
        stack<string> dfs;
        vector<vector<string>> mergedAccounts;
        for (vector<string>& account : accounts) {
            string accountName = account[0];
            string accountFirstEmail = account[1];

            if (visited.find(accountFirstEmail) == visited.end()) {
                // not visit
                vector<string> mergedAccount;
                mergedAccount.push_back(accountName);

                dfs.push(accountFirstEmail);
                visited.insert(accountFirstEmail);
                mergedAccount.push_back(accountFirstEmail);

                while(!dfs.empty()) {
                    string email = dfs.top();
                    dfs.pop();
                    auto neighbors = db[email];
                    for (auto neighbor : neighbors) {
                        if (visited.find(neighbor) == visited.end()) {
                            // not visited
                            dfs.push(neighbor);
                            visited.insert(neighbor);
                            mergedAccount.push_back(neighbor);
                        }
                    }
                }

                sort(mergedAccount.begin() + 1, mergedAccount.end());
                mergedAccounts.push_back(mergedAccount);
            }

        }

        return mergedAccounts;

    }
};