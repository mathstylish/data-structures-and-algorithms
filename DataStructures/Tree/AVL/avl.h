#ifndef _BST_H
#define _BST_H

#include <stdio.h>
#include <stdlib.h>

// represents a node in tree
struct node {
  int key;
  struct node *left;
  struct node *right;
  int height;
};

struct node *insert(struct node *root, int key);
struct node *search(struct node *root, int key);
struct node *remove_node(struct node *root, int key);
// visit left subtree, then the root, and finally the right subtree
void inorder_traversal(struct node *root);
// visit root, then left, and finally right subtree
void preorder_traversal(struct node *root);
// visit left subtree, then the right subtree and finally root
void postorder_traversal(struct node *root);

#endif
