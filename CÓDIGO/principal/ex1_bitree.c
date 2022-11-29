#include <stdio.h>
#include <stdlib.h>

#include "bitree.h"
#include "traverse.h"

/*
   Print preorder
*/
static void print_preorder(const BiTreeNode *node) {
   if (!bitree_is_eob(node)) {
        fprintf(stdout, "tree.node=%03d, %14p <- %p -> %p \n", *(int *)bitree_data(node), bitree_left(node), node, bitree_right(node));

        if (!bitree_is_eob(bitree_left(node)))
            print_preorder(bitree_left(node));

        if (!bitree_is_eob(bitree_right(node)))
            print_preorder(bitree_right(node));
    }

    return;
}

/*
   inorder
*/
static void print_inorder(const BiTreeNode *node) {
    if (!bitree_is_eob(node)) {
        if (!bitree_is_eob(bitree_left(node)))
            print_inorder(bitree_left(node));

        fprintf(stdout, "tree.node=%03d, %14p <- %p -> %p \n", *(int *)bitree_data(node), bitree_left(node), node, bitree_right(node));

        if (!bitree_is_eob(bitree_right(node)))
            print_inorder(bitree_right(node));
    }

   return;
}

/*
   postorder
*/
static void print_postorder(const BiTreeNode *node) {
    if (!bitree_is_eob(node)) {

        if (!bitree_is_eob(bitree_left(node)))
            print_postorder(bitree_left(node));

        if (!bitree_is_eob(bitree_right(node)))
            print_postorder(bitree_right(node));

        fprintf(stdout, "tree.node=%03d, %14p <- %p -> %p \n", *(int *)bitree_data(node), bitree_left(node), node, bitree_right(node));
    }

    return;
}

/*
   Insert int
*/
static int insert_int(BiTree *tree, int i) {
    BiTreeNode *node, *prev;
    int direction, *data;

    node = tree->root;
    direction = 0;

    while (!bitree_is_eob(node)) {
        prev = node;

        if (i == *(int *)bitree_data(node)) {
            return -1;
        } else if (i < *(int *)bitree_data(node)) {
            node = bitree_left(node);
            direction = 1;
        } else {
            node = bitree_right(node);
            direction = 2;
        }
    }

    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return -1;

    *data = i;

    if (direction == 0)
        return bitree_ins_left(tree, NULL, data);

    if (direction == 1)
        return bitree_ins_left(tree, prev, data);

    if (direction == 2)
        return bitree_ins_right(tree, prev, data);

    return -1;
}

/*
   search int
*/
static BiTreeNode *search_int(BiTree *tree, int i) {
    BiTreeNode *node;

    node = bitree_root(tree);

    while (!bitree_is_eob(node)) {
        if (i == *(int *)bitree_data(node)) {
            return node;
        } else if (i < *(int *)bitree_data(node)) {
            node = bitree_left(node);
        } else {
            node = bitree_right(node);
        }
    }

    return NULL;
}

/*
   main program
*/
int main() {
    BiTree             tree;
    BiTreeNode         *node;
    int i;

    bitree_init(&tree, free);

    // Insert nodes
    fprintf(stdout, "Inserting nodes\n");

    if (insert_int(&tree, 20) != 0)
        return 1;
    if (insert_int(&tree, 10) != 0)
        return 1;
    if (insert_int(&tree, 30) != 0)
        return 1;
    if (insert_int(&tree, 15) != 0)
        return 1;
    if (insert_int(&tree, 25) != 0)
        return 1;
    if (insert_int(&tree, 70) != 0)
        return 1;
    if (insert_int(&tree, 80) != 0)
        return 1;
    if (insert_int(&tree, 23) != 0)
        return 1;
    if (insert_int(&tree, 26) != 0)
        return 1;
    if (insert_int(&tree, 5) != 0)
        return 1;

    fprintf(stdout, "Tree size is:  %d\n", bitree_size(&tree));
    fprintf(stdout, "Preorder traversal\n");
    print_preorder(bitree_root(&tree));


    // Searching elements (25)
    i = 25;
    fprintf(stdout, "\nLooking forward: %03d\n", i);
    if ((node = search_int(&tree, i)) == NULL) {
        fprintf(stdout, "Could not find %03d\n", i);
    } else {
        fprintf(stdout, "Found %03d...Removing the left tree below it\n", i);
        bitree_rem_left(&tree, node);
        fprintf(stdout, "Tree size is: %d\n", bitree_size(&tree));
        fprintf(stdout, "Preorder traversal\n");
        print_preorder(bitree_root(&tree));
    }
    
    // Searching elements (100)
    i = 100;
    fprintf(stdout, "\nLooking forward: %03d\n", i);
    if ((node = search_int(&tree, i)) == NULL) {
        fprintf(stdout, "Could not find %03d\n", i);
    } else {
        fprintf(stdout, "Found %03d...Removing the right tree below it\n", i);
        bitree_rem_right(&tree, node);
        fprintf(stdout, "Tree size is %d\n", bitree_size(&tree));
        fprintf(stdout, "Preorder traversal\n");
        print_preorder(bitree_root(&tree));
    }

    // Searching elements (20)
    i = 20;
    fprintf(stdout, "\nLooking forward: %03d\n", i);
    if ((node = search_int(&tree, i)) == NULL) {
        fprintf(stdout, "Could not find %03d\n", i);
    } else {
        fprintf(stdout, "Found %03d...Removing the right tree below it\n", i);
        bitree_rem_right(&tree, node);
        fprintf(stdout, "Tree size is %d\n", bitree_size(&tree));
        fprintf(stdout, "Preorder traversal\n");
        print_preorder(bitree_root(&tree));
    }

    // testing macros
    fprintf(stdout, "\nTesting macros\n");
    i = bitree_is_leaf(bitree_root(&tree));
    fprintf(stdout, "Testing bitree_is_leaf(%03d) ...Value=%d (0=OK)\n", *(int *)bitree_data(bitree_root(&tree)), i);
    
    i = bitree_is_leaf(bitree_left((bitree_root(&tree))));
    fprintf(stdout, "Testing bitree_is_leaf(%03d) ...Value=%d (0=OK)\n", *(int *)bitree_data(bitree_left(bitree_root(&tree))),i);
    
    i = bitree_is_leaf(bitree_left(bitree_left((bitree_root(&tree)))));
    fprintf(stdout, "Testing bitree_is_leaf(%03d) ...Value=%d (1=OK)\n", *(int *)bitree_data(bitree_left(bitree_left((bitree_root(&tree))))),i);
    
    i = bitree_is_leaf(bitree_right(bitree_left((bitree_root(&tree)))));
    fprintf(stdout, "Testing bitree_is_leaf(%03d) ...Value=%d (1=OK)\n", *(int *)bitree_data(bitree_right(bitree_left((bitree_root(&tree))))),i);

    // Inserting new nodes
    fprintf(stdout, "\nInserting some nodes 55, 44, 77 and 11\n");
    if (insert_int(&tree, 55) != 0)
        return 1;
    if (insert_int(&tree, 44) != 0)
        return 1;
    if (insert_int(&tree, 77) != 0)
        return 1;
    if (insert_int(&tree, 11) != 0)
        return 1;
    fprintf(stdout, "Tree size is %d\n", bitree_size(&tree));

    //Printing preorder traversal    
    fprintf(stdout, "\nPreorder traversal\n");
    print_preorder(bitree_root(&tree));
    
    //Printing inorder traversal
    fprintf(stdout, "\nInorder traversal\n");
    print_inorder(bitree_root(&tree));
    
    //Printing postorder traversal
    fprintf(stdout, "\nPostorder traversal\n");
    print_postorder(bitree_root(&tree));

    //Destroying tree
    fprintf(stdout, "\nDestroying the tree\n");
    bitree_destroy(&tree);

    return 0;

}
