#include <iostream>
using namespace std;

void menu()
{
    cout << "\n\t\t==========MENU==========";
    cout << "\n\t\t1. QUAN LY VAT TU";
    cout << "\n\t\t2. QUAN LY NHAN VIEN";
    cout << "\n\t\t3. QUAN LY HOA DON";
    cout << "\n\t\t0. EXIT";
    cout << "\n\t\t=======================\n";

    int choice;
    do
    {
        cout << "NHAP LUA CHON: ";
        cin >> choice;
        switch (choice)
        {

        case 1:
            cout << "\n\t\t==========QUAN LY VAT TU==========";
            cout << "\n\t\t1. THEM VAT TU";
            cout << "\n\t\t2. CHINH SUA VAT TU";
            cout << "\n\t\t3. XOA VAT TU";
            cout << "\n\t\t4. TIM KIEM VAT TU";
            cout << "\n\t\t5. IN DANH SACH VAT TU";
            cout << "\n\t\t0. EXIT";
            cout << "\n\t\t=======================\n";

            int choiceVT;
            do
            {
                cout << "NHAP LUA CHON: ";
                cin >> choiceVT;
                switch (choiceVT)
                {
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:

                    break;

                default:
                    cout << "LUA CHON KHONG HOP LE!!! VUI LONG CHON LAI";
                    break;
                }
            } while (choiceVT != 0);
            break;

        case 2:
            cout << "\n\t\t==========QUAN LY NHAN VIEN==========";
            cout << "\n\t\t1. THEM NHAN VIEN";
            cout << "\n\t\t2. CHINH SUA NHAN VIEN";
            cout << "\n\t\t3. XOA NHAN VIEN";
            cout << "\n\t\t4. TIM KIEM NHAN VIEN";
            cout << "\n\t\t5. IN DANH SACH NHAN VIEN";
            cout << "\n\t\t0. EXIT";
            cout << "\n\t\t=======================\n";

            int choiceNV;
            do
            {
                cout << "NHAP LUA CHON: ";
                cin >> choiceNV;
                switch (choiceNV)
                {
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:

                    break;

                default:
                    cout << "LUA CHON KHONG HOP LE!!! VUI LONG CHON LAI";
                    break;
                }
            } while (choiceNV != 0);
            break;

        case 3:
            cout << "\n\t\t==========QUAN LY HOA DON==========";
            cout << "\n\t\t1. THEM HOA DON";
            cout << "\n\t\t2. CHINH SUA HOA DON";
            cout << "\n\t\t3. XOA HOA DON";
            cout << "\n\t\t4. TIM KIEM HOA DON";
            cout << "\n\t\t5. IN DANH SACH HOA DON";
            cout << "\n\t\t6. XEM CHI TIET HOA DON";
            cout << "\n\t\t0. EXIT";
            cout << "\n\t\t=======================\n";

            int choiceHD;
            do
            {
                cout << "NHAP LUA CHON: ";
                cin >> choiceHD;
                switch (choiceHD)
                {
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:

                    break;

                default:
                    cout << "LUA CHON KHONG HOP LE!!! VUI LONG CHON LAI";
                    break;
                }
            } while (choiceHD != 0);
            break;

        default:
            cout << "LUA CHON KHONG HOP LE!!! VUI LONG CHON LAI";
            break;
        }
    } while (choice != 0);
}