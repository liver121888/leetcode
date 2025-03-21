// class Solution {
// public:

//     struct edge {
//         vector<string> needs;
//         edge() { }
//     };

//     vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

//         // a graph problem
//         unordered_map<string, edge*> graph;

//         for (int i = 0; i < recipes.size(); i++) {
//             edge* cur = new edge();
//             graph[recipes[i]] = cur;
//             for (auto ing : ingredients[i]) {
//                 cur->needs.push_back(ing);
//             }
//         }

//         // supplies are the ing that does not need anything
//         // for (auto sup : supplies) {
//         //     edge* cur = new edge();
//         //     graph[sup] = cur;
//         // }

//         stack<string> dfs;
//         vector<string> result;
//         auto sups = unordered_set(supplies.begin(), supplies.end());

//         for (auto recipe : recipes) {

//             dfs.push(recipe);
//             unordered_set<string> visited;

//             bool canMade = true;
//             while (!dfs.empty()) {
//                 auto cur = dfs.top();
//                 cout << cur << endl;
//                 dfs.pop();
//                 visited.insert(cur);
//                 auto needIngredients = graph[cur]->needs;
//                 for (auto ing : needIngredients) {

//                     if (sups.find(ing) == sups.end()) {
//                         // not raw material

//                         if (visited.find(ing) == visited.end()) {
//                             // does not visit

//                             if (graph.find(ing) != graph.end()) {
//                                 // exist in graph
//                                 dfs.push(ing);
//                             } else {
//                                 // does not exist
//                                 canMade = false;
//                                 break;
//                             }
//                         } else {
//                             // cycle check
//                             canMade = false;
//                             break;
//                         }

//                     }

//                 }
//                 if (!canMade)
//                     break;
//             }

//             // reset dfs
//             while (!dfs.empty())
//                 dfs.pop();
            
//             // reset visited
//             visited.clear();
            
//             if (canMade) 
//                 result.push_back(recipe);
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        // Use ingredients as starts

        // Store available supplies
        unordered_set<string> availableSupplies;
        // Map recipe to its index
        unordered_map<string, int> recipeToIndex;
        // Map ingredient to recipes that need it
        unordered_map<string, vector<string>> dependencyGraph;

        // Initialize available supplies
        for (string& supply : supplies) {
            availableSupplies.insert(supply);
        }

        // Create recipe to index mapping
        for (int idx = 0; idx < recipes.size(); idx++) {
            recipeToIndex[recipes[idx]] = idx;
        }

        // Count of non-supply ingredients needed for each recipe
        vector<int> inDegree(recipes.size(), 0);

        // Build dependency graph
        for (int recipeIdx = 0; recipeIdx < recipes.size(); recipeIdx++) {
            for (string& ingredient : ingredients[recipeIdx]) {
                if (!availableSupplies.count(ingredient)) {
                    // Add edge: ingredient -> recipe
                    dependencyGraph[ingredient].push_back(recipes[recipeIdx]);
                    inDegree[recipeIdx]++;
                }
            }
        }

        // Start with recipes that only need supplies
        queue<int> queue;
        for (int recipeIdx = 0; recipeIdx < recipes.size(); recipeIdx++) {
            if (inDegree[recipeIdx] == 0) {
                queue.push(recipeIdx);
            }
        }

        // Process recipes in topological order
        vector<string> createdRecipes;
        while (!queue.empty()) {
            int recipeIdx = queue.front();
            queue.pop();
            string recipe = recipes[recipeIdx];
            createdRecipes.push_back(recipe);

            // Skip if no recipes depend on this one
            if (!dependencyGraph.count(recipe)) continue;

            // Update recipes that depend on current recipe
            for (string& dependentRecipe : dependencyGraph[recipe]) {
                if (--inDegree[recipeToIndex[dependentRecipe]] == 0) {
                    queue.push(recipeToIndex[dependentRecipe]);
                }
            }
        }

        return createdRecipes;
    }
};

