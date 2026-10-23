//
// Created by ubril on 10/18/2026.
//

#include <iostream>
#include <vector>
using namespace std;


class TreeNode {
public:
    TreeNode() = default;

    TreeNode(std::string val, TreeNode *, TreeNode *);

    TreeNode(const TreeNode &tn):
        value(tn.value), left(tn.left),
        right(tn.right), count(tn.count), use(tn.use)
    {
        ++*use;
        cout <<"copy version"<<endl;
    }

    TreeNode& operator=(const TreeNode&);

    size_t getUse() const {
        return *use;
    }

    ~TreeNode();

private:
    std::string value;
    int count = 0;
    TreeNode *left;
    TreeNode *right;

    size_t *use = new size_t(1);
};

TreeNode::TreeNode(std::string val, TreeNode *l=nullptr, TreeNode *r=nullptr):
    count(0), left(l), right(r), value(val) {}

TreeNode& TreeNode::operator=(const TreeNode &rhs) {
    ++*rhs.use;
    if (--*use == 0) {
        delete use;
        //delete left;
        //delete right;
    }
    use = rhs.use;
    left = rhs.left;
    right = rhs.right;
    value = rhs.value;

    cout <<"operator version"<<endl;
    return *this;
}

TreeNode::~TreeNode() {
    if (--*use == 0) {
        delete use;
        //delete left;
        //delete right;
    }
}


class BinStrTree {
private:
    TreeNode *root;
    size_t *use = new size_t(1);

public:
    BinStrTree() = default;
    BinStrTree(const BinStrTree& bst):root(bst.root), use(bst.use) {
        ++*use;
    }
    BinStrTree& operator=(const BinStrTree&);
    ~BinStrTree();

};


BinStrTree& BinStrTree::operator=(const BinStrTree& rhs) {
    ++*rhs.use;
    if (--*use == 0) {
        delete use;
    }
    use = rhs.use;
    root = rhs.root;

    return *this;
}

BinStrTree::~BinStrTree() {
    if (--*use == 0) {
        delete use;
    }
}

int main() {
    TreeNode t;
    //t.~TreeNode();
    TreeNode z;
    z = t;

    cout <<t.getUse() << endl;
    cout << z.getUse() << endl;
}