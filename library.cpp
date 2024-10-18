#include <bits/stdc++.h>
using namespace std;


class Sach {
    protected:
        int id_sach;
        string tieu_de;
        string tac_gia;
        bool cho_muon;
    public:
        void khoiTaoSach(){
            cout << "Nhập ID của sách: "; cin >> id_sach; cin.ignore();
            cout << "Nhập tiêu đề của sách: "; getline(cin, tieu_de); 
            cout << "Nhập tác giả của sách: "; getline(cin, tac_gia); 
        }
        void inSach(){
            cout << endl << "ID: " << id_sach << endl;
            cout << "Sách: " << tieu_de << endl;
            cout << "Tác giả: " << tac_gia << endl;
        }
};

vector<Sach> thu_vien;
class DocGia{
    protected:
        string ho_ten;
        string dia_chi;
        string sdt;
        string ngay_muon;
        string email;
    public:
};

class MuonTra: protected DocGia, protected Sach{
    public:

};

void chonMode(int &mode){
    do{
        cout << "Chọn chức năng dưới đây:" << endl 
             << "1. Thêm sách" << endl
             << "2. Tìm sách" << endl
             << "3. Thống kê sách" << endl
             << "3. Mượn sách" << endl
             << "4. Trả sách" << endl
             << "5. Gia hạn" << endl 
             << "0. Kết thúc" << endl << endl;
        cout << "Nhập chức năng (0-6) bạn muốn thực hiện: ";
        cin >> mode;
    } while (mode > 5 || mode < 0);

    switch (mode){
        case 1: {
            Sach sach_them;
            sach_them.khoiTaoSach();
            thu_vien.push_back(sach_them);
            break;
        }
        case 0:
            break;
    }
        
}

int main(){
    int mode=1;
    while(mode){
        chonMode(mode);
    }
    
    

}