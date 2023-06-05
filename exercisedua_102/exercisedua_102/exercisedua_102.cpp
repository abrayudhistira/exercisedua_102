#include <iostream>
#include <vector>
using namespace std;

class pengarang;
class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;
	vector<buku*> daftar_buku;

	penerbit(string pNama) : nama(pNama) {
		cout << "Penerbit \"" << nama << "\" ada\n";
	}
	~penerbit() {
		cout << "Penerbit \"" << nama << "\" tidak ada\n";
	}
	void tambahPengarang(pengarang*);
	void tambahBuku(buku*);
	void cetakPengarang();
	void cetakBuku();
};

class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;
	vector<buku*> daftar_buku;

	pengarang(string pNama) : nama(pNama) {
		cout << "Pengarang \"" << nama << "\" ada\n";
	}
	~pengarang() {
		cout << "Pengarang \"" << nama << "\" tidak ada\n";
	}
	void tambahPenerbit(penerbit*);
	void tambahBuku(buku*);
	void cetakPenerbit();
	void cetakBuku();
};

class buku {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;

	buku(string pNama) : nama(pNama) {
		cout << "Buku \"" << nama << "\" ada\n";
	}
	~buku() {
		cout << "Buku \"" << nama << "\" tidak ada\n";
	}
	void tambahPengarang(pengarang*);
	void cetakPengarang();
};

void penerbit::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
	pPengarang->daftar_penerbit.push_back(this);
}

void penerbit::tambahBuku(buku* pBuku) {
	daftar_buku.push_back(pBuku);
	pBuku->tambahPengarang(this);
}

void penerbit::cetakPengarang() {
	cout << "Daftar pengarang yang dinaungi oleh penerbit \"" << this->nama << "\":\n";
	for (auto& p : daftar_pengarang) {
		cout << p->nama << "\n";
	}
	cout << endl;
}

void penerbit::cetakBuku() {
	cout << "Daftar buku yang diterbitkan oleh penerbit \"" << this->nama << "\":\n";
	for (auto& b : daftar_buku) {
		cout << b->nama << "\n";
	}
	cout << endl;
}

void pengarang::tambahPenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
	pPenerbit->daftar_pengarang.push_back(this);
}

void pengarang::tambahBuku(buku* pBuku) {
	daftar_buku.push_back(pBuku);
	pBuku->tambahPengarang(this);
}

void pengarang::cetakPenerbit() {
	cout << "Daftar penerbit yang dinaungi oleh pengarang \"" << this->nama << "\":\n";
	for (auto& p : daftar_penerbit) {
		cout << p->nama << "\n";
	}
	cout << endl;
}

void pengarang::cetakBuku() {
	cout << "Daftar buku yang ditulis oleh pengarang \"" << this->nama << "\":\n";
	for (auto& b : daftar_buku) {
		cout << b->nama << "\n";
	}
	cout << endl;
}

void buku::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
	pPengarang->daftar_buku.push_back(this);
}

void buku::cetakPengarang() {
	cout << "Daftar pengarang yang menulis buku \"" << this->nama << "\":\n";
	for (auto& p : daftar_pengarang) {
		cout << p->nama << "\n";
	}
	cout << endl;
}

int main() {
	pengarang* varPengarang1 = new pengarang("Abra");
	pengarang* varPengarang2 = new pengarang("Alfi");
	penerbit* varPenerbit1 = new penerbit("Rangga");
	penerbit* varPenerbit2 = new penerbit("Ipan");
	buku* varBuku1 = new buku("Buku Astronomi");
	buku* varBuku2 = new buku("Buku Geofisika");

	varPengarang1->tambahPenerbit(varPenerbit1);
	varPengarang1->tambahPenerbit(varPenerbit2);
	varPengarang2->tambahPenerbit(varPenerbit2);

	varPenerbit1->tambahBuku(varBuku1);
	varPenerbit2->tambahBuku(varBuku1);
	varPenerbit2->tambahBuku(varBuku2);

	varPengarang1->cetakPenerbit();
	varPengarang2->cetakPenerbit();
	varPenerbit1->cetakPengarang();
	varPenerbit2->cetakPengarang();

	varBuku1->cetakPengarang();
	varBuku2->cetakPengarang();

	delete varBuku1;
	delete varBuku2;
	delete varPenerbit1;
	delete varPenerbit2;
	delete varPengarang1;
	delete varPengarang2;

	return 0;
}
