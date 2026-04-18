# 🚀 QUIZ APPLICATION: C/C++ CONSOLE EDITION

> **Hệ thống thi trắc nghiệm Console: Tối ưu logic, quản lý bộ nhớ thủ công và xử lý luồng dữ liệu tệp tin.**

-----

## 💎 TỔNG QUAN DỰ ÁN (PROJECT OVERVIEW)

**Ứng Dụng Thi Trắc Nghiệm** là một dự án phần mềm chạy trên nền tảng Console (C/C++), được thiết kế để mô phỏng quy trình làm bài thi trắc nghiệm. Dự án được phát triển theo định hướng học thuật khắt khe, tập trung sâu vào kỹ năng tổ chức mã nguồn, phân rã bài toán và thao tác dữ liệu ở mức độ cơ bản.

**Mục tiêu cốt lõi:**

  * **Chuyên môn:** Vận dụng triệt để kiến thức lập trình nền tảng (Cấu trúc điều khiển, Hàm, Mảng, Con trỏ, Struct, File).
  * **Kỹ thuật:** Thực hành tư duy phân rã thành các khối chức năng (Modular design) và quản lý dữ liệu hoàn toàn bằng mảng tĩnh/động.
  * **Sản phẩm:** Xây dựng một bài làm hoàn thiện, logic chặt chẽ, phục vụ trực tiếp cho việc nộp đồ án môn học.

-----

## 🛠 THÔNG SỐ KỸ THUẬT & PHẠM VI (TECHNICAL STACK)

Hệ thống được phát triển trên nền tảng C/C++ nguyên thủy ("Old-school"), tuân thủ tuyệt đối giới hạn của 7 chương kiến thức nền tảng:

  * **Core Logic:** Rẽ nhánh (`if`, `switch`), Vòng lặp (`for`, `while`, `do-while`), Lệnh điều khiển (`break`, `continue`).
  * **Architecture:** Lập trình cấu trúc với **Hàm** (truyền tham trị, tham chiếu, địa chỉ).
  * **Data Types:** Mảng 1 chiều/2 chiều, Chuỗi ký tự `char[]` (C-style string).
  * **Memory:** Con trỏ và cấp phát động thủ công (`new`, `delete`, `delete[]`).
  * **Data Storage:** Đóng gói bằng `struct` và thao tác đọc/ghi tệp tin (`fstream`, `ifstream`, `ofstream`).

> [\!CAUTION]
> **KỶ LUẬT MÃ NGUỒN (RED LINES):**
>
> 1.  **Cấm tuyệt đối STL:** Không sử dụng `vector`, `list`, `map`, `set`, v.v.
> 2.  **Cấm Lập trình hướng đối tượng (OOP):** Không `class`, không kế thừa, không đa hình.
> 3.  **Cấm Đa luồng & CSDL:** Không đa luồng (Multithreading), không kết nối cơ sở dữ liệu.
> 4.  **Giới hạn thời gian:** Chỉ sử dụng thời gian mô phỏng (không dùng đồng hồ hệ thống chạy song song để tránh vượt rào kiến thức).
> 5.  **Yêu cầu bắt buộc:** Mã nguồn phải đính kèm file phân công `phancong_manhom.xls`.

-----

## ✨ CHỨC NĂNG HỆ THỐNG (SYSTEM FEATURES)

| Icon | Tính năng | Mô tả chi tiết |
| :--- | :--- | :--- |
| 📥 | **Data Loader** | Tự động đọc danh sách câu hỏi, phương án (A, B, C, D) và đáp án chuẩn từ file text. |
| 👤 | **User Session** | Ghi nhận thông tin định danh thí sinh (Họ tên, MSSV). Hiển thị đồng bộ tổng số câu và thời gian làm bài. |
| ⏭️ | **Smart Navigation** | Cho phép chọn đáp án, **Skip** (bỏ qua câu hỏi để làm sau), và **Edit** (chỉnh sửa đáp án trước khi nộp). |
| 📊 | **Auto Grading** | Tổng hợp kết quả: Thông tin thí sinh, mốc bắt đầu, tổng thời gian, số câu đúng và tổng điểm. |
| 🚀 | **Pro Modules**<br>*(Mở rộng)* | Trích xuất đề ngẫu nhiên từ Ngân hàng đề, xáo trộn câu hỏi/đáp án, và hệ thống History & Leaderboard. |

-----

## 🧬 KIẾN TRÚC DỮ LIỆU & TỔ CHỨC (DATA ARCHITECTURE)

Dự án được cấu trúc thành 4 khối chức năng độc lập: **Khối Dữ liệu**, **Khối Xử lý File**, **Khối Logic Thi**, và **Khối Tiện ích**.

*(Ghi chú suy luận: Khối mã nguồn dưới đây được minh họa dựa trên yêu cầu sử dụng mảng, `char[]` và con trỏ từ tài liệu gốc nhằm làm rõ cách đóng gói `struct` hợp lệ).*

```cpp
// Quản lý bộ đề thi
struct CauHoi {
    char noiDung[256];
    char dsDapAn[4][100]; // 4 phương án A, B, C, D
    char dapAnDung;
};

// Quản lý thực thể thí sinh
struct ThiSinh {
    char hoTen[50];
    char mssv[15];
    char* dsTraLoi;       // Quản lý bằng mảng động để đối chiếu
    float tongDiem;
};
```

### 📂 Cấu trúc thư mục dự kiến

```text
/
├── main.cpp                # Hàm main() và logic điều hướng menu chính
├── cauhoi.txt              # Dữ liệu ngân hàng câu hỏi gốc (File Text ưu tiên)
├── history.txt             # Nơi lưu vết kết quả và bảng xếp hạng
└── phancong_manhom.xls     # File Excel phân công nhiệm vụ (Bắt buộc)
```

-----

## ⚙️ LUỒNG VẬN HÀNH (EXECUTION FLOW)

1.  **Khởi động:** Nạp dữ liệu câu hỏi từ tệp vào bộ nhớ.
2.  **Xác thực:** Ghi nhận thông tin cá nhân của thí sinh.
3.  **Làm bài:** Xuất tuần tự câu hỏi lên Console. Xử lý logic chọn đáp án, bỏ qua (Skip) hoặc sửa lỗi (Edit).
4.  **Kết thúc:** Thí sinh nộp bài, hệ thống kích hoạt khối tiện ích để chấm điểm đối chiếu.
5.  **Báo cáo:** Hiển thị kết quả ra màn hình (Thông tin, Điểm số, Trạng thái) và ghi xuất lịch sử bài làm ra `history.txt`.

-----

## ⚠️ LƯU Ý KỸ THUẬT SỐNG CÒN (CRITICAL IMPLEMENTATION NOTES)

> **1. Ngăn chặn Rò rỉ bộ nhớ (Memory Leak)**
> Nếu sử dụng mảng động (con trỏ) để lưu trữ dữ liệu câu hỏi hay danh sách đáp án, **bắt buộc** phải có lệnh giải phóng bộ nhớ (`delete` hoặc `delete[]`) trước khi chương trình kết thúc.

> **2. Kiểm soát Tràn mảng (Buffer Overflow)**
> Phải lường trước và kiểm soát chặt chẽ kích thước chuỗi nhập vào (tên, MSSV) và số lượng phần tử của mảng tĩnh để tránh vượt quá bộ nhớ đã cấp phát.

> **3. Nguy cơ Lặp vô tận (Infinite Loop)**
> Chức năng **Skip** đòi hỏi cơ chế đánh dấu cờ (flag) cực kỳ chính xác để hệ thống phân biệt được câu đã làm, câu bỏ qua và câu cần quay lại. Sai logic sẽ dẫn đến kẹt vòng lặp bài thi.

> **4. Lỗi Trôi bộ đệm (Buffer Clearing)**
> Thao tác nhập chuỗi có khoảng trắng (Họ tên) rất dễ gây lỗi trôi lệnh nếu không xử lý bộ đệm cẩn thận khi kết hợp đọc dữ liệu số và chữ.