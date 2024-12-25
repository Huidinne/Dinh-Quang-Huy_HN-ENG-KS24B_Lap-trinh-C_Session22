#include<stdio.h>
typedef struct{
	char bookId[50];
	char title[50];
	char author[50];
	float price;
	char catory[50];
}Book;
void addBooks(Book books[], int *n);
void saveInfor(Book books[], int *n);
void getInfor(Book books[], int *n);
void showBooks(Book books[], int *n);
int main(){
	Book books[100];
	int choose;
	int n;
	do{
		printf("\n----------MENU----------\n");
		printf("1. Nhap so luong va thong tin sach\n");
		printf("2. Luu thong tin sach vao file\n");
		printf("3. Lay thong tin sach tu file\n");
		printf("4. Hien thi thong tin sach\n");
		printf("5. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d",&choose);
		
		switch(choose){
			case 1: {
				addBooks(books,&n);
				break;
			}
			case 2: {
				saveInfor(books,&n);
				break;
			}
			case 3: {
				getInfor(books,&n);
				break;
			}
			case 4: {
				showBooks(books,&n);
				break;
			}
			case 5: {
				printf("Thoat chuong trinh");
				break;
			}
			default: {
				printf("khong hop le");
				break;
			}
		}
		
	}while(choose!=5);
	return 0;
}
void addBooks(Book books[], int *n){
	printf("nhap so luong sach: ");
	scanf("%d",&*n);
	for(int i=0; i<*n; i++){
		printf("Ma sach: ");
		fflush(stdin);
		fgets(books[i].bookId,50,stdin);
		printf("Ten sach: ");
		fflush(stdin);
		fgets(books[i].title,50,stdin);
		printf("Tac gia: ");
		fflush(stdin);
		fgets(books[i].author,50,stdin);
		printf("Gia tien: ");
		fflush(stdin);
		scanf("%f",&books[i].price);
		printf("The loai: ");
		fflush(stdin);
		fgets(books[i].catory,50,stdin);
		printf("\n");
	}
}
void saveInfor(Book books[], int *n){
	FILE *file;
	file=fopen("Book_nhi_phan.bin","wb");
	if (file == NULL) {
        printf("Khong the mo file");
        return;
    }
	for (int i = 0; i <*n; i++) {
    	fwrite(&books[i], sizeof(Book), 1, file);
		}
    fclose(file);
}
void getInfor(Book books[], int *n){
	FILE *file;
	file = fopen("Book_nhi_phan.bin", "rb");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }
    for (int i = 0; i <*n; i++) {
    	fread(&books[i], sizeof(Book), 1, file);
		}
    fclose(file);
    printf("Lay thong tin sach tu file thanh cong");
}
void showBooks(Book books[], int *n) {
    if (*n == 0) {
        printf("Danh sach sach trong");
        return;
    }
    printf("\nDanh sach cac cuon sach:\n");
    for (int i = 0; i < *n; i++) {
        printf("\nThong tin sach thu %d:\n", i + 1);
        printf("Ma sach: %s\n", books[i].bookId);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].catory);
    }
}
