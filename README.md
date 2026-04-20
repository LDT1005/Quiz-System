# 🚀 QUIZ APPLICATION: C/C++ CONSOLE EDITION

> **Hệ thống thi trắc nghiệm trên nền tảng Console, tập trung vào xử lý dữ liệu bằng mảng, struct, file và quản lý logic bài thi một cách chặt chẽ.**

---

## 💎 TỔNG QUAN DỰ ÁN (PROJECT OVERVIEW)

**Ứng Dụng Thi Trắc Nghiệm** là một chương trình chạy trên môi trường Console, được xây dựng bằng ngôn ngữ C/C++ nhằm mô phỏng quy trình làm bài thi trắc nghiệm cơ bản. Dự án tập trung vào việc vận dụng các kiến thức lập trình nền tảng như hàm, mảng, chuỗi ký tự, struct, con trỏ và xử lý tệp tin.

Chương trình cho phép người dùng:
- Nạp bộ câu hỏi từ file
- Nhập thông tin cá nhân trước khi làm bài
- Trả lời từng câu hỏi theo thứ tự
- Bỏ qua câu hỏi để xử lý sau
- Chỉnh sửa đáp án trước khi nộp bài
- Chấm điểm tự động
- Lưu lịch sử bài thi
- Hiển thị bảng xếp hạng dựa trên kết quả đã lưu

### 🎯 Mục tiêu của dự án
- Vận dụng kiến thức lập trình cơ bản đã học vào một bài toán thực tế
- Rèn luyện tư duy phân chia chức năng theo từng khối xử lý
- Làm quen với thao tác đọc/ghi file văn bản
- Tổ chức dữ liệu bằng `struct`
- Quản lý chương trình theo luồng xử lý rõ ràng, dễ kiểm tra và dễ mở rộng

---

## 🛠 THÔNG SỐ KỸ THUẬT & PHẠM VI (TECHNICAL STACK)

Dự án được xây dựng theo đúng phạm vi kiến thức cơ bản, không sử dụng các thư viện nâng cao hoặc mô hình lập trình ngoài yêu cầu môn học.

### Công nghệ và kỹ thuật sử dụng
- **Ngôn ngữ:** C/C++
- **Thư viện sử dụng:**
  - `iostream`
  - `fstream`
  - `string.h`
  - `time.h`

### Kiến thức được áp dụng
- Cấu trúc điều khiển: `if`, `else`, `switch`
- Vòng lặp: `for`, `while`, `do...while`
- Hàm
- Mảng tĩnh và mảng động
- Chuỗi ký tự kiểu `char[]`
- Con trỏ và cấp phát động `new[]`, `delete[]`
- Struct
- Đọc/ghi file bằng `ifstream`, `ofstream`

> [!CAUTION]
> **Giới hạn triển khai của dự án**
>
> 1. Không sử dụng STL như `vector`, `string`, `map`, `list`, ...
> 2. Không sử dụng lập trình hướng đối tượng (`class`, kế thừa, đa hình)
> 3. Không sử dụng cơ sở dữ liệu
> 4. Không sử dụng đa luồng
> 5. Dữ liệu được quản lý bằng mảng, struct và file text

---

## ✨ CHỨC NĂNG HỆ THỐNG (SYSTEM FEATURES)

| STT | Chức năng | Mô tả |
|---|---|---|
| 1 | Đọc dữ liệu câu hỏi từ file | Chương trình đọc nội dung câu hỏi, 4 đáp án và đáp án đúng từ file `cauhoi.txt`. |
| 2 | Nhập thông tin thí sinh | Người dùng nhập họ tên, MSSV và thời điểm bắt đầu bài thi theo định dạng `HH:MM`. |
| 3 | Hiển thị bài thi | Hệ thống hiển thị lần lượt từng câu hỏi và các phương án trả lời A, B, C, D. |
| 4 | Chọn đáp án | Thí sinh có thể chọn một đáp án hợp lệ cho mỗi câu hỏi. |
| 5 | Skip câu hỏi | Cho phép bỏ qua câu hỏi bằng ký tự `S` để xem lại sau. |
| 6 | Chỉnh sửa đáp án | Trước khi nộp bài, thí sinh có thể xem bảng tóm tắt và sửa lại đáp án của từng câu. |
| 7 | Chấm điểm tự động | Sau khi nộp bài, chương trình tự động đối chiếu đáp án và tính số câu đúng, điểm số. |
| 8 | Hiển thị kết quả | Kết quả bao gồm thông tin thí sinh, thời điểm bắt đầu, thời gian làm bài, số câu đúng và điểm số. |
| 9 | Lưu lịch sử thi | Kết quả mỗi lần thi được ghi vào file `history.txt`. |
| 10 | Bảng xếp hạng | Chương trình đọc lịch sử thi, sắp xếp theo điểm và hiển thị bảng xếp hạng. |

---

## 🧬 KIẾN TRÚC DỮ LIỆU (DATA ARCHITECTURE)

Chương trình sử dụng 2 cấu trúc dữ liệu chính:

```cpp
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