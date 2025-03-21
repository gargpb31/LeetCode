class Solution {
public:
    struct Node{
        Node* link[2];
        bool flag=false;
        bool containskey(char c){
            return link[c-'0']!=NULL;
        }
        Node* get(char c){
            return link[c-'0'];
        }
        void put(char c, Node* node){
            link[c-'0']=node;
        }
        void end(){
            flag=true;
        }
        bool checkend(){
            return flag;
        }


    };

    class Trie{
        private: Node* root;

        public:
        Trie(){
            root=new Node();
        }
        void insert(string word){
            Node* node=root;

            for(int i=0; i<word.size(); i++){
                if(!node->containskey(word[i])){
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
            node->end();
        }
        int maxXor(string word){
            Node* node=root;
            int count=0;
            int g = 31;
            for(int i=0; i<word.size(); i++){
                if(word[i]=='0'){
                    if(node->containskey('1')){
                        count+=pow(2,g-i);
                        node=node->get('1');
                    }
                    else{
                        node=node->get('0');
                    }
                }
                else{
                      if(node->containskey('0')){
                        count+=pow(2,g-i);
                        node=node->get('0');
                    }
                    else{
                        node=node->get('1');
                    }
                }
            }
            return count;
        }



    };

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int g=0;
        map<pair<int,int>,vector<int>> m;
        for(auto it : queries){
            m[{it[0],it[1]}].push_back(g);
            g++;
        }
        g=0;
       set<pair<int,int>> v;
        for(auto it : queries){
                v.insert({it[1],it[0]});
        }
        
        vector<int> ans(queries.size(),-1);
        Trie* tr = new Trie();
        for(auto it : v){
            cout<<it.first<<" "<<it.second<<endl;
        }

        for(auto it : v){
            
            while(g < nums.size() && nums[g] <= it.first){
                bitset<32> b(nums[g]);
                string s = b.to_string();
                tr->insert(s);
                g++;

            }
            if(g==0){
               for(auto it2 : m[{it.second,it.first}]){
                 ans[it2]=-1;
                }
            }
            else{
                bitset<32> b1(it.second);
                string s1 = b1.to_string();
                for(auto it2 : m[{it.second,it.first}]){
                 ans[it2]=tr->maxXor(s1);
                }
            }
        }
        return ans;
    }
};