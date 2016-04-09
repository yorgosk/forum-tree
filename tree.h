/*
File: tree.h
Author: Georgios Kamaras
Purpose: tree class and treeNode struct descriptions
*/
#include <iostream>   // for cout, endl and string
#include "list.h"     // for list class and whatever else is linked in it's header file
#include "thread.h"   // for thread class and whatever else is linked in it's header file
#include "post.h"     // for post class and whatever else is linked in it's header file
/* tree's class description */
class tree{
private:
  struct treeNode{ // struct treeNode, so it's members are public by default -> I use less functions
    std::string name;   // name of posts' creator (it's forum-name)
    list posts;          // a list of posts by the "name" 's creator
    treeNode* left;      // left child and...
    treeNode* right;     // ...right child, for tree's navigation
    /* treeNode's constructor */
    treeNode(post& p) : name(p.getCreator()), posts(p), left(NULL), right(NULL) {
      std::cout << "Tree node with name: " << name << " has just been created!" << std::endl;
    }                                                       // treeNode construction message
    /* treeNode's destructor */
    ~treeNode(){                                            // treeNode destruction message
      std::cout << "Tree node with name: " << name << " is about to be destroyed" << std::endl;
      delete left;        // delete pointers for left...
      delete right;       // ... and right childs
    }
  };
  treeNode* root; // pointer to our tree's root
public:
  tree(thread&);    // tree's constructor
  ~tree();          // tree's destructor
  void insertPost(post&);  // insert a post to the tree
  void print() const;  // to call tree inorder printing
  void inorder(treeNode*) const; // tree inorder printing
  void enhance(tree&);      // for enhancing a tree with another tree
  void iterate(treeNode*, tree&);  // for iterating a tree in postorder, while keeping a reference to another tree
  void insertTreeNode(tree&, treeNode*);   // handle the insertion of a treeNode's data in a tree
};
