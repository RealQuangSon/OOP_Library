#include<bits/stdc++.h>
using namespace std;

class Nguoi {
    private:
    string maso;
    string hoten;
    double luong;
    public:
    void laythongtin(){
        getline(cin, maso); cin.ignore();
        getline(cin, hoten); cin.ignore();
        cin >> luong;
    }

};

class Bienche: private Nguoi{
    private:
    double hesoluong;
    double tienphu;
    string chucvu;
    public:
    double luongcung(int ){

    }

};

class Hopdong: private Nguoi{
    private:
        double tien_cong;
        int so_ngay;
        float he_so;
};


int main(){
    Nguoi nhanvien1;
    nhanvien1.laythongtin();
}
