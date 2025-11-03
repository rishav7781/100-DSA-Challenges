/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    void dfs(Node* node, Node* clone_node){
        for(auto &n : node->neighbors){
            if(mp.find(n)==mp.end()){  //not found
                //toh ek naya node banyengye clone wala
                Node* clone= new Node(n->val);
                mp[n]=clone;
                clone_node->neighbors.push_back(clone);

                dfs(n,clone);
            }
            //found mil gya map me
            else{
                clone_node->neighbors.push_back(mp[n]); //yhaa direct n ni dalna mil gya mtlan mp[n]=clone hogi toh
                                                        //toh wahi se use krna h
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* clone_node= new Node(node->val);

        //mp[purana]=naya //yaha phle ek diya hua node ka replica banye then usko track rakhne ke liye map me purana 
        // ka address naya se map kr dengye
        mp[node]=clone_node;

        //then humlog traversal marengye uske neighbous pr 
        dfs(node,clone_node);

        return clone_node;
    }
};