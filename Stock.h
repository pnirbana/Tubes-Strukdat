#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>

using namespace std;

struct Product {
    int id;
    string name;
    int stock;
    int price;
    string category;
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
adrNode deleteNode(adrNode root, int id);
void inOrder(adrNode root);
int countProduct(adrNode root);
int totalStock(adrNode root);
void stockLow(adrNode root);
void searchName(adrNode root, string name);
void updateProduct(adrNode root, int id);
void showAllCategories(adrNode root);
void searchCategory(adrNode root, string category, bool &found);
void filterByPrice(adrNode root, int minPrice, int maxPrice, bool &found);

#endif
