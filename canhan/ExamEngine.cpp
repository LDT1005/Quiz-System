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
char chuyenChuHoa(char c);

// --- CÁC HÀM XỬ LÝ LÕI BÀI THI ---

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

/*
// --- TRÍCH ĐOẠN LOGIC LÀM VIỆC CỦA LONG (Được ráp vào luồng chính) ---
    int soCauHoiThi = 5;
    if (tongSoCau < soCauHoiThi) soCauHoiThi = tongSoCau;

    CauHoi* deThi = new CauHoi[soCauHoiThi];
    for (int i = 0; i < soCauHoiThi; i++) {
        deThi[i] = nganHang[i];
    }

    cout << "\n========================================" << endl;
    cout << "CHUYEN BI BAT DAU BAI THI" << endl;
    cout << "Tong so cau hoi: " << soCauHoiThi << " cau" << endl;
    cout << "Thoi diem bat dau: " << ts.thoiDiemBatDau << endl;
    cout << "========================================" << endl;

    // THI TUẦN TỰ
    for (int i = 0; i < soCauHoiThi; i++) {
        int chonHopLe = 0;
        while (chonHopLe == 0) {
            cout << "\n----------------------------------------" << endl;
            cout << "--- CAU HOI " << (i + 1) << "/" << soCauHoiThi << " ---" << endl;
            cout << deThi[i].noiDung << endl;
            cout << "A. " << deThi[i].dapAnA << endl;
            cout << "B. " << deThi[i].dapAnB << endl;
            cout << "C. " << deThi[i].dapAnC << endl;
            cout << "D. " << deThi[i].dapAnD << endl;

            cout << "\nBam [A,B,C,D] de chon | [S] de Skip: ";
            char nhap[10];
            cin.getline(nhap, 10);

            if (strlen(nhap) == 0) continue;

            if (strlen(nhap) != 1) {
                cout << "Lua chon khong hop le! Ban chi duoc nhap DUNG 1 ky tu." << endl;
                continue;
            }

            char chon = chuyenChuHoa(nhap[0]);

            if (chon == 'S' || chon == 'A' || chon == 'B' || chon == 'C' || chon == 'D') {
                deThi[i].dapAnCuaUser = chon;
                chonHopLe = 1;
            } else {
                cout << "Lua chon khong hop le!" << endl;
            }
        }
    }
*/