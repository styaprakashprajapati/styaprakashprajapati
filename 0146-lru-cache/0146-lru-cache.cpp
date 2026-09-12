class LRUCache {
private:

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    // Add node just before tail
    void addNode(Node* node) {
        Node* last = tail->prev;

        last->next = node;
        node->prev = last;

        node->next = tail;
        tail->prev = node;
    }

    // Remove node from linked list
    void removeNode(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;

        before->next = after;
        after->prev = before;
    }

    // Move node to most recently used position
    void moveToEnd(Node* node) {
        removeNode(node);
        addNode(node);
    }

public:

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        // Key doesn't exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Recently used
        moveToEnd(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            moveToEnd(node);

            return;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        mp[key] = newNode;

        addNode(newNode);

        // Cache is full
        if (mp.size() > capacity) {

            // First real node = Least Recently Used
            Node* lru = head->next;

            removeNode(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */