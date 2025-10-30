class LRUCache {
public:

    struct node{
        int key;
        int val;
        node* prev;
        node* next;
        node(int _key,int _val){
            key = _key;
            val = _val;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        if(mpp.find(key_) != mpp.end()){
            node* resnode = mpp[key_];
            int res = resnode->val;
            mpp.erase(key_); // erase the val for that key
            deleteNode(resnode);
            addNode(resnode);
            mpp[key_] = head->next;
            return res;
        }

        return -1;
    }
    
    void put(int key_, int value) {
        if(mpp.find(key_) != mpp.end()){
            node* existingnode = mpp[key_];
            mpp.erase(key_);
            deleteNode(existingnode);
        }
        if(mpp.size() == cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new node(key_, value));
        mpp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */