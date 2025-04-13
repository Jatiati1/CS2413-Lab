/*Binary Tree Inorder Traversal*/

static int count_nodes(struct TreeNode *n) {
  if (!n) return 0;
  return 1 + count_nodes(n->left) + count_nodes(n->right);
}

static void fill_inorder(struct TreeNode *n, int *arr, int *idx) {
  if (!n) return;
  fill_inorder(n->left, arr, idx);
  arr[(*idx)++] = n->val;
  fill_inorder(n->right, arr, idx);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
  int total = count_nodes(root);
  *returnSize = total;
  if (total == 0) return NULL;

  int *result = (int *)malloc(sizeof(int) * total);
  int pos = 0;
  fill_inorder(root, result, &pos);
  return result;
}

/*Binary Tree preorder traversal*/
static int count_nodes(struct TreeNode *node) {
  if (node == NULL) return 0;
  return 1 + count_nodes(node->left) + count_nodes(node->right);
} 

static void fill_preorder(struct TreeNode *node, int *arr, int *idx) {
  if (node == NULL) return;
  arr[(*idx)++] = node->val;
  fill_preorder(node->left, arr, idx);
  fill_preorder(node->right, arr, idx);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
  int total = count_nodes(root);
  int *result = (int *)malloc(sizeof(int) * total);
  int pos = 0;
  fill_preorder(root, result, &pos);
  *returnSize = total;
  return result;
}


