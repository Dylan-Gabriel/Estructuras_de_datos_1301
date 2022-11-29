/*
    bitree.c
*/
#include <stdlib.h>
#include <string.h>

#include "bitree.h"

/*
    Initialize the bitree
*/
void bitree_init (BiTree *tree, void (*destroy)(void *data)) {
    tree->size = 0;
    tree->destroy = destroy;
    tree->root = NULL;

    return;    
}

/*
    Destroying the bitree
*/
void bitree_destroy(BiTree *tree) {
    
    bitree_rem_left(tree, NULL);

    memset(tree, 0, sizeof(BiTree));
    return;
}

/*
    Insert next left node at the BiTree
*/
int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data ) {
    BiTreeNode *new_node, **position;

    if (node == NULL) {
        // is empty?
        if (bitree_size(tree) > 0)
            return -1;

        // first node root
        position = &tree->root;

    } else {
        // insert at the end of the branch
        if (bitree_left(node) != NULL)
            return -1;

        // position to insert node
        position = &node->left;
    }

    if ((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
        return -1;

    new_node->data = (void *)data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;

    tree->size++;

    return 0;
}

/*
    Insert next right node at the BiTree
*/
int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data ) {
    BiTreeNode *new_node, **position;

    if (node == NULL) {
        // is empty?
        if (bitree_size(tree) > 0)
            return -1;

        // first node root
        position = &tree->root;

    } else {
        // insert at the end of the branch
        if (bitree_right(node) != NULL)
            return -1;

        // position to insert node
        position = &node->right;
    }

    if ((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
        return -1;

    new_node->data = (void *)data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;

    tree->size++;

    return 0;
}

/*
    Remove left node at the tree
*/
void bitree_rem_left(BiTree *tree, BiTreeNode *node) {

    BiTreeNode **position;

    if (bitree_size(tree) == 0)
    return;

    // Determine where to remove nodes.                                         

    if (node == NULL)
        position = &tree->root;
    else
        position = &node->left;

    // remove node
    if (*position != NULL) {

        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);

        if (tree->destroy != NULL) {
            // Call a user-defined function to free dynamically allocated data
            tree->destroy((*position)->data);
        }

        free(*position);
        *position = NULL;

        tree->size--;

    }
    return;
}

/*
    Remove right node at the tree
*/
void bitree_rem_right(BiTree *tree, BiTreeNode *node) {

    BiTreeNode **position;

    if (bitree_size(tree) == 0)
    return;

    // Determine where to remove nodes.                                         

    if (node == NULL)
        position = &tree->root;
    else
        position = &node->right;

    // remove node
    if (*position != NULL) {

        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);

        if (tree->destroy != NULL) {
            // Call a user-defined function to free dynamically allocated data
            tree->destroy((*position)->data);
        }

        free(*position);
        *position = NULL;

        tree->size--;

    }
    return;
}



/*
    Merge tree
*/
int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data) {

    // initialize a new tree
    bitree_init(merge, left->destroy);

    // Insert the data for the root node of the merged tree
    if (bitree_ins_left(merge, NULL, data) != 0) {
        bitree_destroy(merge);
        return -1;
    }

    // merge tree
    bitree_root(merge)->left = bitree_root(left);
    bitree_root(merge)->right = bitree_root(right);

    merge->size = merge->size + bitree_size(left) + bitree_size(right);

    left->root = NULL;
    left->size = 0;
    right->root = NULL;
    right->size = 0;

    return 0;
}
