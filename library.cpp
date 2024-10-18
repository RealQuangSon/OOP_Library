#include <bits/stdc++.h>
using namespace std;

// Lớp sách thực hiện chức năng làm khung và các chức năng nhập in tìm sách cơ bản
class Sach {
    protected:
        int id_sach;
        string tieu_de;
        string tac_gia;
        bool cho_muon = 1;
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
            if(cho_muon) cout << "Tình trạng: Có thể mượn" << endl;
            else cout << "Tình trạng: Đã mượn" << endl;
        }
        void timSach(int find_id){
            if(find_id == id_sach){
                inSach();
            }
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

vector<DocGia> users_db;

class MuonTra: protected DocGia, protected Sach{
    public:
        void muonSach(){

        }

};


void chonMode(int &mode){
    do{
        cout << endl << "Chọn chức năng dưới đây:" << endl << endl
             << "1. Thêm sách" << endl
             << "2. Tìm sách (theo ID sách)" << endl
             << "3. Thống kê sách" << endl
             << "4. Mượn sách" << endl
             << "5. Trả sách" << endl
             << "6. Gia hạn" << endl 
             << "0. Kết thúc" << endl << endl;
        cout << "Nhập chức năng (0-6) bạn muốn thực hiện: ";
        cin >> mode;
    } while (mode > 6 || mode < 0);

    switch (mode){
        case 1: {
            Sach sach_them;
            sach_them.khoiTaoSach();
            thu_vien.push_back(sach_them);
            break;
        }

        case 2:{
            int find_id;
            cout << "Nhập ID sách: "; cin >> find_id;
            for(auto a: thu_vien){
                a.timSach(find_id);
            } 
        }

        case 3: {
            cout << "------------------------------------" << endl;
            cout << "Tổng hợp sách của thư viện:" << endl;
            for(auto a: thu_vien){
                a.inSach();

            }
            cout << endl << endl << "Tổng số sách trong thư viện: " << thu_vien.size() << endl;
            cout << "------------------------------------" << endl;
        }

        case 4:

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