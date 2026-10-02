#include <stdio.h>

#define MAX_SIZE 50

int main(void) {

    int stock[MAX_SIZE] = {10, 25, 30, 15, 40};
    int n = 5;
    int choice;
    int loop = 1;
    int value;
    int pos;
    int found;

    while (loop == 1) {

        printf("\n=====================================================\n");
        printf("       CHUONG TRINH QUAN LY TON KHO MINIMART\n");
        printf("=====================================================\n");
        printf("1. Them so luong ton kho\n");
        printf("2. Sua so luong ton kho\n");
        printf("3. Xoa so luong ton kho\n");
        printf("4. Tim kiem so luong ton kho\n");
        printf("0. Thoat chuong trinh\n");
        printf("=====================================================\n");

        printf("Vui long nhap vao su lua chon cua ban (0 - 4): ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\n===== THEM TON KHO =====\n");

                printf("Cac phan tu dang co trong mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", stock[i]);
                }

                printf("\n");

                if (n == MAX_SIZE) {
                    printf("Mang da day, khong the them phan tu\n");
                    break;
                }

                printf("Moi ban nhap vao gia tri ton kho can them: ");
                scanf("%d", &value);

                if (value < 0) {
                    printf("So luong ton kho khong hop le\n");
                    break;
                }

                printf("Moi ban nhap vao vi tri muon chen (1 - %d): ", n + 1);
                scanf("%d", &pos);

                if (pos < 1 || pos > n + 1) {
                    printf("Vi tri chen khong hop le\n");
                    break;
                }

                for (int i = n; i >= pos; i--) {
                    stock[i] = stock[i - 1];
                }

                stock[pos - 1] = value;
                n++;

                printf("Chen thanh cong!\n");

                printf("Mang sau khi chen:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", stock[i]);
                }

                printf("\n");
                break;

            case 2:
                printf("\n===== SUA TON KHO =====\n");

                printf("Nhap vi tri can sua (1 - %d): ", n);
                scanf("%d", &pos);

                if (pos < 1 || pos > n) {
                    printf("Vi tri sua khong hop le\n");
                    break;
                }

                printf("Gia tri hien tai: %d\n", stock[pos - 1]);

                printf("Nhap gia tri moi: ");
                scanf("%d", &value);

                if (value < 0) {
                    printf("So luong ton kho khong hop le\n");
                    break;
                }

                stock[pos - 1] = value;

                printf("Sua thanh cong!\n");

                printf("Mang sau khi sua:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", stock[i]);
                }

                printf("\n");
                break;

            case 3:
                printf("\n===== XOA TON KHO =====\n");

                printf("Nhap vi tri can xoa (1 - %d): ", n);
                scanf("%d", &pos);

                if (pos < 1 || pos > n) {
                    printf("Vi tri xoa khong hop le\n");
                    break;
                }

                for (int i = pos - 1; i < n - 1; i++) {
                    stock[i] = stock[i + 1];
                }

                n--;

                printf("Xoa thanh cong!\n");

                printf("Mang sau khi xoa:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", stock[i]);
                }

                printf("\n");
                break;

            case 4:
                printf("\n===== TIM KIEM TON KHO =====\n");

                printf("Nhap so luong ton kho can tim: ");
                scanf("%d", &value);

                found = 0;

                for (int i = 0; i < n; i++) {
                    if (stock[i] == value) {
                        printf("Tim thay %d tai vi tri %d\n", value, i + 1);
                        found = 1;
                    }
                }

                if (found == 0) {
                    printf("Khong tim thay so luong ton kho %d\n", value);
                }

                break;

            case 0:
                printf("\nThoat chuong trinh!\n");
                loop = 0;
                break;

            default:
                printf("\nLua chon khong hop le, vui long nhap lai!\n");
                break;
        }
    }

    return 0;
}