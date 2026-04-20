#include <iostream>
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

// KHAI BÁO HÀM LIÊN QUAN ĐỂ GIỮ NGUYÊN LOGIC HIỆN TẠI

char chuyenChuHoa(char c);
int chuyenChuoiThanhSo(char str[]);
int nhapThoiDiemBatDau(char ketQua[]);
int ghiLichSuThi(ThiSinh ts, const char* tenFile);

// LUỒNG THI CHÍNH

int thiTracNghiem(CauHoi* nganHang, int tongSoCau) {
    ThiSinh ts;
    cout << "\n--- NHAP THONG TIN THI SINH ---" << endl;
    cout << "Ho va ten: ";
    cin.getline(ts.hoTen, 50);

    cout << "MSSV: ";
    cin.getline(ts.mssv, 20);

    nhapThoiDiemBatDau(ts.thoiDiemBatDau);

    int soCauHoiThi = 5;
    if (tongSoCau < soCauHoiThi) soCauHoiThi = tongSoCau;

    CauHoi* deThi = new CauHoi[soCauHoiThi];
    for (int i = 0; i < soCauHoiThi; i++) {
        deThi[i] = nganHang[i];
    }

    // LẤY THỜI GIAN THỰC TẾ CỦA MÁY TÍNH
    long thoiGianBatDauThuc = time(0);

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

            // Chỉ được nhập đúng 1 ký tự
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

    // REVIEW VÀ EDIT
    int dangReview = 1;
    while (dangReview == 1) {
        cout << "\n=========== BANG TOM TAT BAI LAM ===========" << endl;
        for (int i = 0; i < soCauHoiThi; i++) {
            cout << "Cau " << (i + 1) << ": [";
            if (deThi[i].dapAnCuaUser == 'S' || deThi[i].dapAnCuaUser == ' ') cout << "Chua lam";
            else cout << deThi[i].dapAnCuaUser;
            cout << "]\t";
            if ((i + 1) % 2 == 0) cout << endl;
        }

        cout << "\nNhap STT cau hoi ban muon SUA (1 den " << soCauHoiThi << "). Nhap '0' de NOP BAI: ";
        char nhapSua[10];
        cin.getline(nhapSua, 10);
        int cauSua = chuyenChuoiThanhSo(nhapSua);

        if (cauSua == 0) {
            cout << "Ban co chac chan nop bai? (Y/N): ";
            char xacNhan[10];
            cin.getline(xacNhan, 10);

            if (strlen(xacNhan) != 1) {
                cout << "=> Chi duoc nhap DUNG 1 ky tu Y hoac N.\n";
                continue;
            }

            char qd = chuyenChuHoa(xacNhan[0]);
            if (qd == 'Y') dangReview = 0;
            else if (qd != 'N') cout << "=> Lua chon khong hop le!\n";
        }
        else if (cauSua >= 1 && cauSua <= soCauHoiThi) {
            int i = cauSua - 1;
            cout << "\n--- Sua Cau " << cauSua << " ---" << endl;
            cout << deThi[i].noiDung << endl;
            cout << "A. " << deThi[i].dapAnA << "\nB. " << deThi[i].dapAnB << endl;
            cout << "C. " << deThi[i].dapAnC << "\nD. " << deThi[i].dapAnD << endl;
            cout << "Dap an cu: " << deThi[i].dapAnCuaUser << endl;
            cout << "Nhap dap an moi (A/B/C/D): ";

            char nhapMoi[10];
            cin.getline(nhapMoi, 10);

            if (strlen(nhapMoi) == 0) {
                cout << "=> Ban chua nhap du lieu.\n";
            } else if (strlen(nhapMoi) != 1) {
                cout << "=> Ban chi duoc nhap DUNG 1 ky tu. Giu nguyen dap an cu.\n";
            } else {
                char chon = chuyenChuHoa(nhapMoi[0]);
                if (chon == 'A' || chon == 'B' || chon == 'C' || chon == 'D') {
                    deThi[i].dapAnCuaUser = chon;
                    cout << "=> Da sua thanh cong!\n";
                } else {
                    cout << "=> Dap an khong hop le. Giu nguyen dap an cu.\n";
                }
            }
        } else {
            cout << "=> STT cau hoi khong hop le!\n";
        }
    }

    // CHỐT THỜI GIAN THỰC TẾ
    ts.tongThoiGian = time(0) - thoiGianBatDauThuc;

    // CHẤM ĐIỂM & BÁO CÁO CHI TIẾT ĐÚNG / SAI
    ts.soCauDung = 0;
    cout << "\n================ CHI TIET DUNG / SAI ================" << endl;
    for (int i = 0; i < soCauHoiThi; i++) {
        cout << "Cau " << (i + 1) << ": " << deThi[i].noiDung << endl;
        cout << "   -> Ban chon: [" << deThi[i].dapAnCuaUser << "] | Dap an dung: [" << deThi[i].dapAnDung << "] => ";

        if (deThi[i].dapAnCuaUser == deThi[i].dapAnDung) {
            ts.soCauDung++;
            cout << "DUNG" << endl;
        } else if (deThi[i].dapAnCuaUser == 'S' || deThi[i].dapAnCuaUser == ' ') {
            cout << "CHUA LAM" << endl;
        } else {
            cout << "SAI" << endl;
        }
    }

    ts.diem = ((float)ts.soCauDung / soCauHoiThi) * 10.0;

    cout << "\n=== KET QUA TONG KET ===" << endl;
    cout << "Thi sinh: " << ts.hoTen << " - " << ts.mssv << endl;
    cout << "Thoi diem bat dau: " << ts.thoiDiemBatDau << endl;
    cout << "So cau dung: " << ts.soCauDung << "/" << soCauHoiThi << endl;
    cout << "Diem so: " << ts.diem << " / 10" << endl;
    cout << "Tong thoi gian lam bai: " << ts.tongThoiGian << " giay" << endl;

    ghiLichSuThi(ts, "data/history.txt");
    delete[] deThi;

    return 1;
}