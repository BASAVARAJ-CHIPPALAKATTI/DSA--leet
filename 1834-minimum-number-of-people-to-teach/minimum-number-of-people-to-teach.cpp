class Solution {
public:
    // easy
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sad_user;

        for (auto &it : friendships) {
            int u = it[0] - 1; //-1 because we nee to st from 0
            int v = it[1] - 1;
            unordered_set<int> lang(languages[u].begin(), languages[u].end());
            bool talk = false;

            for (int a : languages[v]) {
                if (lang.count(a)) {
                    talk = true;
                    break;
                }
            }
            if (!talk) {
                sad_user.insert(u);
                sad_user.insert(v);
            }
        }
        // we need to find max one lang speak most people
        vector<int> language(n + 1, 0);
        int mostKnownLang = 0;

        for (int user : sad_user) {
            for (int lang : languages[user]) {
                language[lang]++;
                mostKnownLang = max(mostKnownLang, language[lang]);
            }
        }

        return sad_user.size() - mostKnownLang;
    }
};