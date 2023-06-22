struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};


class LRUCache {
public:
    int capacity;
    unordered_map<int,Node*> m;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node *t = m[key];
        remove(t);
        add(t);
        return t->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node *old = m[key];
            remove(old);
        }
        Node *t = new Node(key,value);
        m[key] = t;
        add(t);
        if(m.size()>capacity){
            Node *least = head->next;
            remove(least);
            m.erase(least->key);
        }
    }

    void add(Node* k){
        Node* end = tail->prev;
        end->next = k;
        k->prev = end;
        k->next = tail;
        tail->prev = k;
    }

    void remove(Node *k){
        Node *pr = k->prev;
        pr->next = k->next;
        k->next->prev = pr;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */