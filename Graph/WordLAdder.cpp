class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if(wordSet.find(endWord) == wordSet.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            pair<string, int> front = q.front();
            q.pop();

            string word = front.first;
            int count = front.second;

            if(word == endWord) return count;

            for(int i = 0; i < word.length(); i++) {
                string temp = word;
                for(char c = 'a' ; c <= 'z'; c++) {
                    temp[i] = c;
                    if(wordSet.find(temp) != wordSet.end()) {
                        q.push({temp, count+1});
                    }
                    wordSet.erase(temp);
                }
            }
        }

        return 0;
    }
};