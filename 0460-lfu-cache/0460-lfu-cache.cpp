struct Node {
    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
    }
};

struct List {
    int size;
    Node* head;
    Node* tail;

    // Constructor
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // Function to add node in front
    void addFront(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    // Function to remove node from the list
    void removeNode(Node* delnode) {
        Node* prevNode = delnode->prev;
        Node* nextNode = delnode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

class LFUCache {
private:
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxCacheSize;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity) {
        maxCacheSize = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);

        //if this is the last node in the list and it is the minFreq
        if(node->cnt == minFreq &&freqListMap[node->cnt]->size == 0){
            minFreq++;
        }

        List* nextHigherList = new List();

        if(freqListMap.find(node->cnt+1) != freqListMap.end()){
            nextHigherList = freqListMap[node->cnt+1]; 
        }

        node->cnt += 1;

        nextHigherList->addFront(node);

        freqListMap[node->cnt] = nextHigherList;
        keyNode[node->key] = node;
    }

    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* ansNode = keyNode[key];
            int ans = ansNode->value;
            updateFreqListMap(ansNode);

            return ans;
        }
        // default return value.
        return -1;
    }

    void put(int key, int value) {
        if(maxCacheSize == 0) return;

        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];

            node->value = value;
            updateFreqListMap(node);
        }else{
            if(curSize == maxCacheSize){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }

            curSize++;
            minFreq = 1;

            List* freqList = new List();

            if(freqListMap.find(minFreq) != freqListMap.end()){
                freqList = freqListMap[minFreq];
            }

            Node* node = new Node(key, value);

            freqList->addFront(node);

            keyNode[node->key] = node;

            freqListMap[minFreq] = freqList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */