#include "avl.h"

static int height(struct node *node) {
  if (node == NULL) return 0;
  return node->height;
}

static int max(int a, int b) { return (a > b) ? a : b; }

static struct node *find_min(struct node *root) {
  // Keep traversing to the left until the leftmost node is reached
  if (root == NULL) return NULL;        // The tree is empty
  if (root->left == NULL) return root;  // The leftmost node is found
  return find_min(root->left);          // Continue traversing to the left
}

static struct node *single_rotate_right(struct node *root) {
  struct node *new_root = root->left;
  root->left = new_root->right;
  new_root->right = root;

  // update heights
  root->height = max(height(root->left), height(root->right)) + 1;
  new_root->height = max(height(new_root->left), height(new_root->right));

  return new_root;
}

static struct node *single_rotate_left(struct node *root) {
  struct node *new_root = root->right;
  root->right = new_root->left;
  new_root->left = root;

  // update heights
  root->height = max(height(root->left), height(root->right)) + 1;
  new_root->height = max(height(new_root->left), height(new_root->right)) + 1;

  return new_root;
}

static struct node *double_rotate_left(struct node *root) {
  // First rotation: simple right rotation on left child
  root->left = single_rotate_right(root->left);
  // Second rotation: simple left rotation on the original node
  return single_rotate_left(root);
}

static struct node *double_rotate_right(struct node *root) {
  // First rotation: simple left rotation on right child
  root->right = single_rotate_left(root->right);
  // Second rotation: simple right rotation on the original node
  return single_rotate_right(root);
}

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

  // Update height of current node
  root->height = max(height(root->left), height(root->right)) + 1;

  // Checks the balance and performs rotations if necessary
  int balance = height(root->left) - height(root->right);

  // case 1: left-left
  if (balance > 1 && key < root->left->key) return single_rotate_right(root);

  // case 2: right-right
  if (balance < -1 && key > root->right->key) return single_rotate_left(root);

  // case 3: left-right
  if (balance > 1 && key > root->left->key) return double_rotate_right(root);

  // case 4: right-left
  if (balance < -1 && key < root->right->key) return double_rotate_left(root);

  return root;
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

  // update height of current node
  root->height = max(height(root->left), height(root->right)) + 1;

  // Checks the balance and performs rotations if necessary
  int balance = height(root->left) - height(root->right);

  // case 1: left-left
  if (balance > 1 && height(root->left->left) - height(root->left->right) >= 0)
    return single_rotate_right(root);

  // case 2: right-right
  if (balance < -1 &&
      height(root->right->right) - height(root->right->left) >= 0)
    return single_rotate_left(root);

  // case 3: left-right
  if (balance > 1 && height(root->left->left) - height(root->left->right) < 0) {
    return double_rotate_right(root);
  }

  // case 4: right-left
  if (balance < -1 &&
      height(root->right->right) - height(root->right->left) < 0) {
    return double_rotate_left(root);
  }

  return root;
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
