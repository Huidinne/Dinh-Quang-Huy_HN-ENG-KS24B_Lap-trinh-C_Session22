#include <stdio.h>
#include <string.h>
struct sinhVien {
    int id;
    char name[100];
    int age;
};
int main() {
    FILE *fptr;
    struct sinhVien sv[100];
    int n = 0;
    fptr = fopen("students.txt", "r");
    if (fptr == NULL) {
        printf("Khong the mo file students.txt de doc.\n");
        return 1;
    }
    while (fscanf(fptr, "%d %99[^\n] %d", &sv[n].id, sv[n].name, &sv[n].age) == 3) {
        n++;
        if (n >= 100) break;
    }
    fclose(fptr);
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d\n", sv[i].id, sv[i].name, sv[i].age);
    }
    return 0;
}
