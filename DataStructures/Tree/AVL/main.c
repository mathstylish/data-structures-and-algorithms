#include "avl.h"

int main(void) {
  struct node *root = NULL;
  int nodes[] = {34, 84, 15, 0,  2,   99,  79, 9,  88,
                 89, 18, 31, 39, 100, 101, 34, 102};

  for (int i = 0; i < (sizeof(nodes) / sizeof(nodes[0])); i++) {
    root = insert(root, nodes[i]);
    printf("Inserted: %d\n", nodes[i]);
  }

  root = remove_node(root, 99);

  printf("\nInorder traversal:\n");
  inorder_traversal(root);

  printf("\nPreorder traversal:\n");
  preorder_traversal(root);

  printf("\nPostorder traversal:\n");
  postorder_traversal(root);

  return EXIT_SUCCESS;
}
