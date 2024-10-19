#include <bits/stdc++.h>
using namespace std;

// Đọc file database dạng txt
fstream book_file("@book_database.txt", ios::app); // ios::app để đổi chế độ qua append mode (thêm kí tự)
fstream user_file("@user_database.txt", ios::app);

// Lớp sách thực hiện chức năng làm khung và các chức năng nhập in tìm sách cơ bản
class SACH {
    protected:
        string id_sach;
        string tieu_de;
        string tac_gia;
        bool cho_muon = 1;
    public: // mỗi function đều hoạt động word by word
        // Thêm một hàm tạo (cho có kiến thức) cho việc thêm sách thủ công ngay trong code ??




        // 

        void khoiTaoSach(){
            cout << endl << "Thông tin cho sách mới thêm vào: " << endl;
            cout << "Nhập ID của sách: "; cin >> id_sach; cin.ignore();
            cout << "Nhập tiêu đề của sách: "; getline(cin, tieu_de); 
            cout << "Nhập tác giả của sách: "; getline(cin, tac_gia); 
        }

        void inSach(){
            cout << endl << "ID: " << id_sach << endl;
            id_sach.empty() ? "NULL" : id_sach;
            cout << "Sách: " << tieu_de << endl;
            cout << "Tác giả: " << tac_gia << endl;
            if(cho_muon) cout << "Tình trạng: Có thể mượn" << endl;
            else cout << "Tình trạng: Đã mượn" << endl;
        }

        void addSachtoDB(){
            // Viết vào file y như cout bình thường
            book_file << endl << "ID: " << id_sach << endl;
            id_sach.empty() ? "NULL" : id_sach;
            book_file << "Sách: " << tieu_de << endl;
            book_file << "Tác giả: " << tac_gia << endl;
            if(cho_muon) book_file << "Tình trạng: Có thể mượn" << endl;
            else book_file << "Tình trạng: Đã mượn" << endl;
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
class DOCGIA{
    protected:
        string dia_chi;
        string ngay_muon;
        string email;
    public: 
        string ho_ten;
        string sdt;
        void timUser(string find_sdt){

        }
        
        // Thêm function nhập, in, ném vào database cho user (dùng form đã có sẵn như lớp SACH)
};

vector<DOCGIA> users_db;
DOCGIA current_user;

class MUONTRA: protected DOCGIA, protected SACH{
    public:
        
        void muonSach(){

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



    cout << "Xin chào, " << current_user.ho_ten << endl
         << "SĐT: " << current_user.sdt << endl << endl;

    while(mode){
        chonMode(mode);
    }
    
    

}