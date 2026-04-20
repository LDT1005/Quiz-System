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

// Khai báo nguyên mẫu hàm hỗ trợ từ file UI
int kiemTraHaiChuSo(char str[], int min, int max); 

// --- CÁC HÀM QUẢN LÝ THÔNG TIN THÍ SINH ---

int nhapThoiDiemBatDau(char ketQua[]) {
    char gio[10];
    char phut[10];

    while (1) {
        cout << "Nhap gio bat dau (HH): ";
        cin.getline(gio, 10);

        if (!kiemTraHaiChuSo(gio, 0, 23)) {
            cout << "=> Gio khong hop le! Vui long nhap 2 chu so tu 00 den 23.\n";
            continue;
        }

        cout << "Nhap phut bat dau (MM): ";
        cin.getline(phut, 10);

        if (!kiemTraHaiChuSo(phut, 0, 59)) {
            cout << "=> Phut khong hop le! Vui long nhap 2 chu so tu 00 den 59.\n";
            continue;
        }

        strcpy(ketQua, gio);
        strcat(ketQua, ":");
        strcat(ketQua, phut);
        return 1;
    }
}

/* // --- TRÍCH ĐOẠN LOGIC LÀM VIỆC CỦA HIẾU (Được ráp vào luồng chính) ---
    ThiSinh ts;
    cout << "\n--- NHAP THONG TIN THI SINH ---" << endl;
    cout << "Ho va ten: "; 
    cin.getline(ts.hoTen, 50);

    cout << "MSSV: "; 
    cin.getline(ts.mssv, 20);

    nhapThoiDiemBatDau(ts.thoiDiemBatDau);
*/