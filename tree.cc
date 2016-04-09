/*
File: tree.cc
Author: Georgios Kamaras
Purpose: tree class member functions
*/
#include "tree.h"

using namespace std;
/* tree's constructor */
tree::tree(thread& t){
  int i;
  post* pArr = t.getPostArr();    // get the posts of the argument's thread
  root = new treeNode(pArr[0]);   // construct a new tree node
  for(i = 1; i < t.getPostNum(); i++) insertPost(pArr[i]); // insert each one of the threads posts to our tree
  cout << "Tree has just been created!" << endl;      // tree's construction message
}
/* tree's destructor */
tree::~tree(){
  cout << "Tree is about to be destroyed" << endl;    // tree's destruction message
  delete root; // delete pointer to the tree's root (so, call the tree root node's destructor if there is a root)
}
/* insert a post to the tree */
void tree::insertPost(post& p){
  bool flag = false;      // flag which tells if the post has been inserted (true) or not (false)
  treeNode* temp = root;  // temporary treeNode, to assist in tree's iteration
  while(!flag){      // while post hasn't been inserted
    if(p.getCreator() == temp->name){ // if we already have a treeNode about the post's creator
      temp->posts.pushFront(p);     // just add the post to it's creator's list
      flag = true;    // post has just been inserted
    }
    else if(p.getCreator() < temp->name){   // if we need to go left
      if(temp->left != NULL) temp = temp->left; // if we can go left, we go
      else{
        treeNode* n = new treeNode(p); // else, we create a new tree node with the data-to-be-inserted
        temp->left = n;       // and we add it to the tree, as the left child of the current tree node
        flag = true;    // post has just been inserted
      }
    }
    else{                                   // if we need to go right
      if(temp->right != NULL) temp = temp->right; // if we can go right, we go
      else{
        treeNode* n = new treeNode(p); // else, we create a new tree node with the data-to-be-inserted
        temp->right = n;      // and we add it to the tree, as the right child of the current tree node
        flag = true;    // post has just been inserted
      }
    }
  }
}
/* to call tree inorder printing */
void tree::print() const{
  cout << "Printing forum's tree in inorder:" << endl;
  inorder(root);  // call the function with which we are inorder printing
}
/* tree inorder printing */
void tree::inorder(treeNode* t) const{
  if(t == NULL) return;   // if (the argument's) tree node is empty, then return
  inorder(t->left);       // go left
  cout << "Forum member with name: " << t->name << ", has: " << endl;  // print user
  t->posts.print();               // print node's data (a list)
  inorder(t->right);      // go right
}
/* for enhancing a tree with another tree */
void tree::enhance(tree& t){
  iterate(t.root, *this); // call the function with which we iterate the argument's tree, passing current tree (*this) as argument
  t.root = NULL;    // after enhancing (*this) tree, t tree will definitely be empty
}
/* for iterating a tree in postorder, while keeping a reference to another tree */
void tree::iterate(treeNode* node, tree& t){
  if(node->left != NULL){       // if we can go left
    iterate(node->left, t);     // go left
    node->left = NULL;  // "forget" the iterated nodes', we don't care about this tree's integrity
  }                     // and we don't want problems with tree t, when we destroy it
  if(node->right != NULL){      // if we can go right
    iterate(node->right, t);    // go right
    node->right = NULL; // "forget" the iterated nodes', we don't care about this tree's integrity
  }                     // and we don't want problems with tree t, when we destroy it
  insertTreeNode(t, node); // if we can't go left or right, we are on a leaf, whose data need to be inserted
  if(node->posts.empty()) delete node;  // if we inserted the whole posts list, delete this leaf
}
/* handle the insertion of a treeNode's data in a tree */
void tree::insertTreeNode(tree& t, treeNode* node){
  treeNode* tn = t.root;
  bool flag = false; // flag to know if we have inserted yet (true) or not (false)...we haven't inserted yet
	while(!flag){     // while we haven't inserted
		if((node->name < tn->name) && (tn->left != NULL)) tn = tn->left; // go left if you can and you need to
		else if((node->name > tn->name) && (tn->right != NULL)) tn = tn->right; // else go right if you can and you need to
		else if(node->name == tn->name){  // if no need to go left or right (we are in the right user's tree node)
      tn->posts.insertListOfPosts(node->posts); // insert just the list of the posts (adding it to the one that already exists)
      flag = true;   // we're done here!
    }else{    // add the whole treeNode to the tree, to include node's content
      if(node->name < tn->name) tn->left = node;    // if you should add it left, add it left
      else tn->right = node;                // else, if you should add it right, add it right
      flag = true;    // we're done here
    }
  }
}
