#include <iostream>
#include <string>
using namespace std;
class Nguoi {
protected:
    string maSo;
   string hoTen;
    double luong;
    void nhapThongTin() {
        cout << "Nhap ma so: ";
       getline(cin, maSo);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap luong: ";
        cin >> luong;
        cin.ignore();
    }
public:
    Nguoi(const string& maSo, const string& hoTen, double luong)
        : maSo(maSo), hoTen(hoTen), luong(luong) {}

    void hienThiThongTin() const {
        cout << "Ma so: " << maSo << "\nHo ten: " << hoTen << "\nLuong: " << luong << endl;
    }
};

class Bienche : public Nguoi {
private:
    double heSoLuong;
    double tienPhuCap;
    string chucVu;

public:
    Bienche(const string& maSo, const string& hoTen, double luong, double heSoLuong, double tienPhuCap, const string& chucVu)
        : Nguoi(maSo, hoTen, luong), heSoLuong(heSoLuong), tienPhuCap(tienPhuCap), chucVu(chucVu) {}

    void hienThiThongTin() const {
        Nguoi::hienThiThongTin();
        cout << "He so luong: " << heSoLuong << "\nTien phu cap: " << tienPhuCap << "\nChuc vu: " << chucVu << endl;
    }
};

class Hopdong : public Nguoi {
private:
    double tienCong;
    int soNgayLamViec;
    double heSoVuotGio;

public:
    Hopdong(const string& maSo, const string& hoTen, double luong, double tienCong, int soNgayLamViec, double heSoVuotGio)
        : Nguoi(maSo, hoTen, luong), tienCong(tienCong), soNgayLamViec(soNgayLamViec), heSoVuotGio(heSoVuotGio) {}

    void hienThiThongTin() const {
        Nguoi::hienThiThongTin();
        cout << "Tien cong: " << tienCong << "\nSo ngay lam viec: " << soNgayLamViec << "\nHe so vuot gio: " << heSoVuotGio << endl;
    }
};

int main() {
    Bienche bc("BC001", "Hoang Thi Nghia", 5000, 2.5, 1000, "Truong phong");
    Hopdong hd("HD001", "Ho Van Nghia", 3000, 200, 22, 1.5);

    cout << "Thong tin Bien che:\n";
    bc.hienThiThongTin();

    cout << "\nThong tin Hop dong:\n";
    hd.hienThiThongTin();

    return 0;
}