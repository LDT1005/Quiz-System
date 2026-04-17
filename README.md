# 🚀 QUIZ MASTER: C++ CORE EDITION
> **Hệ thống thi trắc nghiệm tối ưu hóa bộ nhớ và xử lý luồng dữ liệu tệp tin.**

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B)
![Memory](https://img.shields.io/badge/Memory-Manual_Management-orange?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Academic_Pure-green?style=for-the-badge)

---

## 💎 TỔNG QUAN DỰ ÁN (PROJECT OVERVIEW)

**Quiz Master** là một ứng dụng Console mạnh mẽ, được thiết kế để xử lý các kỳ thi trắc nghiệm quy mô lớn mà không cần dựa vào các thư viện hiện đại (STL). Dự án tập trung vào việc mô phỏng cách hệ thống vận hành ở mức thấp (Low-level), quản lý từng byte bộ nhớ và luồng dữ liệu từ tệp tin vật lý.

---

## 🛠 THÔNG SỐ KỸ THUẬT (TECHNICAL STACK)

Để đạt được điểm số tuyệt đối về mặt kỹ thuật lập trình, hệ thống được xây dựng trên nền tảng "Old-school" tinh khiết:

* **Core:** C++ Standard (ISO)
* **Data Storage:** Mảng động (Dynamic Arrays) & Con trỏ (Pointers)
* **File System:** `fstream` (Xử lý tệp tin văn bản)
* **Logic:** Modular Programming (Lập trình hàm)

> [!CAUTION]
> **Kỷ luật mã nguồn:** Tuyệt đối không sử dụng `std::vector`, `std::map` hoặc `std::sort`. Mọi thuật toán đều được viết tay (Hard-coded) để chứng minh năng lực logic.

---

## ✨ TÍNH NĂNG NỔI BẬT (KEY FEATURES)

| Icon | Tính năng | Mô tả chi tiết |
| :--- | :--- | :--- |
| 📁 | **Smart Loader** | Tự động quét và cấp phát bộ nhớ dựa trên số lượng câu hỏi thực tế từ `nganhang.txt`. |
| 🔀 | **Shuffle Engine** | Thuật toán hoán vị ngẫu nhiên toàn bộ bộ đề, đảm bảo tính minh bạch cho mỗi lượt thi. |
| ⏱️ | **Real-time Tracking** | Theo dõi chính xác thời gian làm bài của thí sinh theo từng giây. |
| ⏭️ | **Smart Navigation** | Hỗ trợ tính năng **Skip** (Bỏ qua) và **Back** (Quay lại) để sửa đáp án linh hoạt. |
| 🏆 | **Pro Leaderboard** | Hệ thống xếp hạng thông minh dựa trên: `Điểm cao nhất` > `Thời gian ngắn nhất`. |

---

## 🧬 KIẾN TRÚC DỮ LIỆU (DATA ARCHITECTURE)

Dự án được module hóa thông qua các `struct` chuyên biệt để quản lý trạng thái:

```cpp
// Quản lý bộ đề thi
struct CauHoi {
    string noiDung;
    string dsDapAn[4];
    char dapAnDung;
};

// Quản lý thực thể thí sinh
struct ThiSinh {
    string hoTen;
    char* dsTraLoi;  // Quản lý bộ nhớ động tại đây
    float tongDiem;
};