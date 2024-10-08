#include<iostream>

using namespace std;

struct NV {
    string MANV;
    string HO, TEN, PHAI;
};

class Nhanvien {
    NV *DSNhanvien = new NV[500];
    public:
    nhap() {
        
    }
}


class Nodehd {
    public:
    char SoHD[20];
    string ngay;
    char Loai;
    Node *next;
    Node(char SoHD, string ngay, char Loai) {
        this->SoHD = SoHD;
        this->ngay = ngay;
        this->Loai = loai;
        this->next = nullptr;
    }
};

class HOADON {
    Nodehd *headnhap;
    Nodehd *headxuat;
    DSCT_HOADON *cthoadon;
    public:
    HOADON() {
        headnhap = nullptr:
        headxuat = nullptr;
    }
    void themhd(char SoHD, string ngay, char Loai) {
        Nodehd *newnode = new Nodehd(SoHD, ngay, Loai);
        if (Loai == 'N') {
            if (head == nullptr) {
                head = newnode;
            }
             else {
                Node *last = headnhap;
                while (last->next != nullptr) {
                last = last->next;
            }
            last->next = newnode;
        }
        return;
        }
        else if (Loai == 'X') {
            if (head == nullptr) {
                head = newnode;
            }
             else {
                Node *last = headxuat;
                while (last->next != nullptr) {
                last = last->next;
            }
            last->next = newnode;
        }
        return;
        }
    }
    void in() {
        for ( Node *k = head; k != nullptr; k=k->next) {
            cout << k->SoHd << endl;
            cout << k->ngay << endl;
            cout << k->Loai << endl;
        }
    }
}

class Nodecthd {
    public:
    string MAVT;
    int Soluong;
    float Dongia;
    float VAT;
    Nodecthd *next;
    Node(string MAVT, int Soluong, float Dongia, float VAT) {
        this->MAVT = MAVT;
        this->Soluong = Soluong;
        this->Dongia = Dongia;
        this->VAT = VAT;
    }
}

class DSCT_HOADON {
    Nodecthd *head;
    public:
    CT_HOADON() {
        head = nullptr;
    }
    void themcthd(string MAVT, int Soluong, float Dongia, float VAT) {

    }

}


int main() {

}