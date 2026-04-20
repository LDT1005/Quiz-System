#include <iostream>
#include <string.h>

using namespace std;

// HIỂN THỊ MENU CHÍNH

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

// CHUYỂN CHỮ THƯỜNG THÀNH CHỮ HOA

char chuyenChuHoa(char c) {
    if (c >= 'a' && c <= 'z') return c - 32;
    return c;
}

// CHUYỂN CHUỖI THÀNH SỐ NGUYÊN

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

// KIỂM TRA CHUỖI CÓ ĐÚNG 2 CHỮ SỐ VÀ NẰM TRONG KHOẢNG CHO PHÉP

int kiemTraHaiChuSo(char str[], int min, int max) {
    if (strlen(str) != 2) return 0;
    if (!(str[0] >= '0' && str[0] <= '9')) return 0;
    if (!(str[1] >= '0' && str[1] <= '9')) return 0;

    int value = (str[0] - '0') * 10 + (str[1] - '0');
    if (value < min || value > max) return 0;

    return 1;
}

// NHẬP THỜI ĐIỂM BẮT ĐẦU THEO DẠNG HH:MM
// Chương trình nhập giờ và phút riêng rồi tự ghép lại

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