#include "Inventory.h"

int main() {
    adrNode root;
    createTree(root);

    int pilih = 1;

    while (pilih != 0) {
        cout << "\n=== STOREKEEP (BST) ===\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Hapus Produk\n";
        cout << "3. Cari Produk (ID)\n";
        cout << "4. Tampilkan Semua\n";
        cout << "5. Update Produk\n";
        cout << "6. ID Terkecil\n";
        cout << "7. ID Terbesar\n";
        cout << "8. Total Produk\n";
        cout << "9. Total Stok\n";
        cout << "10. Stok Rendah\n";
        cout << "11. Cari Nama Produk\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            Product x;
            cout << "Masukkan ID Produk: "; cin >> x.id;
            cout << "Masukkan Nama Produk: "; cin >> x.name;
            cout << "Masukkan Jumlah Stok: "; cin >> x.stock;
            insertNode(root, x);
        }

        else if (pilih == 2) {
            int id;
            cout << "Masukkan ID Produk: "; cin >> id;
            root = deleteNode(root, id);
        }

        else if (pilih == 3) {
            int id;
            cout << "Masukkan ID Produk: ";
            cin >> id;

            adrNode p = searchNode(root, id);

            if (p != NULL) {
                cout << "\n=== PRODUK DITEMUKAN ===\n";
                cout << "ID Produk   : " << p->info.id << endl;
                cout << "Nama Produk : " << p->info.name << endl;
                cout << "Jumlah Stok : " << p->info.stock << endl;
            } else {
                cout << "Produk tidak ditemukan.\n";
            }
        }

        else if (pilih == 4) {
            inOrder(root);
        }

        else if (pilih == 5) {
            int id;
            cout << "Masukkan ID Produk: "; cin >> id;
            updateProduct(root, id);
        }

        else if (pilih == 6) {
            showMin(root);
        }

        else if (pilih == 7) {
            showMax(root);
        }

        else if (pilih == 8) {
            cout << "Total Produk: " << countProduct(root) << endl;
        }

        else if (pilih == 9) {
            cout << "Total Stok: " << totalStock(root) << endl;
        }

        else if (pilih == 10) {
            stockLow(root);
        }

        else if (pilih == 11) {
            string name;
            cout << "Masukkan Nama Produk yang ingin dicari: ";
            cin >> name;
            searchName(root, name);
        }
    }

    return 0;
}

