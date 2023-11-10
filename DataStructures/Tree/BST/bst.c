#include "bst.h"

struct node *insert(struct node *root, int key) {
  struct node *node_new = malloc(sizeof(struct node));
  node_new->key = key;
  node_new->left = NULL;
  node_new->right = NULL;

  if (root == NULL) {
    root = node_new;
    return root;
  }

  // duplicate is not allowed
  if (root->key == key) return root;

  if (key < root->key) {
    root->left = insert(root->left, key);
  } else {
    root->right = insert(root->right, key);
  }

  return root;
}

// just for learning purposes. Recursively is more used
struct node *insert_it(struct node *root, int key) {
  struct node *node_new = malloc(sizeof(struct node));
  node_new->key = key;
  node_new->left = NULL;
  node_new->right = NULL;

  if (root == NULL) {
    root = node_new;
    return root;
  }

  struct node *current = root;
  struct node *parent = NULL;

  while (1) {
    parent = current;
    if (key < parent->key) {
      current = current->left;
      if (current == NULL) {
        parent->left = node_new;
        return root;
      }
    } else {
      current = current->right;
      if (current == NULL) {
        parent->right = node_new;
        return root;
      }
    }
  }
}

struct node *search(struct node *root, int key) {
  if (root == NULL || root->key == key) return root;

  if (key < root->key)
    return search(root->left, key);
  else
    return search(root->right, key);
}

struct node *remove_node(struct node *root, int key) {
  if (root == NULL) {  // empty tree
    return root;
  } else if (key < root->key) {  // The node to be removed is in the subtree to
                                 // the left of the root
    root->left = remove_node(root->left, key);
  } else if (key > root->key) {  // The node to be removed is in the subtree to
                                 // the right of the root
    root->right = remove_node(root->right, key);
  } else {  // The node to be removed is equal to root key, so this is the node
            // to be removed
    // case 1: childless node or one node
    if (root->left == NULL) {
      struct node *current = root->right;
      free(root);
      return current;
    } else if (root->right == NULL) {
      struct node *current = root->left;
      free(root);
      return current;
    }
    // Case 2: Node with two children, find in-order successor (smallest node in
    // right subtree)
    struct node *current = root->right;
    while (current->left) current = current->left;

    // copy the key of the successor in-order
    root->key = current->key;

    // remove the successor in-order
    root->right = remove_node(root->right, current->key);
  }
  return root;
}

struct node *search_it(struct node *root, int key) {
  while (root) {
    if (key < root->key) {
      root = root->left;
    } else if (key > root->key) {
      root = root->right;
    } else {
      return root;
    }
  }
  return NULL;
}

void inorder_traversal(struct node *root) {
  if (root == NULL) return;
  inorder_traversal(root->left);
  printf("%d\n", root->key);
  inorder_traversal(root->right);
}

void preorder_traversal(struct node *root) {
  if (root == NULL) return;
  printf("%d\n", root->key);
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

void postorder_traversal(struct node *root) {
  if (root == NULL) return;
  postorder_traversal(root->left);
  postorder_traversal(root->right);
  printf("%d\n", root->key);
}
