struct Node{
    Node* link[26];
    bool flag=false;

    bool containskey(char c){
        return (link[c-'a']!=NULL);
    }

    Node* get(char c){
        return link[c-'a'];
    }
    void put(char c, Node* node){
        link[c-'a']=node;
    }
    bool checklast(){
        return flag;
    }
  void end(){
        flag=true;
    }
};


class Trie {
    private: Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node =root;
        for(int i=0; i<word.size(); i++){
            if(!(node->containskey(word[i]))){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);

        }
        node->end();
    }
    
    bool search(string word) {
          Node* node =root;
        for(int i=0; i<word.size(); i++){
            if(!(node->containskey(word[i]))){
               return false;
            }
            node=node->get(word[i]);

        }
       return node->checklast();
    }
    
    bool startsWith(string prefix) {
         Node* node =root;
        for(int i=0; i<prefix.size(); i++){
            if(!(node->containskey(prefix[i]))){
               return false;
            }
            node=node->get(prefix[i]);

        }
       return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */