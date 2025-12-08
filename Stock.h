#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    int stock;
};

struct Node {
    Product info;
    Node *left;
    Node *right;
};

typedef Node* adrNode;

void createTree(adrNode &root);
adrNode newNode(Product x);
void insertNode(adrNode &root, Product x);
adrNode searchNode(adrNode root, int id);
adrNode findMin(adrNode root);
adrNode deleteNode(adrNode root, int id);
void inOrder(adrNode root);
int countProduct(adrNode root);
int totalStock(adrNode root);
void showMin(adrNode root);
void showMax(adrNode root);
void stockLow(adrNode root);
void searchName(adrNode root, string name);
void updateProduct(adrNode root, int id);

#endif

