#include <iostream>
#include <fstream>
#include <string.h>

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

// ĐỌC NGÂN HÀNG CÂU HỎI TỪ FILE

int docNganHangCauHoi(CauHoi* nganHang, const char* tenFile) {
    ifstream file(tenFile);
    if (!file.is_open()) return 0;

    int count = 0;
    while (count < 500 && file.getline(nganHang[count].noiDung, 256)) {
        if (strlen(nganHang[count].noiDung) == 0) continue;

        file.getline(nganHang[count].dapAnA, 128);
        file.getline(nganHang[count].dapAnB, 128);
        file.getline(nganHang[count].dapAnC, 128);
        file.getline(nganHang[count].dapAnD, 128);

        char tam[10];
        file.getline(tam, 10);
        nganHang[count].dapAnDung = tam[0];
        nganHang[count].dapAnCuaUser = ' ';

        count++;
    }
    file.close();
    return count;
}