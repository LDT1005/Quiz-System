#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

// THIẾT KẾ DỮ LIỆU (STRUCT)
struct CauHoi {
    char noiDung[256];
    char dapAnA[128];
    char dapAnB[128];
    char dapAnC[128];
    char dapAnD[128];
    char dapAnDung;
    char dapAnCuaUser;
};

struct ThiSinh {
    char hoTen[50];
    char mssv[20];
    char thoiDiemBatDau[20];
    int soCauDung;
    float diem;
    long tongThoiGian;
};

// --- CÁC HÀM XỬ LÝ GIAO DIỆN & KIỂM TRA ĐẦU VÀO ---

int inMenuChinh() {
    cout << "\n========================================" << endl;
    cout << "       UNG DUNG THI TRAC NGHIEM         " << endl;
    cout << "========================================" << endl;
    cout << "1. Bat dau thi" << endl;
    cout << "2. Xem bang xep hang (Lich su thi)" << endl;
    cout << "0. Thoat" << endl;
    cout << "========================================" << endl;
    return 1;
}

char chuyenChuHoa(char c) {
    if (c >= 'a' && c <= 'z') return c - 32;
    return c;
}

int chuyenChuoiThanhSo(char str[]) {
    if (strlen(str) == 0) return -1;
    int num = 0;
    for (int i = 0; i < (int)strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
        } else {
            return -1;
        }
    }
    return num;
}

int kiemTraHaiChuSo(char str[], int min, int max) {
    if (strlen(str) != 2) return 0;
    if (!(str[0] >= '0' && str[0] <= '9')) return 0;
    if (!(str[1] >= '0' && str[1] <= '9')) return 0;

    int value = (str[0] - '0') * 10 + (str[1] - '0');
    if (value < min || value > max) return 0;

    return 1;
}