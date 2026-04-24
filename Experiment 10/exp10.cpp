#include <iostream>
#include <vector>
using namespace std;

// Segment Tree Implementation for Sum Queries
class SegmentTree {
public:
    vector<int> tree;
    int n;
    SegmentTree(int _n) : n(_n), tree(4 * _n, 0) {}
    void update(int idx, int val) {
        updateUtil(1, 0, n - 1, idx, val);
    }
    void updateUtil(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) updateUtil(2 * node, l, mid, idx, val);
        else updateUtil(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    int query(int ql, int qr) {
        if (ql > qr) return 0;
        return queryUtil(1, 0, n - 1, ql, qr);
    }
    int queryUtil(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return queryUtil(2 * node, l, mid, ql, qr) + queryUtil(2 * node + 1, mid + 1, r, ql, qr);
    }
};

// Trie Node for Binary Trie
struct TrieNode {
    TrieNode* child[2];
    int count;
    TrieNode() : count(0) {
        child[0] = child[1] = nullptr;
    }
};

// Binary Trie Implementation
class BinaryTrie {
public:
    TrieNode* root;
    BinaryTrie() {
        root = new TrieNode();
    }
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 14; i >= 0; i--) {  // 2^14 = 16384 > 10000
            int bit = (num >> i) & 1;
            if (!node->child[bit]) node->child[bit] = new TrieNode();
            node = node->child[bit];
            node->count++;
        }
    }
    int querySmaller(int num) {
        TrieNode* node = root;
        int res = 0;
        for (int i = 14; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 1) {
                if (node->child[0]) res += node->child[0]->count;
            }
            if (!node->child[bit]) break;
            node = node->child[bit];
        }
        return res;
    }
};

// Solution using Segment Tree
vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    const int SHIFT = 10000;
    const int MAXV = 20001;
    SegmentTree st(MAXV);
    for (int i = n - 1; i >= 0; i--) {
        int val = nums[i] + SHIFT;
        res[i] = st.query(0, val - 1);
        st.update(val, 1);
    }
    return res;
}

int main() {
    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = countSmaller(nums);
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}