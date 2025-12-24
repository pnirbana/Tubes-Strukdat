#include "Inventory.h"

void createTree(adrNode &root) {
    root = NULL;
}

adrNode newNode(Product x) {
    adrNode p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(adrNode &root, Product x) {
    if (root == NULL) {
        root = newNode(x);
    } else {
        if (x.id < root->info.id) {
            insertNode(root->left, x);
        } else if (x.id > root->info.id) {
            insertNode(root->right, x);
        } else {
            cout << "ID sudah ada! Produk tidak ditambahkan.\n";
        }
    }
}

adrNode searchNode(adrNode root, int id) {
    if (root == NULL) return NULL;
    if (id == root->info.id) return root;
    if (id < root->info.id)
        return searchNode(root->left, id);
    else
        return searchNode(root->right, id);
}

adrNode deleteNode(adrNode root, int id) {
    if (root == NULL) return NULL;

    if (id < root->info.id) {
        root->left = deleteNode(root->left, id);
    } else if (id > root->info.id) {
        root->right = deleteNode(root->right, id);
    } else {
        if (root->left == NULL) return root->right;
        else if (root->right == NULL) return root->left;
        else {
            adrNode temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->info = temp->info;
            root->right = deleteNode(root->right, temp->info.id);
        }
    }
    return root;
}

void inOrder(adrNode root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << "ID: " << root->info.id
             << " | Nama: " << root->info.name
             << " | Stok: " << root->info.stock
             << " | Harga: " << root->info.price
             << " | Kategori: " << root->info.category << endl;
        inOrder(root->right);
    }
}

int countProduct(adrNode root) {
    if (root == NULL) return 0;
    return 1 + countProduct(root->left) + countProduct(root->right);
}

int totalStock(adrNode root) {
    if (root == NULL) return 0;
    return root->info.stock + totalStock(root->left) + totalStock(root->right);
}

void stockLow(adrNode root) {
    if (root != NULL) {
        stockLow(root->left);
        if (root->info.stock < 5) {
            cout << root->info.name << " stok rendah!\n";
        }
        stockLow(root->right);
    }
}

void searchName(adrNode root, string name) {
    if (root != NULL) {
        searchName(root->left, name);
        if (root->info.name == name) {
            cout << "ID: " << root->info.id
                 << " | Nama: " << root->info.name
                 << " | Stok: " << root->info.stock
                 << " | Harga: " << root->info.price
                 << " | Kategori: " << root->info.category << endl;
        }
        searchName(root->right, name);
    }
}

void updateProduct(adrNode root, int id) {
    adrNode p = searchNode(root, id);
    if (p != NULL) {
        cout << "Nama baru: ";
        cin >> p->info.name;
        cout << "Stok baru: ";
        cin >> p->info.stock;
        cout << "Harga baru: ";
        cin >> p->info.price;
        cout << "Kategori baru: ";
        cin >> p->info.category;
    } else {
        cout << "Produk tidak ditemukan\n";
    }
}

void showAllCategories(adrNode root) {
    if (root != NULL) {
        showAllCategories(root->left);
        cout << "- " << root->info.category << endl;
        showAllCategories(root->right);
    }
}

void searchCategory(adrNode root, string category, bool &found) {
    if (root != NULL) {
        searchCategory(root->left, category, found);
        if (root->info.category == category) {
            found = true;
            cout << "Nama: " << root->info.name
                 << " | Stok: " << root->info.stock
                 << " | Harga: " << root->info.price << endl;
        }
        searchCategory(root->right, category, found);
    }
}

void filterByPrice(adrNode root, int minPrice, int maxPrice, bool &found) {
    if (root != NULL) {
        filterByPrice(root->left, minPrice, maxPrice, found);
        if (root->info.price >= minPrice && root->info.price <= maxPrice) {
            found = true;
            cout << "Nama: " << root->info.name
                 << " | Stok: " << root->info.stock
                 << " | Harga: " << root->info.price
                 << " | Kategori: " << root->info.category << endl;
        }
        filterByPrice(root->right, minPrice, maxPrice, found);
    }
}
