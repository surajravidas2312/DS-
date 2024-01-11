#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left, *right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void performOperation(struct Node** root) {
    int choice, key;
    printf("\n1.Insert a key\n");
    printf("2.Delete a key\n");
    printf("3.Search for a key\n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            *root = insert(*root, key);
            printf("Key %d inserted into the BST.\n", key);
            break;
        case 2:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            *root = deleteNode(*root, key);
            printf("Key %d deleted from the BST.\n", key);
            break;
        case 3:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            if (search(*root, key) != NULL) {
                printf("Key %d found in the BST.\n", key);
            } else {
                printf("Key %d not found in the BST.\n", key);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    while (1) {
        printf("\nBinary Search Tree ");
        inorderTraversal(root);
        performOperation(&root);
    }
    return 0;

}