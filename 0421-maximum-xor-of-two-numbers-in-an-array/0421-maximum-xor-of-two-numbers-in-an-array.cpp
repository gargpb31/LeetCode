class Solution {
public:
    struct Node{
        Node* link[2];
       bool flag=false;

        bool containskey(char c){
            return link[c-'0']!=NULL;
        }

        void put(char c, Node* node){
            link[c-'0']=node;
        }

        Node* get(char c){
            return link[c-'0'];
        }
        void end(){
            flag=true;
        }
        

    };

    class Trie{
        private: Node* root;

        public :

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
            int maxXor(string word){
                Node* node = root;
                int g = word.size()-1;
                int count=0;
                int flag=0;
                for(int i=0; i<word.size(); i++){
                    

                    if(word[i]=='0'){
                        if(node->containskey('1')){
                            count+=pow(2,g-i);
                            node=node->get('1');
                        }
                        else if(node->containskey('0')) node=node->get('0');
                        else {
                          
                            flag=1;
                        }

                    }
                    else{
                        if(node->containskey('0')){
                            count+=pow(2,g-i);
                            node=node->get('0');
                        }
                        else if(node->containskey('1')) node=node->get('1');
                        else {
                            flag=1;
                            
                        }
                    }
                }
                return count;
            }


    };
    int findMaximumXOR(vector<int>& nums) {
            Trie* tr = new Trie();
            int ans=0;
            for(auto it : nums){
                bitset<32> b(it);
               
                string s = b.to_string();
                cout<<s<<endl;
                tr->insert(s);
                ans=max(ans,tr->maxXor(s));
            }
            return ans;
    }
};