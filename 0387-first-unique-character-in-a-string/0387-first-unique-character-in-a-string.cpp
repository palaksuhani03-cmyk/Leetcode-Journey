class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        queue<int> q;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            q.push(i);
        }

        while (!q.empty()) {
            int index = q.front();

            if (freq[s[index] - 'a'] == 1)
                return index;

            q.pop();
        }

        return -1;
    }
};