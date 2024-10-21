#include <bits/stdc++.h>
using namespace std;

/*
Tasklist:
1. lưu thông tin vào db và trích xuất in đầy đủ
2. bugged case solve (ko cần thiét), đang giả sử constrain input là hợp lệ và bình thường
*/


// Đọc file database dạng txt
fstream book_file("@book_database.txt", ios::app | ios::in); // ios::app để đổi chế độ qua append mode (thêm kí tự)
fstream user_file("@user_database.txt", ios::app | ios::in);
// Them sach vao thu vien ngay khi khoi tao

// Lớp sách thực hiện chức năng làm khung và các chức năng nhập in tìm sách cơ bản
class SACH {
    protected:
        
        
    public:
        string id_sach;
        string tieu_de;
        string tac_gia;
        bool cho_muon = 1;
        string ngay_muon;
        string ngay_tra;

        SACH(){}
        SACH (string x, string y, string z, string t){
            id_sach = x;
            tieu_de = y; 
            tac_gia = z;
            if(t == "Có thể mượn") cho_muon = 1;
            else cho_muon = 0;
        }

        void khoiTaoSach(){
            cout << endl << "Thông tin cho sách mới thêm vào: " << endl;
            cout << "Nhập ID của sách: "; cin >> id_sach; cin.ignore();
            cout << "Nhập tiêu đề của sách: "; getline(cin, tieu_de); 
            cout << "Nhập tác giả của sách: "; getline(cin, tac_gia); 
        }

        void inSach(){
            cout << endl << left << setw(12) << "ID: " << id_sach << endl;
            cout << left << setw(13) << "Sách: " << tieu_de << endl;
            cout << left << setw(15) << "Tác giả: " << tac_gia << endl;
            if(cho_muon) cout << left << setw(12) <<"Tình trạng: Có thể mượn" << endl;
            else cout << left << setw(12) << "Tình trạng: Đã mượn" << endl;
        }

        void addSachtoDB(){
            // Viết vào file y như cout bình thường
            book_file << endl << left << setw(12) << "ID: " << id_sach << endl;
            book_file << left << setw(13) << "Sách: " << tieu_de << endl;
            book_file << left << setw(15) << "Tác giả: " << tac_gia << endl;
            if(cho_muon) book_file << left << setw(12) <<"Tình trạng: Có thể mượn";
            else book_file << left << setw(12) << "Tình trạng: Đã mượn";
        }
        // Tìm sách qua id (user truyền từ input)
        void timSach(string find_id){
            if(find_id == id_sach){
                inSach();
            }
        }
};

vector<SACH> thu_vien;

// Flow cho reader: đăng nhập chỉ bằng SĐT, khỏi tạo ngay khi user chạy code
class DOCGIA: public SACH{
    protected:
        string dia_chi;
        string ngay_muon;
        string email;
        vector<SACH> sach_muon;
    public: 
        string ho_ten;
        string sdt;
        
        // Thêm function nhập, in, ném vào database cho user (dùng form đã có sẵn như lớp SACH)
        // thêm lưu user vao database
        void khoiTaoUser(){
            cin.ignore();
            cout << endl << "Đăng kí tài khoản mới: " << endl;
            cout << "Nhập chúng tôi gọi bạn là: "; getline(cin, ho_ten); 
            cout << "Nhập địa chỉ của bạn: "; getline(cin, dia_chi); 
            cout << "Nhập email của bạn: "; getline(cin, email);
        }

        void addUserToDB(){

        }

        void inUser(){

        }
        
        string timUser(string find_sdt){
            if(find_sdt == sdt){
                return sdt;
            }
            else {
                cout << "SĐT chưa tồn tại trên hệ thống, vui lòng đăng kí.\n";
                khoiTaoUser();
                addUserToDB(); 
            }
        }
};

vector<DOCGIA> users_db;
DOCGIA current_user;

class MUONTRA: protected DOCGIA, protected SACH{
    public:
        void muonSach(){
            string find_id;

            for(auto a: thu_vien){
                if(a.cho_muon) {
                    a.inSach();
                }
            }

            cout << "Nhập ID sách bạn muốn mượn: "; cin >> find_id;
            for(auto a: thu_vien){
                if(a.cho_muon && a.id_sach == find_id) {
                    sach_muon.push_back(a); return;
                }
            }
            
            cout << "ID không hợp lệ, vui lòng thử lại." << endl;
            muonSach();
        }

};


void logIn(){
        string find_sdt;
        cout << "Đăng nhập (Tự động đăng kí nếu SĐT chưa tồn tại):" << endl; 
        cout << "Nhập số điện thoại: "; cin.ignore(); getline(cin, find_sdt);cin >> find_sdt;
        for(auto a: users_db){
            a.timUser(find_sdt);
        }   
}

void chonMode(int &mode){
    do{
        cout << endl << "Chọn chức năng dưới đây:" << endl << endl
             << "1. Thêm sách" << endl
             << "2. Tìm sách (theo ID sách)" << endl
             << "3. Thống kê sách" << endl
             << "4. Mượn sách" << endl
             << "5. Trả sách" << endl
             << "6. Gia hạn" << endl 
             << "7. Chỉnh sửa thông tin cá nhân" << endl
             << "8. Xem thông tin cá nhân" << endl
             << "0. Kết thúc" << endl << endl;
        cout << "Nhập chức năng (0-6) bạn muốn thực hiện: ";
        cin >> mode;
    } while (mode > 6 || mode < 0);

    switch (mode){
        case 1: {
            SACH sach_them;
            sach_them.khoiTaoSach();
            sach_them.addSachtoDB();
            thu_vien.push_back(sach_them);
            cout << "\n Đã thành công thêm sách:"; sach_them.inSach(); 
            break;
        }

        case 2:{
            string find_id;
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

        case 4:{

        }

        case 0:
            break;
    }
        
}

int main(){
    int mode=1;
    

    // Đọc database ngay khi khởi tạo chương trình (CẤM SỬA GÌ ĐOẠN NÀY NỮA)
    string read_line;
    while (getline(book_file, read_line)) {
        string x, y, z, t;

        getline(book_file, read_line); x = read_line.substr(12);
        getline(book_file, read_line); y = read_line.substr(13);
        getline(book_file, read_line); z = read_line.substr(15);
        getline(book_file, read_line); t = read_line.substr(15);
    
        thu_vien.push_back(SACH(x, y, z, t));
    }
    // ---------------------------------------------------------------------



    cout << "Xin chào, " << current_user.ho_ten << endl
         << "SĐT: " << current_user.sdt << endl << endl;

    while(mode){
        chonMode(mode);
    }
    
    

}