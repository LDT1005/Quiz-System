#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

// =================================================================
// [1] THIẾT KẾ DỮ LIỆU (STRUCT)
// =================================================================
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

// =================================================================
// [2] KHAI BÁO NGUYÊN MẪU HÀM
// =================================================================
int inMenuChinh();
char chuyenChuHoa(char c);
int chuyenChuoiThanhSo(char str[]);
int kiemTraHaiChuSo(char str[], int min, int max);
int nhapThoiDiemBatDau(char ketQua[]);
int docNganHangCauHoi(CauHoi* nganHang, const char* tenFile);
int thiTracNghiem(CauHoi* nganHang, int tongSoCau);
int ghiLichSuThi(ThiSinh ts, const char* tenFile);
int inBangLichSu(const char* tenFile);

// =================================================================
// [3] CHƯƠNG TRÌNH CHÍNH (MAIN)
// =================================================================
int main() {
    CauHoi nganHangDe[500];

    int soLuongCau = docNganHangCauHoi(nganHangDe, "data/cauhoi.txt");
    if (soLuongCau == 0) {
        cout << "LOI: Khong the doc file 'data/cauhoi.txt' hoac file rong!" << endl;
        return 1;
    }

    int luaChon;
    do {
        inMenuChinh();
        cout << "Moi ban chon (0-2): ";

        char nhapMenu[10];
        cin.getline(nhapMenu, 10);
        luaChon = chuyenChuoiThanhSo(nhapMenu);

        switch (luaChon) {
            case 1:
                thiTracNghiem(nganHangDe, soLuongCau);
                break;
            case 2:
                inBangLichSu("data/history.txt");
                break;
            case 0:
                cout << "Tam biet! Hen gap lai." << endl;
                break;
            default:
                cout << "Lua chon sai, vui long nhap lai so tu 0 den 2." << endl;
        }
    } while (luaChon != 0);

    return 0;
}

// =================================================================
// [4] ĐỊNH NGHĨA CHI TIẾT CÁC HÀM
// =================================================================

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

// Kiểm tra chuỗi có đúng 2 chữ số và nằm trong khoảng min-max hay không
int kiemTraHaiChuSo(char str[], int min, int max) {
    if (strlen(str) != 2) return 0;
    if (!(str[0] >= '0' && str[0] <= '9')) return 0;
    if (!(str[1] >= '0' && str[1] <= '9')) return 0;

    int value = (str[0] - '0') * 10 + (str[1] - '0');
    if (value < min || value > max) return 0;

    return 1;
}

// Nhập thời điểm bắt đầu theo dạng HH:MM
// Do giới hạn phạm vi kiến thức, chương trình nhập giờ và phút riêng rồi tự ghép lại.
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

    // --- GIAI ĐOẠN 1: THI TUẦN TỰ ---
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

            // Bắt buộc chỉ được nhập đúng 1 ký tự
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

    // --- GIAI ĐOẠN 2: REVIEW VÀ EDIT ---
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

    // --- CHẤM ĐIỂM & BÁO CÁO CHI TIẾT ĐÚNG / SAI ---
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