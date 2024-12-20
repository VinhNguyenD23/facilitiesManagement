# ĐỀ TÀI MÔN CẤU TRÚC DỮ LIỆU & GIẢI THUẬT
**KHÓA 2023 - CNTT CLC**

## 4. Quản lý nhập xuất vật tư

### Tổ chức các danh sách

1. **Danh sách Vật tư**:
   - **Cấu trúc**: Cây nhị phân tìm kiếm cân bằng (BST)
   - **Thuộc tính**:
     - `MAVT` (Mã vật tư, C10)
     - `TENVT` (Tên vật tư)
     - `DVT` (Đơn vị tính)
     - `Số lượng tồn`

2. **Danh sách Nhân viên**:
   - **Cấu trúc**: Danh sách tuyến tính (mảng con trỏ)
   - **Số lượng tối đa**: 500 nhân viên
   - **Thuộc tính**:
     - `MANV` (Mã nhân viên)
     - `HO` (Họ)
     - `TEN` (Tên)
     - `PHAI` (Phái)
     - `con trỏ dshd`: Trỏ đến danh sách các hóa đơn mà nhân viên đó đã lập

3. **Danh sách Hóa đơn**:
   - **Cấu trúc**: Danh sách liên kết đơn
   - **Thuộc tính**:
     - `SoHD` (Số hóa đơn, C20)
     - `Ngày lập hóa đơn`
     - `Loại` (chỉ nhận 'N' - Phiếu nhập hoặc 'X' - Phiếu xuất)
     - `con trỏ dscthd`: Trỏ đến danh sách chi tiết các vật tư của hóa đơn đó

4. **Danh sách Chi tiết Hóa đơn (CT_HOADON)**:
   - **Cấu trúc**: Danh sách liên kết đơn
   - **Thuộc tính**:
     - `MAVT` (Mã vật tư)
     - `Soluong` (Số lượng)
     - `Dongia` (Đơn giá)
     - `%VAT` (Phần trăm VAT)

---

## Các chức năng của chương trình

### a) **Nhập vật tư**
- Cập nhật thông tin của vật tư (Thêm / Xóa / Hiệu chỉnh).
- **Lưu ý**:
  - `Số lượng tồn` chỉ được nhập khi thêm vật tư mới.

### b) **In danh sách vật tư tồn kho**
- In danh sách vật tư ra màn hình theo thứ tự **Tên vật tư tăng dần**.
- **Kết xuất**:
  ```
  Mã VT     Tên vật tư     Đơn vị tính     Số lượng tồn
  ```

### c) **Nhập nhân viên**
- Cập nhật thông tin nhân viên (Mã NV, Họ, Tên, Phái).
- **Điều kiện**:
  - Không cho phép thông tin bị rỗng.
  - Danh sách nhân viên luôn sắp xếp **tăng dần theo Tên**, nếu trùng Tên thì **tăng dần theo Họ**.

### d) **In danh sách nhân viên**
- In danh sách nhân viên ra màn hình theo thứ tự **Tên tăng dần**, nếu trùng Tên thì **tăng dần theo Họ**.
- **Hiển thị**: Mỗi nhân viên 1 dòng.

### e) **Lập hóa đơn nhập / Lập hóa đơn xuất**
- **Nhập thông tin hóa đơn**:
  - Số hóa đơn (`SoHD`)
  - Ngày lập
  - Loại hóa đơn (`N` - Nhập, `X` - Xuất)

- **Nhập chi tiết vật tư của hóa đơn**.
- **Cập nhật số lượng tồn**:
  - Dựa trên loại hóa đơn (`N` hoặc `X`).

- **Lưu ý**:
  - Nếu số lượng xuất không đủ, chương trình sẽ:
    - Báo lỗi.
    - In ra số lượng tồn hiện có trong kho.
  - Chỉ được phép xóa vật tư **đang lập** của hóa đơn hiện tại.
  - Khi hóa đơn đã ghi, **không được xóa vật tư** trong hóa đơn.

### f) **In hóa đơn**
- In hóa đơn dựa trên **Số hóa đơn** (`SoHD`) mà người dùng nhập vào.
- **Thông tin hiển thị**:
  ```
  Ngày, Họ tên, Loại, Tên vật tư, Số lượng, Đơn giá, Trị giá
  Tổng trị giá hóa đơn: <giá trị>
  ```

### g) **Thống kê hóa đơn trong khoảng thời gian**
- **Nhập khoảng thời gian**:
  - Từ ngày (dd/mm/yyyy)
  - Đến ngày (dd/mm/yyyy)

- **Hiển thị kết quả**:
  ```
  BẢNG LIỆT KÊ CÁC HÓA ĐƠN TRONG KHOẢNG THỜI GIAN
  Từ ngày: ##/##/####   Đến ngày: ##/##/####
  
  Số HĐ     Ngày lập     Loại HĐ     Họ tên NV lập     Trị giá hóa đơn
  ```

### h) **In 10 vật tư có doanh thu cao nhất**
- **Nhập khoảng thời gian**:
  - Từ ngày (dd/mm/yyyy)
  - Đến ngày (dd/mm/yyyy)

- **Hiển thị**: 10 vật tư có doanh thu cao nhất trong khoảng thời gian đã chọn.

### i) **Thống kê doanh thu cửa hàng theo tháng**
- **Nhập năm** cần thống kê.
- **Hiển thị kết quả**:
  ```
  BẢNG THỐNG KÊ DOANH THU NĂM ####
  
  THÁNG      DOANH THU
  ```

## Lưu ý chung
- Chương trình cho phép lưu các danh sách vào **file** để sử dụng cho lần tiếp theo.
- **Kiểm tra và xử lý lỗi**:
  - Kiểm tra các điều kiện ràng buộc khi nhập để tránh nhập sai dữ liệu.
