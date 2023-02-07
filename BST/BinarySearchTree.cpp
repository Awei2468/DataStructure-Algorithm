#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

class TreeNode {
public:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    int value;
    string name;

    TreeNode(void):leftchild(NULL), rightchild(NULL), parent(NULL), value(0), name(""){};
    TreeNode(int x,string s):leftchild(NULL), rightchild(NULL), parent(NULL), value(x), name(s){};
    TreeNode(int x):leftchild(nullptr), rightchild(nullptr), parent(nullptr), value(x), name(""){};
};

class BST {
public:
    TreeNode *root;

    BST(void):root(NULL){};
    void InorderPrint(TreeNode *current);
    void InsertNode(int x,string s);
    bool SearchNode(int x);
    void DeleteNode(int x);

    //recursive
    void inorder(TreeNode *&t);
    TreeNode *insert(TreeNode *&t, int val);
    TreeNode *find(TreeNode *&t, int target);
    TreeNode *findMin(TreeNode *&t);
    TreeNode *findMax(TreeNode *&t);
    TreeNode *remove(TreeNode *&t, int target);
    TreeNode *makeEmpty(TreeNode *&t);

    TreeNode *SearchRtnNode(int x);
    void DeleteRtnNode(int x);
    int maxTreeHeight(TreeNode *root);
    int nodeNumber(TreeNode *root);
};

void BST::InsertNode(int x, string s){
    TreeNode *insertNode = new TreeNode(x,s);
    TreeNode *pre = NULL;   //using two node to move forward,and tick off "next" because it will turn to null finally.
    TreeNode *next = root;

    if (!root) {
        root = insertNode;
    }
    else {
        while (next) {
            pre = next;
            if (insertNode->value > next->value)
                next = next->rightchild;
            else
                next = next->leftchild;
        }

        insertNode->parent = pre;

        if (insertNode->value > pre->value)
            pre->rightchild = insertNode;
        else
            pre->leftchild = insertNode;
    }
}

void BST::InorderPrint(TreeNode *current){  //LVR
    if (current) {
        InorderPrint(current->leftchild);
        cout << setw(2) << current->value << "[" << current->name << "]" << " ";
        InorderPrint(current->rightchild);
    }
}

bool BST::SearchNode(int x){
    TreeNode *current = root;

    while (current) {
        if (x > current->value)
            current = current->rightchild;
        else if (x < current->value)
            current = current->leftchild;
        else
            return true;
    }
    return false;
}

void BST::DeleteNode(int x){
    if (!root) {
        cout << "No root!" << endl;
        return;
    }

    if (!SearchNode(x)) {
        cout << x << " is not in the tree." << endl;
        return;
    }

    TreeNode *pre = NULL;
    TreeNode *next = root;

    while (next->value != x) {
        pre = next;
        if (x > next->value)
            next = next->rightchild;
        else
            next = next->leftchild;
    }

    if (next->leftchild == NULL && next->rightchild == NULL) {  //no child
        if (pre->rightchild == next) {
            pre->rightchild = NULL;
        }
        else {
            pre->leftchild = NULL;
        }
    }
    else if ((next->leftchild != NULL && next->rightchild == NULL) || (next->rightchild != NULL && next->leftchild == NULL)) {  //only one child
        if (next->leftchild != NULL && next->rightchild == NULL) {
            next->leftchild->parent = pre;
            if (pre->leftchild == next) {
                pre->leftchild = next->leftchild;
            }
            else {
                pre->rightchild = next->leftchild;
            }
        }
        else {
            next->rightchild->parent = pre;
            if (pre->rightchild == next) {             
                pre->rightchild = next->rightchild;
            }
            else {
                pre->leftchild = next->rightchild;
            }
        }
    }
    else if (next->leftchild != NULL && next->rightchild != NULL) { // two child,two way(1:find the right subtree smallest value 2:find the left subtree largest value,choose one to do)
        TreeNode *destination = next;

        pre = next;
        if (next->rightchild) {    //you don't know which side can use
            next = next->rightchild;

            while (next->leftchild != NULL) {   //use 1:find the right subtree smallest value
                pre= next;
                next = next->leftchild;
            }

            destination->value = next->value;

            if (pre->leftchild == next)
                pre->leftchild = next->rightchild;   //考慮還有1個rightchild情況 或是 NULL
            else
                pre->rightchild = next->rightchild;  //考慮right skewed subtree情況
        }
        else {
            next = next->leftchild;

            while (next->rightchild != NULL) {   //use 2:find the left subtree largest value
                pre = next;
                next = next->rightchild;
            }

            destination->value = next->value;

            if (pre->rightchild = next)
                pre->rightchild = next->leftchild; //考慮還有1個leftchild情況 或是 NULL
            else
                pre->leftchild = next->leftchild;  //考慮left skewed subtree情況
        }
    }
    cout << "Delete:" << x << endl;

    delete next;
    next = NULL;
}

void BST::inorder(TreeNode *&t) {
    if (!t) return;
    stack<TreeNode*> stk;
    TreeNode *node = t;
    while (!stk.empty() || node) {
        if (node) {
            stk.push(node);
            node = node->leftchild;
        }
        else {
            TreeNode *buf = stk.top();
            stk.pop();
            cout << setw(4) << buf->value;
            node = buf->rightchild;
        }
    }
    cout << "\n";
}

TreeNode *BST::insert(TreeNode *&t, int val) {
    if (!t) {
        t = new TreeNode(val);
        t->leftchild = t->rightchild = nullptr;
    }
    else if (val < t->value)
        t->leftchild = insert(t->leftchild, val);
    else if (val > t->value)
        t->rightchild = insert(t->rightchild, val);
    
    return t;
}

TreeNode *BST::find(TreeNode *&t, int target) {
    if (!t) return nullptr;
    if (t->value == target) return t;
    if (target > t->value) return find(t->rightchild, target);
    if (target < t->value) return find(t->leftchild, target);
}

TreeNode *BST::findMin(TreeNode *&t) {
    if (!t || !t->leftchild) return t;
    return findMin(t->leftchild);
}

TreeNode *BST::findMax(TreeNode *&t) {
    if (!t || !t->rightchild) return t;
    return findMax(t->rightchild);
}

TreeNode *BST::remove(TreeNode *&t, int target) {
    TreeNode *tmp;
    if (!t) return t;
    else if (target < t->value) t->leftchild = remove(t->leftchild, target);
    else if (target > t->value) t->rightchild = remove(t->rightchild, target);
    else if (t->leftchild && t->rightchild) {
        tmp = findMin(t->rightchild);  //find right side smallest
        //tmp = findMax(t->leftchild);  //find left side biggest
        t->value = tmp->value;
        t->rightchild = remove(t->rightchild, t->value);
    }
    else {
        tmp = t;
        if (!t->leftchild) t = t->rightchild;
        else if (!t->rightchild) t = t->leftchild;
        delete tmp;
        tmp = nullptr;
    }
    return t;
}

TreeNode *BST::makeEmpty(TreeNode *&t) {
    if (!t) return t;
    makeEmpty(t->leftchild);
    makeEmpty(t->rightchild);
    delete t;
    t = nullptr;
    return nullptr;
}

TreeNode *BST::SearchRtnNode(int x){
    TreeNode *current = root;

    while(current != NULL){
        if(x > current->value)
            current = current->rightchild;
        else if(x < current->value)
            current = current->leftchild;
        else
            return current;
    }
    return NULL;
}

void BST::DeleteRtnNode(int x){
    TreeNode *deleteNode = SearchRtnNode(x);
    if (!deleteNode)
        return;

    if (deleteNode->leftchild == NULL && deleteNode->rightchild == NULL) {
        if (deleteNode == deleteNode->parent->leftchild)
            deleteNode->parent->leftchild = NULL;
        else
            deleteNode->parent->rightchild = NULL;

        delete deleteNode;
        deleteNode = NULL;
    }
    else if ((deleteNode->leftchild == NULL && deleteNode->rightchild != NULL) || (deleteNode->leftchild != NULL && deleteNode->rightchild == NULL)) {

        if (deleteNode->leftchild == NULL && deleteNode->rightchild != NULL) {
            if (deleteNode == deleteNode->parent->rightchild) {
                deleteNode->rightchild->parent = deleteNode->parent;
                deleteNode->parent->rightchild = deleteNode->rightchild;
            }
            else {
                deleteNode->rightchild->parent = deleteNode->parent;
                deleteNode->parent->leftchild = deleteNode->rightchild;
            }
        }
        else {
            if (deleteNode == deleteNode->parent->rightchild) {
                deleteNode->leftchild->parent = deleteNode->parent;
                deleteNode->parent->rightchild = deleteNode->leftchild;
            }
            else {
                deleteNode->leftchild->parent = deleteNode->parent;
                deleteNode->parent->leftchild = deleteNode->leftchild;
            }
        }
        delete deleteNode;
        deleteNode = NULL;
    }
    else if (deleteNode->leftchild != NULL && deleteNode->rightchild != NULL) {
        TreeNode *desNode = deleteNode;

        if (desNode->rightchild) {     //you don't know which side can use
            desNode = desNode->rightchild;
            while (desNode->leftchild) {
                desNode = desNode->leftchild;
            }

            deleteNode->value = desNode->value;

            if (desNode == desNode->parent->leftchild)
                desNode->parent->leftchild = desNode->rightchild;
            else
                desNode->parent->rightchild = desNode->rightchild;
        }
        else {
            desNode = desNode->leftchild;
            while (desNode->rightchild) {
                desNode = desNode->rightchild;
            }

            deleteNode->value = desNode->value;

            if (desNode = desNode->parent->leftchild)
                desNode->parent->leftchild = desNode->leftchild;
            else
                desNode->parent->rightchild = desNode->leftchild;
        }

        delete desNode;
        desNode = NULL;
    }
}

int BST::maxTreeHeight(TreeNode *root) {
    if (!root) return 0;
    int hL = maxTreeHeight(root->leftchild);
    int hR = maxTreeHeight(root->rightchild);
    return 1 + max(hL,hR);
}

int BST::nodeNumber(TreeNode *root) {
    if (!root) return 0;
    else {
        int NL = nodeNumber(root->leftchild);
        int NR = nodeNumber(root->rightchild);
        return 1 + NL + NR;
    }
}

int main(){

    cout << "Hello Binary Search Tree!" << endl;

    BST bst_1;

    bst_1.InsertNode(10,"Aa");
    bst_1.InsertNode(5,"Bb");
    bst_1.InsertNode(43,"Cc");
    bst_1.InsertNode(30,"Dd");
    bst_1.InsertNode(70,"Ee");
    bst_1.InsertNode(72,"Ff");
    bst_1.InsertNode(2,"Gg");
    bst_1.InsertNode(8,"Hh");
    bst_1.InsertNode(21,"Ii");
    bst_1.InsertNode(36,"Jj");
    bst_1.InorderPrint(bst_1.root);
    cout << endl;

    cout << "bst_1 tree height: " << bst_1.maxTreeHeight(bst_1.root) << endl;
    cout << "bst_1 nodes number: " << bst_1.nodeNumber(bst_1.root) << endl;

    if(bst_1.SearchNode(40))
        cout << "In the tree." << endl;
    else
        cout << "Not in the tree." << endl;

    if(bst_1.SearchNode(70))
        cout << "In the tree." << endl;
    else
        cout << "Not in the tree." << endl;

    bst_1.DeleteNode(8);
    bst_1.InorderPrint(bst_1.root);
    cout << endl;
    bst_1.DeleteNode(70);
    bst_1.InorderPrint(bst_1.root);
    cout << endl;
    bst_1.DeleteNode(10);
    bst_1.InorderPrint(bst_1.root);
    cout << endl;

    cout << "bst_1 nodes number: " << bst_1.nodeNumber(bst_1.root) << endl;

    /*------------------------------------------------------------------------------*/

    BST bst_2;
    bst_2.InsertNode(20,"a");
    bst_2.InsertNode(9,"b");
    bst_2.InsertNode(45,"c");
    bst_2.InsertNode(5,"d");
    bst_2.InsertNode(18,"e");
    bst_2.InsertNode(31,"f");
    bst_2.InsertNode(47,"g");
    bst_2.InsertNode(19,"h");
    bst_2.InsertNode(46,"i");
    bst_2.InorderPrint(bst_2.root);
    cout << endl;

    //bst_2.DeleteRtnNode(46);
    //bst_2.InorderPrint(bst_2.root);
    //cout << endl;

    //bst_2.DeleteRtnNode(18);
    //bst_2.InorderPrint(bst_2.root);
    //cout << endl;

    bst_2.DeleteRtnNode(20);
    bst_2.InorderPrint(bst_2.root);
    cout << endl;

    cout << "------------test recursion----------------------------------------------------\n";

    BST bst_3;
    bst_3.insert(bst_3.root, 50);
    bst_3.insert(bst_3.root, 36);
    bst_3.insert(bst_3.root, 88);
    bst_3.insert(bst_3.root, 67);
    bst_3.insert(bst_3.root, 102);
    bst_3.insert(bst_3.root, 2);
    bst_3.insert(bst_3.root, 48);
    bst_3.insert(bst_3.root, 55);
    
    bst_3.inorder(bst_3.root);  //show result

    TreeNode *t3 = bst_3.find(bst_3.root, 102);
    if (t3) cout << "We find " << t3->value << " in the tree.\n";
    else cout << "We can't find it.\n";

    t3 = bst_3.find(bst_3.root, 200);
    if (t3) cout << "We find " << t3->value << " in the tree.\n";
    else cout << "we can't find it.\n";
    
    t3 = bst_3.findMin(bst_3.root);
    if (t3) cout << "We find minimum = " << t3->value << "\n";
    else cout << "We can't find minimum.\n";

    t3 = bst_3.findMax(bst_3.root);
    if (t3) cout << "We find maximum = " << t3->value << "\n";
    else cout << "We can't find maximum.\n";

    bst_3.remove(bst_3.root, 88);  //delete 88(in the tree)
    bst_3.inorder(bst_3.root);

    bst_3.remove(bst_3.root, 200);  //delete 200(not in the tree)
    bst_3.inorder(bst_3.root);

    bst_3.remove(bst_3.root, 2);  //delete 2(in the tree)
    bst_3.inorder(bst_3.root);

    bst_3.makeEmpty(bst_3.root);  //clear tree nodes
    bst_3.inorder(bst_3.root);
    
    system("pause");
    return 0;
}
