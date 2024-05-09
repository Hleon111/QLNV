#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class NhanVien{
private:
	string id, hoTen, gT, diaChi;
	int tuoi;
public:
	void Nhap() {
		cout << "\nNhap id cua nhan vien: "; getline(cin, id);
		cout << "\nNhap ho ten cua nhan vien: "; getline(cin, hoTen);
		cout << "\nNhap tuoi cua nhan vien: "; cin >> tuoi;
		cin.ignore();
		cout << "\nNhap gioi tinh: "; getline(cin, gT);
		cout << "\nNhap dia chi cua nhan vien: "; getline(cin, diaChi);
	}
	void Xuat() {
		cout << endl;
		cout << "ID: " << id << "     Ho ten: " << hoTen << "     Tuoi: " << tuoi << "     Gioi tinh : " << gT << "     Dia chi : " << diaChi << endl;
	}
	string tachten() {
		string ten;
		for (int i = 0; i < hoTen.length(); i++)
		{
			if (hoTen[i] == ' ')
			{
				ten = hoTen.substr(i + 1, 10);
			}
		}
		return ten;
	}
	string getID() {
		return id;
	}
};

class QLNV {

public:
	int n;
	NhanVien ds[100];
	void NhapTT() {
		cout << "\nSo luong nhan vien can nhap tt: ";
		cin >> n;
		cin.ignore();
		//a = new NhanVien[n];
		for (int i = 1; i <= n; i++)
		{
			ds[i].Nhap();
			cout << endl;
		}
	}

	void XuatTT() {
		if (n>0)
		{
			for (int i = 1; i <= n; i++)
			{
				ds[i].Xuat();
			}
		}
		else
		{
			cout << "" << endl;
			cout << "\nChua co nhan vien nao trong danh sach !" << endl;
		}
	}

	void ThemNV() {
		if (n>0)
		{
			int vitri;
			do
			{
				cout << "\nVi tri them nhan vien moi (vi tri phai nam trong danh sach): ";
				cin >> vitri;
			} while (vitri > (n + 1));
			n++;
			cin.ignore();
			for (int i = n; i >= vitri; i--)
			{
				ds[i] = ds[i - 1];
			}
			for (int i = vitri; i <= n; i++)
			{
				ds[i].Nhap(); break;
			}
		}
		else
		{
			cout << "\nDanh sach chua co nhan vien nao, khong the them !" << endl;
		}
		//n++;
	}

	void SuaTT() {
		if (n>0)
		{
			int tim = 0;
			string id;
			cout << "\nNhap ID nhan vien muon sua: ";
			cin >> id;
			cin.ignore();
			for (int i = 1; i <= n; i++)
			{
				if (id==ds[i].getID())
				{
					tim = 1;
					ds[i].Nhap();
					cout << endl;
					cout << "\ndanh sach sau khi sua !!!" << endl;
					XuatTT();
				}
			}
			if (tim==0)
			{
				cout << "\nKhong tim thay nhan vien muon sua !" << endl;
			}
		}
		else
		{
			cout << "\nKhong co nhan vien nao de sua !" << endl;
		}
	}

	void XoaNVtheoID() {
		if (n>0)
		{
			int tim = 0;
			string id;
			cout << "\nNhap ID nhan vien can xoa: ";
			cin >> id;
			for (int i = 1; i <= n; i++)
			{
				if (ds[i].getID() == id)
				{
					tim = 1;
					for (int j = i; j <= n; j++) {
						ds[j] = ds[j + 1];
					}
					cout << "\nDa xoa SV co ID = " << id << endl;
					n--;
				}
			}
			if (tim == 0)
			{
				cout << "\nKhong tim thay nhan vien co ID: " << id << endl;
			}
		}
		else
		{
			cout << "\nKhong co nhan vien nao trong danh sach !" << endl;
		}
	}

	void TimNVtheoID() {
		if (n>0)
		{
			int tim = 0;
			string id;
			cout << "\nNhap ID nhan vien muon tim kiem: ";
			cin >> id;
			for (int i = 1; i <= n; i++)
			{
				if (ds[i].getID() == id)
				{
					tim = 1;
					ds[i].Xuat();
				}
			}
			if (tim == 0)
			{
				cout << "\nKhong tim thay nhan vien co ID: " << id << endl;
			}
		}
		else
		{
			cout << "\nKhong co nhan vien nao trong danh sach !" << endl;
		}
	}

	void SapxepNV() {
		NhanVien temp;
		for (int i = 1; i < n; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				int res = ds[i].tachten().compare(ds[j].tachten());
				if (res>0)
				{
					temp = ds[i];
					ds[i] = ds[j];
					ds[j] = temp;
				}
			}
		}
		cout << "\ndanh sach sau khi sap xep !!!" << endl;
		XuatTT();
	}
};

int main() {
	QLNV a;
	int chon;
	do
	{
	system("cls");
	cout << "\n THONG TIN QUAN LY NHAN VIEN ";
	cout << "\n --------------------------- ";
	cout << "\n 1. Nhap thong tin cho nhan vien.";
	cout << "\n 2. Hien thi thong tin cua tat ca nhan vien.";
	cout << "\n 3. Them nhan vien moi.";
	cout << "\n 4. Sua thong tin cua nhan vien.";
	cout << "\n 5. Xoa nhan vien theo ID.";
	cout << "\n 6. Tim kiem nhan vien theo ID.";
	cout << "\n 7. Sap xep danh sach nhan vien.";
	cout << "\n 0. thoat chuong trinh.";
	cout << "\n --------------------------- ";
	cout << "\n Hay nhap lua chon: "; cin >> chon;
	switch (chon)
	{
	case 1:
		a.NhapTT();
		system("pause");
		break;
	case 2:
		a.XuatTT();
		cout << endl;
		system("pause");
		break;
	case 3:
		a.ThemNV();
		cout << endl;
		system("pause");
		break;
	case 4:
		a.SuaTT();
		cout << endl;
		system("pause");
		break;
	case 5:
		a.XoaNVtheoID();
		cout << endl;
		system("pause");
		break;
	case 6:
		a.TimNVtheoID();
		cout << endl;
		system("pause");
		break;
	case 7:
		a.SapxepNV();
		cout << endl;
		system("pause");
		break;
	case 0:
		break;
	default:
		cout << "\n hay nhap dung lua chon !" << endl; break;
	}
	} while (chon!=0);
}
