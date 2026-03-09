/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    // O(1) space
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        // 1. 複製節點，插入到原節點之後
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // 2. 設置拷貝節點的 random 指針
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // 3. 拆分鏈表
        Node* newHead = head->next;
        curr = head;
        Node* temp;
        while (curr) {
            temp = curr->next;
            curr->next = temp->next;
            if (temp->next) {
                temp->next = temp->next->next;
            }
            curr = curr->next;
        }

        return newHead;
    }


    // O(n) space
    // unordered_map<Node*, Node*> visited;

    // Node* getClonedNode(Node* node) {

    //     // If node exists (not null) then
    //     if (node) {
    //         // Check if its in the visited map
    //         if (visited.find(node) != visited.end()) {
    //             // If its in the visited map then return the new node reference
    //             // from the map
    //             return visited[node];
    //         } else {
    //             // Otherwise create a new node, save the reference in the
    //             // visited map and return it.
    //             visited[node] = new Node(node->val, NULL, NULL);
    //             return visited[node];
    //         }
    //     }
    //     return NULL;
    // }

    // Node* copyRandomList(Node* head) {

    //     if (!head) {
    //         return nullptr;
    //     }

    //     Node* oldNode = head;
    //     Node* newNode = new Node(oldNode->val);
    //     visited[oldNode] = newNode;

    //     while (oldNode) {
    //         // Get the clones of the nodes referenced by random and next
    //         // pointers.
    //         newNode->random = this->getClonedNode(oldNode->random);
    //         newNode->next = this->getClonedNode(oldNode->next);
    //         // Move one step ahead in the linked list.
    //         oldNode = oldNode->next;
    //         newNode = newNode->next;
    //     }

    //     return visited[head];
    // }


};