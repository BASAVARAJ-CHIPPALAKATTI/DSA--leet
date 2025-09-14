class Solution {
public:
    unordered_set<string>samematch;
    unordered_map<string,string>lowercase;
    unordered_map<string,string>vowels;

    string lowerword(string word){
        string l;
        for(char c : word){
            l.push_back(tolower(c));
        }
        return l;
    }
    string vowelword(string word){
        string v;
        for(char c : word){
            if(c=='a'|| c=='e'||c=='i'||c=='o'||c=='u'){
                v.push_back('*');
            }
            else{
                v.push_back(c);
            }
        }
        return v;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for(string &word : wordlist){
            samematch.insert(word);

            string lower=lowerword(word);
            if(!lowercase.count(lower)){
                lowercase[lower]=word;
            }

            string maskword=vowelword(lower);
            if(!vowels.count(maskword)){
                vowels[maskword]=word;
            }
        }
        vector<string>ans;
        for(string query :queries){
            if(samematch.count(query)){
                ans.push_back(query);
                continue;
            }
            string lower=lowerword(query);
            if(lowercase.count(lower)){
                ans.push_back(lowercase[lower]);
                continue;
            }
            string maskword=vowelword(lower);
            if(vowels.count(maskword)){
                ans.push_back(vowels[maskword]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};