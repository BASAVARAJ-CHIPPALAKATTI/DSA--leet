class FoodRatings {
public:
    unordered_map<string,string>food_cuisin;  //store for food in which cuisin
    unordered_map<string,int>food_rating;    //food with rating
    unordered_map<string,set<pair<int,string>>>cuisine_rating_food;  //cuisine with food and rating 
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            string food=foods[i];
            string cuisin=cuisines[i];
            int rate=ratings[i];

            food_cuisin[food]=cuisin;
            food_rating[food]=rate;
            cuisine_rating_food[cuisin].insert({-rate,food});
            //we use - reason set is stores in ascending val during  cuisin under highest rate food it will help
            // {-16,abc},{-16 xyz} {-1,abc}
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisin=food_cuisin[food];
        int old_rate=food_rating[food];

        food_rating[food]=newRating;
        cuisine_rating_food[cuisin].erase({-old_rate,food});
        cuisine_rating_food[cuisin].insert({-newRating,food});

    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_rating_food[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */