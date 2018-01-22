#ifndef TREE_H
#define TREE_H
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
struct node {
    string name;
    node* left;
    node* right;
    bool sex;
    bool ismarriage;
    bool alive;
    int x,y;
    node(string na, bool se = true, bool im = false, bool al = true, node* l = NULL, node* r = NULL)
    :name(na), sex(se), ismarriage(im), alive(al), left(l), right(r){x=y=0;}
};

class Tree {
public:
    Tree();
    string createRoot(string na);
    string marriage(string na, string nb);
    string born(string fa, string mo, string name,int d);
    string die(string name);
    string divorce(string husband, string wife);
    node* getRoot();
    node*& find(string a);
    void set();
private:
    node* root;
    node* find_ptr;
    string pre_str;
    string in_str;
    void recursion_find(string a, node*& ptr);
    bool recursion_find_judge;
    void preorder(node* ptr);
    void static maketree(string pre,string in,node* &ptr);
    void inorder(node* ptr);
    bool readFromFile();
    bool writeToFile();
};

#endif // TREE_H
