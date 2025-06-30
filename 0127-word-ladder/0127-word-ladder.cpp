class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;

        for(auto it : wordList)
        {
            s.insert(it);
        }

        if(s.find(endWord)==s.end()) return 0;

        string start = beginWord;

        queue<pair<string,int>> q;
        q.push({start,0});
        if(s.find(start)!=s.end()) s.erase(start);
        while(!q.empty())
        {
            string s1 = q.front().first;
            int y = q.front().second;
            if(s1==endWord) return y+1;
            q.pop();
            for(int j=0; j<s1.size(); j++)
            {
                char d = s1[j];
                for(int i=0; i<26; i++)
                {
                    char e = 'a'+i;
                    s1[j]=e;
                    if(s.find(s1)!=s.end()) 
                    {
                        q.push({s1,y+1});
                        s.erase(s1);
                     }

                }
                    s1[j]=d;
            }
        
        }
        return 0;

    }
};