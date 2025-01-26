class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int n = chars.size();
        for (int i = 0; i < n;) {
            char letter = chars[i];
            int count = 0;
            while (i < n && letter == chars[i]) {
                i++;
                count++;
            }
            if (count > 1) {
                chars[ans++]=letter;
                for (int len : to_string(count)) {
                    chars[ans++] = len;
                }
            } else {
                chars[ans++] = letter;
            }
        }
        return ans;
    }
};