#include <iostream>
#include <vector>
using namespace std;

struct UndirectedGraphNode {
        int label;
        vector<UndirectedGraphNode *> neighbors;
        UndirectedGraphNode(int x) : label(x) {};
};


class Solution {
public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
                if (node == NULL) return NULL;
                UndirectedGraphNode *head = new UndirectedGraphNode(node->label);
                dfs(node, head);
                return head;
        }
        void dfs(UndirectedGraphNode *node, UndirectedGraphNode *copy) {
                if ( !is_visited(node) ) {
                        visited.push_back(node->label);        
                        //cout << node->label << endl;
                        vector<UndirectedGraphNode *> vec = node->neighbors;
                        for (int i=0; i<vec.size(); i++) {
                                UndirectedGraphNode *n = new UndirectedGraphNode(vec[i]->label);
                                copy->neighbors.push_back(n); 
                                //cout << n->label << ": " << vec[i]->label << endl;  
                                dfs(vec[i], n);
                        }
                }        
        }
        bool is_visited(UndirectedGraphNode *node) {
                for (int i=0; i<visited.size(); i++) {
                        if (visited[i] == node->label) return true;
                }
                return false;
        }        
private:
        vector<int> visited;
};

        vector<int> visited;
        bool is_visited(UndirectedGraphNode *node) {
                for (int i=0; i<visited.size(); i++) {
                        if (visited[i] == node->label) return true;
                }
                return false;
        }
        void dfs(UndirectedGraphNode *node) {
                if ( !is_visited(node) ) {
                        visited.push_back(node->label);        
                        //cout << node->label << endl;
                        vector<UndirectedGraphNode *> vec = node->neighbors;
                        for (int i=0; i<vec.size(); i++) {
                                cout << node->label << "->neighbors: " << vec[i]->label << endl;  
                                dfs(vec[i]);
                        }
                }        
        }

        

int main()
{
        UndirectedGraphNode *node0 = new UndirectedGraphNode(0);
        UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
        UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
        
        node0->neighbors.push_back(node1); 
        node0->neighbors.push_back(node2); 
        node0->neighbors.push_back(node0); 
        node0->neighbors.push_back(node0); 

        node1->neighbors.push_back(node0);
        node1->neighbors.push_back(node2);

        node2->neighbors.push_back(node0);
        node2->neighbors.push_back(node1);

        Solution s;
        UndirectedGraphNode *n = s.cloneGraph(node0);
        //cout << n->neighbors[0]->label << endl;
        //cout << n->neighbors[1]->label << endl;
        //cout << n->neighbors.size() << endl;
        dfs(n);
}
