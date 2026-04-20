#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// THIẾT KẾ DỮ LIỆU (STRUCT)

struct ThiSinh {
    char hoTen[50];
    char mssv[20];
    char thoiDiemBatDau[20];
    int soCauDung;
    float diem;
    long tongThoiGian;
};

// GHI LỊCH SỬ THI

int ghiLichSuThi(ThiSinh ts, const char* tenFile) {
    ofstream file(tenFile, ios::app);
    if (file.is_open()) {
        file << ts.mssv << "\n"
             << ts.hoTen << "\n"
             << ts.thoiDiemBatDau << "\n"
             << ts.soCauDung << "\n"
             << ts.diem << "\n"
             << ts.tongThoiGian << "\n";
        file.close();
        return 1;
    }
    return 0;
}

// ĐỌC LỊCH SỬ VÀ HIỂN THỊ BẢNG XẾP HẠNG

int inBangLichSu(const char* tenFile) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        cout << "\nChua co du lieu lich su thi!" << endl;
        return 0;
    }

    ThiSinh ds[100];
    int count = 0;

    while (count < 100 && file.getline(ds[count].mssv, 20)) {
        file.getline(ds[count].hoTen, 50);
        file.getline(ds[count].thoiDiemBatDau, 20);
        file >> ds[count].soCauDung;
        file >> ds[count].diem;
        file >> ds[count].tongThoiGian;

        char boQua[10];
        file.getline(boQua, 10);
        count++;
    }
    file.close();

    if (count == 0) {
        cout << "\nDanh sach lich su thi trong!" << endl;
        return 0;
    }

    // Bubble Sort
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (ds[i].diem < ds[j].diem) {
                ThiSinh temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    cout << "\n================================ BANG XEP HANG ================================\n";
    cout << "MSSV\t\tHo ten\t\tBat Dau\t\tSo cau\tDiem\tThoi gian\n";
    cout << "-------------------------------------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << ds[i].mssv << "\t\t" << ds[i].hoTen << "\t\t" << ds[i].thoiDiemBatDau
             << "\t\t" << ds[i].soCauDung << "\t" << ds[i].diem << "\t" << ds[i].tongThoiGian << "s" << endl;
    }

    return 1;
}