#include <iostream>
using namespace std;

// max number of versions, can be made larger or smaller. each update creates a new version
constexpr int MAX = 100;
using ll = long long;

// node struct that stores a long long as well as pointers to left and right children
// can be updated to store other data types; would potentially require updating the merge function
struct Node {
    ll value;
    Node *leftChild;
    Node *rightChild;
    // default constructor sets values to null
    Node() {
        leftChild = rightChild = nullptr;
        value = 0;
    }
    Node(Node *l, Node *r, ll v) {
        leftChild = l, rightChild = r;
        value = v;
    }
};

// global array of pointers to nodes where each Node is a root node for that version; each index represents a version
// index 0 is the original tree and each subsequent index is a new version created by an update
Node *root[MAX];

// Persistent Segment Tree class
class PST {
    const int n;
    int version;
    int size;

    static Node* makeNode() {
        return new Node;
    }

    // merge is simply the addition of the two values as this tree stores integers
    static ll merge(const Node *l, const Node *r) {
        return l->value + r->value;
    }

    // Private recursive constructor function: takes array of values to store and creates the tree
    Node* construct(ll val[], int l, int r) {
        Node *newNode = makeNode();
        // base case: if l == r, set the value of the node to the value at that index to be stored
        if (l == r) {
            newNode->value = (val==nullptr ? 0 : val[l]);
            return newNode;
        }
        // otherwise recursively create the left and right children
        const int middle = (l + r) / 2;
        newNode->leftChild = construct(val, l, middle);
        newNode->rightChild = construct(val, middle + 1, r);
        // once the children finish their construction, merge their values to set the value of the parent (this) node
        newNode->value = merge(newNode->leftChild, newNode->rightChild);
        return newNode;
    }

    // Private recursive update function
    Node* update(const int l, const int r, const Node *prevVerPtr, const int idx, const ll newVal) {
        Node *newNode = makeNode();
        // base case: if l == r we've found the node to update in the previous version tree, now set the new version's node to the new value
        if (l == r) {
            newNode->value = newVal;
        } else {
            // otherwise recurse down the tree to find the node to update
            if (const int middle = (l + r) / 2; idx <= middle) {
                // if the index is in the left half, update the left child and set the right child to the previous version's right child
                newNode->leftChild = update(l, middle, prevVerPtr->leftChild, idx, newVal);
                newNode->rightChild = prevVerPtr->rightChild;
            } else {
                // if the index is in the right half, update the right child and set the left child to the previous version's left child
                newNode->rightChild = update(middle + 1, r, prevVerPtr->rightChild, idx, newVal);
                newNode->leftChild = prevVerPtr->leftChild;
            }
            // once the children finish their updates, merge their values to set the value of the parent (this) node for this new version
            newNode->value = merge(newNode->leftChild, newNode->rightChild);
        }
        return newNode;
    }

    // Private query function
    ll query(const Node* node, const int l, const int r, const int ql, const int qr) {
        if (l > qr || r < ql) {
            return 0;
        }
        if (ql <= l && qr >= r) {
            return node->value;
        } else {
            const int middle = (l + r) / 2;
            const ll left = query(node->leftChild, l, middle, ql, qr);
            const ll right = query(node->rightChild, middle + 1, r, ql, qr);
            return left + right;
        }
    }

public:

    explicit PST(const int n): n(n) {
        version = 0;
        size = 0;
    }

    // Public constructor function; takes an array of values to store
    // calls private constructor function
    void construct(ll val[]) {
        root[0] = construct(val, 0, n-1);
    }

    // Public update function; takes an index to update and the new value
    // create a new version of the tree and call the private update function
    void update(const int idx, const ll val) {
        this->version = version + 1;
        root[version] = update(0, n-1, root[version-1], idx, val);
    }

    // Public query function; takes a version, left index, and right index
    // calls the private query function to get the sum of the values in the range
    ll query(int queryVersion, const int l, const int r) {
        return query(root[queryVersion], 0, n-1, l, r);
    }

    // helper function to get a pointer to the root node of a specific version
    // can be used to look at the state of the tree at that version
    static Node *getVersion(const int version) {
        return root[version];
    }
};

int main(){
    // ——— Example Case 0 (original) ———
    cout << "\033[1;33m=== Starting Example Case 0 ===\033[0m" << endl;
    ll a[] = {1, 2, 3, 4, 5};
    PST S1(5);
    S1.construct(a);
    // version 0 in red
    cout << "The tree at \033[1;31mversion 0\033[0m is storing: \033[1;31m{1, 2, 3, 4, 5}\033[0m" << endl;
    cout << "Querying \033[1;31mversion 0\033[0m on range \033[1;31m[1..2]\033[0m gives: \033[1;31m"
         << S1.query(0,1,2) << "\033[0m" << endl;
    // update → version 1 in blue
    cout << "\033[1;36mApplying update: index = 1, new value = 5\033[0m" << endl;
    S1.update(1, 5);
    cout << "The tree at \033[1;34mversion 1\033[0m is storing: \033[1;34m{1, 5, 3, 4, 5}\033[0m" << endl;
    cout << "Querying \033[1;34mversion 1\033[0m on range \033[1;34m[1..2]\033[0m gives: \033[1;34m"
         << S1.query(1,1,2) << "\033[0m" << endl << endl;

    // ——— Example Case 1 — all zeros, then update at the end ———
    cout << "\033[1;33m=== Starting Example Case 1 | All zeros, update at the end ===\033[0m" << endl;
    ll b[] = {0, 0, 0, 0};
    PST S2(4);
    S2.construct(b);
    // version 0 in red
    cout << "The tree at \033[1;31mversion 0\033[0m is storing: \033[1;31m{0, 0, 0, 0}\033[0m" << endl;
    cout << "Querying \033[1;31mversion 0\033[0m on range \033[1;31m[0..3]\033[0m gives: \033[1;31m"
         << S2.query(0,0,3) << "\033[0m" << endl;
    // update → version 1 in blue
    cout << "\033[1;36mApplying update: index = 3, new value = 7\033[0m" << endl;
    S2.update(3, 7);
    cout << "The tree at \033[1;34mversion 1\033[0m is storing: \033[1;34m{0, 0, 0, 7}\033[0m" << endl;
    cout << "Querying \033[1;34mversion 1\033[0m on range \033[1;34m[2..3]\033[0m gives: \033[1;34m"
         << S2.query(1,2,3) << "\033[0m" << endl << endl;

    // ——— Example Case 2 — mix of positives & negatives ———
    cout << "\033[1;33m=== Starting Example Case 2 | Positives & Negatives ===\033[0m" << endl;
    ll d[] = {1, -1, 2, -2, 3};
    PST S4(5);
    S4.construct(d);
    // version 0 in red
    cout << "The tree at \033[1;31mversion 0\033[0m is storing: \033[1;31m{1, -1, 2, -2, 3}\033[0m" << endl;
    cout << "Querying \033[1;31mversion 0\033[0m on range \033[1;31m[0..4]\033[0m gives: \033[1;31m"
         << S4.query(0,0,4) << "\033[0m" << endl;
    // update → version 1 in blue
    cout << "\033[1;36mApplying update: index = 1, new value = 5\033[0m" << endl;
    S4.update(1, 5);
    cout << "The tree at \033[1;34mversion 1\033[0m is storing: \033[1;34m{1, 5, 2, -2, 3}\033[0m" << endl;
    cout << "Querying \033[1;34mversion 1\033[0m on range \033[1;34m[0..2]\033[0m gives: \033[1;34m"
         << S4.query(1,0,2) << "\033[0m" << endl << endl;

    // ——— Example Case 3 — four versions in one test ———
    cout << "\033[1;33m=== Starting Example Case 3 | A tree with 4 versions ===\033[0m" << endl;
    ll e[] = {10, 20, 30, 40};
    PST S5(4);
    S5.construct(e);
    // version 0 in red
    cout << "The tree at \033[1;31mversion 0\033[0m is storing: \033[1;31m{10, 20, 30, 40}\033[0m" << endl;
    cout << "Querying \033[1;31mversion 0\033[0m on range \033[1;31m[1..2]\033[0m gives: \033[1;31m"
         << S5.query(0,1,2) << "\033[0m" << endl;
    // version 1 in blue
    cout << "\033[1;36mApplying update: index = 0, new value = 100\033[0m" << endl;
    S5.update(0, 100);
    cout << "The tree at \033[1;34mversion 1\033[0m is storing: \033[1;34m{100, 20, 30, 40}\033[0m" << endl;
    cout << "Querying \033[1;34mversion 1\033[0m on range \033[1;34m[0..1]\033[0m gives: \033[1;34m"
         << S5.query(1,0,1) << "\033[0m" << endl;
    // version 2 in green
    cout << "\033[1;36mApplying update: index = 3, new value = 5\033[0m" << endl;
    S5.update(3, 5);
    cout << "The tree at \033[1;32mversion 2\033[0m is storing: \033[1;32m{100, 20, 30, 5}\033[0m" << endl;
    cout << "Querying \033[1;32mversion 2\033[0m on range \033[1;32m[2..3]\033[0m gives: \033[1;32m"
         << S5.query(2,2,3) << "\033[0m" << endl;
    // version 3 in magenta
    cout << "\033[1;36mApplying update: index = 1, new value = 50\033[0m" << endl;
    S5.update(1, 50);
    cout << "The tree at \033[1;35mversion 3\033[0m is storing: \033[1;35m{100, 50, 30, 5}\033[0m" << endl;
    cout << "Querying \033[1;35mversion 3\033[0m on range \033[1;35m[0..3]\033[0m gives: \033[1;35m"
         << S5.query(3,0,3) << "\033[0m" << endl << endl;

    // ——— Example Case 4 — past vs. successor version queries ———
    cout << "\033[1;33m=== Starting Example Case 4 | Querying a past version ===\033[0m" << endl;
    ll f[] = {2, 4, 6, 8, 10};
    PST S6(5);
    S6.construct(f);
    // version 0 in red
    cout << "The tree at \033[1;31mversion 0\033[0m is storing: \033[1;31m{2, 4, 6, 8, 10}\033[0m" << endl;
    cout << "Querying \033[1;31mversion 0\033[0m on range \033[1;31m[1..4]\033[0m gives: \033[1;31m"
         << S6.query(0,1,4) << "\033[0m" << endl;

    // version 1 in blue
    cout << "\033[1;36mApplying update: index = 2, new value = 12\033[0m" << endl;
    S6.update(2, 12);
    cout << "The tree at \033[1;34mversion 1\033[0m is storing: \033[1;34m{2, 4, 12, 8, 10}\033[0m" << endl;
    cout << "Querying \033[1;34mversion 1\033[0m on range \033[1;34m[1..4]\033[0m gives: \033[1;34m"
         << S6.query(1,1,4) << "\033[0m" << endl;

    // version 2 in green
    cout << "\033[1;36mApplying update: index = 4, new value = 0\033[0m" << endl;
    S6.update(4, 0);
    cout << "The tree at \033[1;32mversion 2\033[0m is storing: \033[1;32m{2, 4, 12, 8, 0}\033[0m" << endl;
    cout << "Querying \033[1;32mversion 2\033[0m on range \033[1;32m[1..4]\033[0m gives: \033[1;32m"
         << S6.query(2,1,4) << "\033[0m" << endl;

    // version 3 in magenta
    cout << "\033[1;36mApplying update: index = 3, new value = 16\033[0m" << endl;
    S6.update(3, 16);
    cout << "The tree at \033[1;35mversion 3\033[0m is storing: \033[1;35m{2, 4, 12, 16, 0}\033[0m" << endl;
    cout << "Querying \033[1;35mversion 3\033[0m on range \033[1;35m[1..4]\033[0m gives: \033[1;35m"
         << S6.query(3,1,4) << "\033[0m" << endl;

    // revisit an earlier version after further updates
    cout << "\033[1;36mRe-querying past version:\033[0m" << endl;
    cout << "Even after later updates, querying \033[1;34mversion 1\033[0m on range \033[1;34m[1..4]\033[0m still gives: \033[1;34m"
         << S6.query(1,1,4) << "\033[0m" << endl;
    return 0;
}