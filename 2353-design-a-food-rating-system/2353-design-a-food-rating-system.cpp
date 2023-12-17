class FoodRatings {
    unordered_map<string, int> rates;
    unordered_map<string, string> types;
    unordered_map<string, set<pair<int, string>>> cuisineFoodMap;

public:

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            rates[foods[i]] = ratings[i];
            types[foods[i]] = cuisines[i];
            cuisineFoodMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
        
    }
    
    void changeRating(string food, int newRating) {
        auto id = cuisineFoodMap[types[food]].find({-rates[food], food});
        cuisineFoodMap[types[food]].erase(id);
        cuisineFoodMap[types[food]].insert({-newRating, food});
        rates[food]  = newRating;
    }
    
    string highestRated(string cuisine) {
        auto highestRated = *cuisineFoodMap[cuisine].begin();
        return highestRated.second;      
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */