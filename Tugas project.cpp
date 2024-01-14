#include <iostream>
using namespace std;

// Fungsi untuk menampilkan papan permainan
void tampilkanPapan(char papan[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << papan[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Fungsi untuk memeriksa apakah ada pemenang
bool cekPemenang(char papan[3][3]) {
    // Cek baris dan kolom
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2] && papan[i][0] != ' ') {
            return true; // Baris samal
        }
        if (papan[0][i] == papan[1][i] && papan[1][i] == papan[2][i] && papan[0][i] != ' ') {
            return true; // Kolom sama
        }
    }

    // Cek diagonal
    if (papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2] && papan[0][0] != ' ') {
        return true; // Diagonal kiri atas ke kanan bawah sama
    }
    if (papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0] && papan[0][2] != ' ') {
        return true; // Diagonal kanan atas ke kiri bawah sama
    }

    return false; // Tidak ada pemenang
}

// Fungsi untuk memeriksa apakah terdapat celah kosong pada papan
bool cekCelahKosong(char papan[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (papan[i][j] == ' ') {
                return true; // Ada celah kosong
            }
        }
    }
    return false; // Tidak ada celah kosong
}

// Fungsi untuk memeriksa apakah langkah yang diambil oleh pemain valid
bool cekLangkahValid(int baris, int kolom, char papan[3][3]) {
    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3 && papan[baris][kolom] == ' ') {
        return true; // Langkah valid
    }
    return false; // Langkah tidak valid
}

int main() {
	cout<<"======================="<<endl;
	cout<<"| Program Tic Tac Toe |"<<endl;
	cout<<"======================="<<endl;
    char papan[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    int giliran = 1; // 1 untuk pemain X, 2 untuk pemain O
    int baris, kolom;

    do {
        tampilkanPapan(papan);

        // Pilih baris dan kolom
        do {
            cout << "Pemain " << (giliran == 1 ? 'X' : 'O') << ", masukkan baris (0-2) dan kolom (0-2) yang diinginkan: ";
            cin >> baris >> kolom;
        } while (!cekLangkahValid(baris, kolom, papan));

        // Isi papan dengan simbol pemain
        papan[baris][kolom] = (giliran == 1 ? 'X' : 'O');

        // Cek pemenang
        if (cekPemenang(papan)) {
            tampilkanPapan(papan);
            cout << "Pemain " << (giliran == 1 ? 'X' : 'O') << " menang!" << endl;
            break;
        }

        // Cek apakah papan penuh
        if (!cekCelahKosong(papan)) {
            tampilkanPapan(papan);
            cout << "Permainan seri!" << endl;
            break;
        }

        // Ganti giliran pemain
        giliran = (giliran == 1 ? 2 : 1);

    } while (true);

    return 0;
}
