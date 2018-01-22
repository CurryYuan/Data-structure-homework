#include "tree.h"

Tree::Tree()
{
    recursion_find_judge = false;
    find_ptr = NULL;
    pre_str.clear();
    in_str.clear();
    root = NULL;
    readFromFile();
}

string Tree::createRoot(string na)
{
    if(root==NULL){
        root=new node(na);
        return "Create root successfully";
    }
    else{
        return "Root already exist\nCreate root failed";
    }
}

string Tree::marriage(string na, string nb)
{
    node* ptr = find(na);
    if (ptr == NULL)
        return na+" doesn't exist\nMarriage failed";
    node* ptr1=find(nb);
    if(ptr1!=NULL)               //有待修改
        return nb+" already exists\nMarriage failed";
    if (ptr->sex == false)
        return na+" should be a man\nMarriage failed";
    if(!ptr->alive)
        return na+" should alive\nMarriage failed";
    ptr->ismarriage = true;
    while(ptr->right!=NULL)
        ptr = ptr->right;
    ptr->right = new node(nb,false,true);
    writeToFile();
    return "Marriage succeed";
}

string Tree::born(string fa,string mo,string name,int d)
{
    node* father = find(fa);
    if(father==NULL)
        return fa+" doesn't exist\nBorn failed";
    node* mother = find(mo);
    if(mother==NULL)
        return mo+" doesn't exist\nBorn failed";

    if(find(name))
        return name+" already exist\nBorn failed";

    node* temp=father->right;
    while(temp&&temp->name != mother->name) {
        temp=temp->right;
    }
    if(temp==NULL)
        return fa+" "+mo+" aren't married\nBorn failed";
    while(mother->left)
        mother = mother->left;

    if(d==0)
        mother->left = new node(name,true);
    else
        mother->left = new node(name,false);
    writeToFile();
    return "Born succeed";
}

string Tree::die(string name)
{
    node* temp = find(name);
    if(temp==NULL)
        return name+" doesn't exist\nDie failed";
    if(temp->alive == true){
        temp->alive = false;
        writeToFile();
        return name+" died successfully";
    }
    return name+" already died\nDie failed";
}

string Tree::divorce(string husband,string wife)
{
    node* hptr = find(husband);
    node* temp = hptr->right;
    node* wptr = find(wife);

    if(hptr== NULL)
        return husband+" doesn't exist\nDivorce failed";
    if(wptr==NULL)
        return wife+" doesn't exist\nDivorce failed";

    while(temp){
        if(temp->name == wptr->name) break;
        temp = temp->right;
    }
    if(temp == NULL)
        return husband+" has no wife "+wife+"\nDivorce failed";
    wptr->ismarriage = false;
    hptr->ismarriage = false;
    writeToFile();
    return "Divorce succeed";
}

node* Tree::getRoot()
{
    return root;
}

node*& Tree::find(string a)
{
    recursion_find(a,root);
    if(recursion_find_judge == true){
        recursion_find_judge = false;
        return find_ptr;
    }
    else{
        find_ptr = NULL;
        return find_ptr;
    }
}

void Tree::recursion_find(string a, node *&ptr)
{
    if (ptr != NULL) {
        if (ptr->name == a){
            find_ptr = ptr;
            recursion_find_judge = true;
        }
        recursion_find(a, ptr->left);
        recursion_find(a, ptr->right);
    }
}

void Tree::preorder(node* ptr)
{
    if(ptr!=NULL){
        pre_str.append(ptr->name+",");
        (ptr->sex==true)?pre_str.append("1,"):pre_str.append("0,");
        (ptr->ismarriage==true)?pre_str.append("1,"):pre_str.append("0,");
        (ptr->alive==true)?pre_str.append("1;"):pre_str.append("0;");
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void Tree::inorder(node* ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        in_str.append(ptr->name+",");
        (ptr->sex==true)?in_str.append("1,"):in_str.append("0,");
        (ptr->ismarriage==true)?in_str.append("1,"):in_str.append("0,");
        (ptr->alive==true)?in_str.append("1;"):in_str.append("0;");
        inorder(ptr->right);
    }
}

void Tree::maketree(string pre,string in,node* &ptr){
    if(ptr) return;
    if(pre.size() == 0 || in.size() == 0) return;
    string temppre = pre;
    string firstname = temppre.substr(0,temppre.find(","));
    temppre = temppre.substr(temppre.find(",")+1,temppre.size());
    string firstsex_str = temppre.substr(0,temppre.find(","));
    temppre = temppre.substr(temppre.find(",")+1,temppre.size());
    string firstismarriage_str = temppre.substr(0,temppre.find(","));
    temppre = temppre.substr(temppre.find(",")+1,temppre.size());
    string firstalive_str = temppre.substr(0,temppre.find(";"));
    temppre = temppre.substr(temppre.find(";")+1,temppre.size());
    int first_size = pre.size() - temppre.size();

    bool firstsex;
    bool firstismarriage;
    bool firstalive;
    (firstsex_str == "1")?firstsex = true:firstsex = false;
    (firstismarriage_str == "1")?firstismarriage = true:firstismarriage = false;
    (firstalive_str == "1")?firstalive = true:firstalive = false;

    if(ptr==NULL)
        ptr = new node(firstname,firstsex,firstismarriage,firstalive);

    string l_pre,l_in,r_pre,r_in;
    int position = in.find(firstname);
    l_pre = pre.substr(pre.find(";")+1,position);
    l_in = in.substr(0,position);
    r_pre = pre.substr(pre.find(";")+position+1,pre.size());
    r_in = in.substr(position+first_size,pre.size());

    maketree(l_pre,l_in,ptr->left);
    maketree(r_pre,r_in,ptr->right);
}

bool Tree::writeToFile(){
    ofstream file("./Genealogy.txt",ios::out);
    if(!file)
        return false;
    pre_str.clear();
    in_str.clear();
    preorder(root);
    inorder(root);
    file << pre_str << endl;
    file << in_str << endl;
    pre_str.clear();
    in_str.clear();
    file.close();
    return true;
}

bool Tree::readFromFile(){
    ifstream file("./Genealogy.txt",ios::in);
    if(!file)
        return false;
    while(!file.eof()){
        file >> pre_str;
        file >> in_str;
    }
    maketree(pre_str,in_str,root);
    file.close();
    return true;
}



void setPosition(node*& root,int& x,int y){
    if(root!=NULL){
        y+=60;
        setPosition(root->left,x,y);
        x+=40;
        root->x=x;
        root->y=y;
        setPosition(root->right,x,y);
    }
}
void Tree::set(){
    int x=40;
    setPosition(root,x,130);
}
