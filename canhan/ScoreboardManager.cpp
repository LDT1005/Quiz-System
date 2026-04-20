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
int chuyenChuoiThanhSo(char str[]);

// --- CÁC HÀM XỬ LÝ LỊCH SỬ VÀ BẢNG XẾP HẠNG ---

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

/*
// --- TRÍCH ĐOẠN LOGIC LÀM VIỆC CỦA THÀNH (Được ráp vào luồng chính) ---
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
*/