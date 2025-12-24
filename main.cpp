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
        cout << "4. Tampilkan Semua Produk\n";
        cout << "5. Update Produk\n";
        cout << "6. Total Produk\n";
        cout << "7. Total Stok\n";
        cout << "8. Stok Rendah\n";
        cout << "9. Cari Produk (Nama)\n";
        cout << "10. Halaman Kategori\n";
        cout << "11. Filter Produk Berdasarkan Harga\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            Product x;
            cout << "ID Produk: "; cin >> x.id;
            cout << "Nama Produk: "; cin >> x.name;
            cout << "Stok: "; cin >> x.stock;
            cout << "Harga: "; cin >> x.price;
            cout << "Kategori: "; cin >> x.category;
            insertNode(root, x);
        }

        else if (pilih == 2) {
            int id;
            cout << "Masukkan ID Produk: ";
            cin >> id;
            root = deleteNode(root, id);
        }

        else if (pilih == 3) {
            int id;
            cout << "Masukkan ID Produk: ";
            cin >> id;
            adrNode p = searchNode(root, id);
            if (p != NULL) {
                cout << "Nama: " << p->info.name
                     << " | Stok: " << p->info.stock
                     << " | Harga: " << p->info.price
                     << " | Kategori: " << p->info.category << endl;
            } else {
                cout << "Produk tidak ditemukan\n";
            }
        }

        else if (pilih == 4) {
            inOrder(root);
        }

        else if (pilih == 5) {
            int id;
            cout << "Masukkan ID Produk: ";
            cin >> id;
            updateProduct(root, id);
        }

        else if (pilih == 6) {
            cout << "Total Produk: " << countProduct(root) << endl;
        }

        else if (pilih == 7) {
            cout << "Total Stok: " << totalStock(root) << endl;
        }

        else if (pilih == 8) {
            stockLow(root);
        }

        else if (pilih == 9) {
            string name;
            cout << "Masukkan Nama Produk: ";
            cin >> name;
            searchName(root, name);
        }

        else if (pilih == 10) {
            int opsi;
            cout << "\n=== HALAMAN KATEGORI ===\n";
            cout << "1. Tampilkan Semua Kategori\n";
            cout << "2. Cari Kategori\n";
            cout << "Pilih: ";
            cin >> opsi;

            if (opsi == 1) {
                showAllCategories(root);
            }
            else if (opsi == 2) {
                string cat;
                bool found = false;
                cout << "Masukkan Kategori: ";
                cin >> cat;
                searchCategory(root, cat, found);
                if (!found) {
                    cout << "Kategori yang anda cari tidak ada\n";
                }
            }
        }

        else if (pilih == 11) {
            int minP, maxP;
            bool found = false;
            cout << "Harga minimum: ";
            cin >> minP;
            cout << "Harga maksimum: ";
            cin >> maxP;
            filterByPrice(root, minP, maxP, found);
            if (!found) {
                cout << "Tidak ada produk dengan range harga yang anda inginkan\n";
            }
        }
    }

    return 0;
}
