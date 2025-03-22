class Solution {
public:

    struct Node{
        Node* link[26];
        bool flag=false;

        Node* get(char c){
            return link[c-'a'];
        }
        void put(char c, Node* node){
            link[c-'a'] = node;
        }
        void end(){
            flag=true;
        }
        bool checkend(){
            return flag;
        }
        bool containskey(char c){
            return link[c-'a']!=NULL;
        }
    };

    class Trie{

        private: Node* root;
        public: 
        Trie(){
            root=new Node();

        }
        void insert(string word){
            Node* node = root;
            for(int i=0; i<word.size(); i++){
                if(!node->containskey(word[i])){
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
            node->end();
        }
        void func(string s,Node* node,set<string> &s1){
            int count=0;
            for(int i=0; i<26; i++){
                char c = 'a'+i;

                if(node->containskey(c)){
                    count++;
                }
            }
            if(count==0 || count>1){
                    s1.insert(s);
            }
            else{
                 for(int i=0; i<26; i++){
                char c = 'a'+i;

                if(node->containskey(c)){
                   Node* node2 = node->get(c);
                   func(s+c,node2,s1);
                }
                }
            }
        }
       string ans(){
             Node* node = root;
             set<string> s;
            string ss = "";
            func(ss,root,s);
            if(s.empty()){
                return "";
            }
            else{
                return *s.begin();
            }
        }

    };

    string longestCommonPrefix(vector<string>& strs) {
        Trie* tr = new Trie();

        for(auto it : strs){
            if(it=="") return "";
            tr->insert(it);
        }
        return tr->ans();
    }
};