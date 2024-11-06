#include "StaffService.h"

StaffService::StaffService()
{// Staff inputStaff() {
    // Staff s;
    // std::cout << "Nhập ID: ";
    // std::cin >> s.id;
    // std::cout << "Nhập tên: ";
    // std::cin >> s.firstName;
    // std::cout << "Nhập họ: ";
    // std::cin >> s.lastName;
    // std::cout << "Nhập giới tính (1: Nam, 0: Nữ): ";
    // std::cin >> s.gender;
    // return s;
// }

void displayStaff(const Staff &s) {
    std::cout << "ID: " << s.id.toStdString()
              << ", Họ và tên: " << s.firstName.toStdString() << " " << s.lastName.toStdString()
              << ", Giới tính: " << (s.gender ? "Nam" : "Nữ") << std::endl;
}

void createStaff(DArray<Staff> &staffList) {
    Staff s = inputStaff();
    staffList.push(s);
    std::cout << "Đã thêm nhân viên mới";
}

void readStaff(const DArray<Staff> &staffList) {
    if (staffList.isEmpty()) {
        std::cout << "Danh sách nhân viên trống";
        return;
    }
    for (size_t i = 0; i < staffList.getSize(); ++i) {
        displayStaff(staffList.at(i));
    }
}

void updateStaff(DArray<Staff> &staffList) {
    QString id;
    std::cout << "Nhập ID của nhân viên cần cập nhật: ";
    std::cin >> id;

    int index = staffList.findById(id);
    if (index == -1) {
        std::cout << "Không tìm thấy nhân viên.\n";
        return;
    }

    Staff updatedStaff = inputStaff();
    staffList.updateAt(index, updatedStaff);
    std::cout << "Đã cập nhật thông tin nhân viên.\n";
}

void deleteStaff(DArray<Staff> &staffList) {
    QString id;
    std::cout << "Nhập ID của nhân viên cần xóa: ";
    std::cin >> id;

    int index = staffList.findById(id);
    if (index == -1) {
        std::cout << "Không tìm thấy nhân viên.\n";
        return;
    }

    staffList.popAt(index);
    std::cout << "Đã xóa nhân viên.\n";
}

}

StaffService::~StaffService()
{
}
