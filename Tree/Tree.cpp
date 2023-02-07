#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    int value;
    string name;
    char tag;

    TreeNode(int t): value(t), leftchild(NULL), rightchild(NULL), parent(NULL){};
    TreeNode(string s): name(s), leftchild(NULL), rightchild(NULL), parent(NULL){};  //implicit constructor better than explicit
    TreeNode(char p): tag(p), leftchild(NULL), rightchild(NULL), parent(NULL){};
    TreeNode(): name(""), leftchild(NULL), rightchild(NULL), parent(NULL){};
    ~TreeNode(void) {  //destructor
        cout << "TreeNode is being deleted." << endl; 
    }
};

class Tree {
public:
    TreeNode *root;

    void Preorder(TreeNode *current);
    void Inorder(TreeNode *current);
    void Postorder(TreeNode *current);
    void Levelorder(void);

    //another method not use recursive,use stack
    vector<string> PreorderUsingStack(TreeNode *current);
    vector<string> InorderUsingStack(TreeNode *current);
    vector<string> PostorderUsingStack(TreeNode *current);
    vector<char> inorderAnotherChar(TreeNode *current);
    void ShowResult(vector<string> S);
    void ShowResultChar(vector<char> S);


    TreeNode *leftmost(TreeNode *current);
    TreeNode *rightmost(TreeNode *current);

    TreeNode *InorderSuccessor(TreeNode *current);
    void Inorder_by_parent(TreeNode *node);

    TreeNode *InorderPreDecessor(TreeNode *current);
    void Inorder_reverse(TreeNode *node);

    void LevelOrderConstruct(char *Array,int length);
    void LevelorderTag(void);
    void InsertLevelOrder(char data);

    Tree(TreeNode *node): root(node){};  //implicit constructor better than explicit
    Tree(void): root(NULL){};
    ~Tree(void) { 
        cout << "Tree is being deleted." << endl; 
    }  //destructor
};

void Tree::Preorder(TreeNode *current){  //VLR
    if (!current) return; 
    cout << current->name << " ";
    Preorder(current->leftchild);
    Preorder(current->rightchild);
}

void Tree::Inorder(TreeNode *current){  //LVR
    if (!current) return;
    Inorder(current->leftchild);
    cout << current->name << " ";
    Inorder(current->rightchild);
}

void Tree::Postorder(TreeNode *current){  //LRV
    if (!current) return;
    Postorder(current->leftchild);
    Postorder(current->rightchild);
    cout << current->name << " ";
}

void Tree::Levelorder(void){
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *current = q.front();
        cout << current->name << " ";
        q.pop();

        if (current->leftchild) {
            q.push(current->leftchild);
        }

        if (current->rightchild) {
            q.push(current->rightchild);
        }
    }
}

void Tree::LevelorderTag(void){
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *current = q.front();
        cout << current->tag << " ";
        q.pop();

        if (current->leftchild) {
            q.push(current->leftchild);
        }

        if (current->rightchild) {
            q.push(current->rightchild);
        }
    }
}

vector<string> Tree::PreorderUsingStack(TreeNode *current){ //VLR
    vector<string> res;
    if (!current) return res;

    stack<TreeNode*> S;
    S.push(current);

    while (!S.empty()) {
        TreeNode *node = S.top();
        S.pop();
        res.push_back(node->name);
        if (node->rightchild)  //先放right
            S.push(node->rightchild);
        if (node->leftchild)   //再放left
            S.push(node->leftchild);
    }
    return res;
}

vector<string> Tree::InorderUsingStack(TreeNode *current){ //LVR
    vector<string> res;
    if (!current) return res;

    stack<TreeNode*> S;
    TreeNode *node = current;

    while (node || !S.empty()) {
        if (node) {  //一直往left找
            S.push(node);
            node = node->leftchild;
        }
        else {  //left找不下去後開始輸出
            TreeNode *nodeback = S.top();
            S.pop();
            res.push_back(nodeback->name);
            node = nodeback->rightchild;
        }
    }
    return res;
}

vector<char> Tree::inorderAnotherChar(TreeNode *current){
    vector<char> res;
    if(!current) return res;

    stack<TreeNode*> S;
    TreeNode *node = current;

    while (node || !S.empty()) {
        if (node) {
            S.push(node);
            node = node->leftchild;
        }
        else {
            TreeNode *nodeback = S.top();
            S.pop();
            res.push_back(nodeback->tag);
            node = nodeback->rightchild;
        }
    }
    return res;
}

vector<string> Tree::PostorderUsingStack(TreeNode *current){ //LRV
    vector<string> res;
    if(!current) return res;

    stack<TreeNode*> S;
    S.push(current);

    while (!S.empty()) {
        TreeNode *node = S.top();

        if (!node->leftchild && !node->rightchild) {  //V
            S.pop();
            res.push_back(node->name);
        }

        if (node->rightchild) {  //先放R
            S.push(node->rightchild);
            node->rightchild = NULL;
        }

        if (node->leftchild) {  //再放L
            S.push(node->leftchild);
            node->leftchild = NULL;
        }
    }
    return res;
}

void Tree::ShowResult(vector<string> S){
    for (int i = 0; i < S.size(); ++i) 
        cout << S[i] << " ";
    cout << endl;
}

void Tree::ShowResultChar(vector<char> S){
    for (int i = 0; i < S.size(); ++i)
        cout << S[i] << " ";
    cout << endl;
}

TreeNode *Tree::leftmost(TreeNode *current){
    while(current->leftchild != NULL) {
        current = current->leftchild;
    }
    return current;
}

TreeNode *Tree::rightmost(TreeNode *current){
    while(current->rightchild != NULL) {
        current = current->rightchild;
    }
    return current;
}

TreeNode *Tree::InorderSuccessor(TreeNode *current){
    if (current->rightchild != NULL) {
        return leftmost(current->rightchild);
    }

    TreeNode *successor = current->parent;
    while (successor != NULL && current == successor->rightchild) {
        current = successor;
        successor = successor->parent;
    }
    return successor;
}

void Tree::Inorder_by_parent(TreeNode *node){
    TreeNode *current = new TreeNode();
    current = leftmost(node);

    while (current) {
        cout << current->name << " ";
        current = InorderSuccessor(current);
    }
}

TreeNode *Tree::InorderPreDecessor(TreeNode *current){
    if (current->leftchild != NULL) {
        return rightmost(current->leftchild);
    }

    TreeNode *preDecessor = current->parent;
    while (preDecessor != NULL && current == preDecessor->leftchild) {
        current = preDecessor;
        preDecessor = preDecessor->parent;
    }
    return preDecessor;
}

void Tree::Inorder_reverse(TreeNode *node){
    TreeNode *current = new TreeNode();
    current = rightmost(node);

    while (current) {
        cout << current->name << " ";
        current = InorderPreDecessor(current);
    }
}

void Tree::LevelOrderConstruct(char *Array,int length){
    queue<TreeNode*> q;
    TreeNode *current = new TreeNode(*Array);
    root = current;
    int i = 1;
    cout << length << endl;

    while (i < length) {  //*(Array+i) != '\0'
        if (i < length) {
            TreeNode *newNode = new TreeNode(*(Array+i));
            newNode->parent = current;
            current->leftchild = newNode;
            q.push(newNode);
            ++i;
        }

        if (i < length) {
            TreeNode *newNode = new TreeNode(*(Array+i));
            newNode->parent = current;
            current->rightchild = newNode;
            q.push(newNode);
            ++i;
        }

        current = q.front();
        q.pop();
    }
}

void Tree::InsertLevelOrder(char data){
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *current = q.front();
        cout << current->tag << " ";
        q.pop();

        if (current->leftchild != NULL && current->leftchild->tag != 'x') {
            q.push(current->leftchild);
        }
        else if (current->leftchild != NULL && current->leftchild->tag == 'x') {
            current->leftchild->tag = data;
            q.push(current->leftchild);
            return;
        }

        if (current->rightchild != NULL && current->rightchild->tag != 'x') {
            q.push(current->rightchild);
        }
        else if (current->rightchild != NULL && current->rightchild->tag == 'x') {
            current->rightchild->tag = data;
            q.push(current->rightchild);
            return;
        }
    }
    cout << endl << data << " can't be inserted to tree." << endl;
}

int main(){

    cout << "Hello Binary Tree!" << endl;

    TreeNode *nodeA = new TreeNode("A"); TreeNode *nodeB = new TreeNode("B"); TreeNode *nodeC = new TreeNode("C"); TreeNode *nodeD = new TreeNode("D");
    TreeNode *nodeE = new TreeNode("E"); TreeNode *nodeF = new TreeNode("F"); TreeNode *nodeG = new TreeNode("G"); TreeNode *nodeH = new TreeNode("H");
    TreeNode *nodeI = new TreeNode("I");

    //point to child
    nodeA->leftchild = nodeB; nodeA->rightchild = nodeC;
    nodeB->leftchild = nodeE; nodeB->rightchild = nodeF;
    nodeC->leftchild = nodeD; nodeF->leftchild = nodeG;
    nodeD->leftchild = nodeH; nodeH->rightchild = nodeI;
    //point back to parent
    nodeB->parent = nodeA; nodeC->parent = nodeA;
    nodeE->parent = nodeB; nodeF->parent = nodeB;
    nodeG->parent = nodeF; nodeD->parent = nodeC;
    nodeH->parent = nodeD; nodeI->parent = nodeH;

    Tree T(nodeA);

    T.Preorder(T.root);
    cout << endl;
    T.Inorder(T.root);
    cout << endl;
    T.Postorder(T.root);
    cout << endl;
    T.Levelorder();
    cout << endl;


    cout << "Left most node:" << T.leftmost(T.root)->name << endl;
    cout << "Right most node:" << T.rightmost(T.root)->name << endl;

    T.Inorder_by_parent(T.root);
    cout << endl;

    T.Inorder_reverse(T.root);
    cout << endl;

    cout << "Using while loop to express PreOrder:" << endl;
    T.ShowResult(T.PreorderUsingStack(T.root));

    cout << "Using while loop to express InOrder:" << endl;
    T.ShowResult(T.InorderUsingStack(T.root));

    cout << "Using while loop to express PostOrder:" << endl;
    T.ShowResult(T.PostorderUsingStack(T.root));

    cout << "-----------------------------------------------------------------------------" << endl;

    char AlphaArray[] = {'A','B','C','D','E','F','x','G','x','x','x','x','H','I','x','J'};

    Tree T_2;
    T_2.LevelOrderConstruct(AlphaArray, sizeof(AlphaArray) / sizeof(AlphaArray[0]));
    T_2.LevelorderTag();
    cout << endl;

    //insert node by level order
    T_2.InsertLevelOrder('K');
    cout << endl;
    T_2.InsertLevelOrder('L');
    cout << endl;
    T_2.InsertLevelOrder('M');
    cout << endl;
    T_2.InsertLevelOrder('N');
    cout << endl;
    T_2.InsertLevelOrder('O');
    cout << endl;
    T_2.InsertLevelOrder('P');
    cout << endl;
    T_2.InsertLevelOrder('Q');
    cout << endl;
    T_2.LevelorderTag();

    cout << "root:" << T_2.root->tag << endl;
    cout << "Inorder result:" << endl;
    T_2.ShowResultChar(T_2.inorderAnotherChar(T_2.root));

    system("pause");
    return 0;
}
