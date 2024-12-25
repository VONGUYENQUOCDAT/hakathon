#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 100

void displayArray(int array[], int size) {
    if (size == 0) {
        printf("Mang rong\n");
        return;
    }
    printf("Cac phan tu trong mang la: ");
    for (int i = 0; i < size; ++i) {
    	if(array[i] != array[size - 1]) {
        printf("arr[%d] = %d, ",i, array[i]);
	}else{   
		printf("arr[%d] = %d",i, array[i]);
	}
	}
    printf("\n");
}
	int isPrime(int n) {
	    if (n <= 1) return 0;
	    for (int i = 2; i <= sqrt(n); ++i) {
	        if (n % i == 0) return 0;
	    }
	    return 1;
	}

int main(void) {
    int arrayInt[MAX_SIZE];
    int size = 0;
    int chan = 0, le = 0;

    while (1) {
        printf("\n==============MENU================\n");
        printf("1. Nhap phan tu cho mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Dem so luong cac phan tu chan le trong mang\n");
        printf("4. Tim gia tri lon thu hai trong mang\n");
        printf("5. Them mot phan tu vao dau mang\n");
        printf("6. Xoa phan tu tai vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan\n");
        printf("8. Tim kiem phan tu\n");
        printf("9. In ra bo so nguyen to trong mang\n");
        printf("10. Sap xep theo thu tu giam dan\n");
        printf("Moi ban nhap lua chon: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n;
                printf("Hay nhap so luong phan tu: ");
                scanf("%d", &n);
                if (n <= 0 || n > MAX_SIZE) {
                    printf("So luong phan tu khong hop le! (1 - %d)\n", MAX_SIZE);
                    break;
                }
                for (int i = 0; i < n; ++i) {
                    printf("Nhap Array[%d]: ", i);
                    scanf("%d", &arrayInt[i]);
                }
                size = n;
                printf("Da nhap mang thanh cong.\n");
                break;
            }
            case 2: {
                displayArray(arrayInt, size);
                break;
			}
			case 3: {
				for(int i = 0; i<size; i++) {
					if (arrayInt[i] % 2 == 0) {
						chan++;
					}else{
						le++;
				}
			}
				printf("So phan tu chan: %d\n", chan);
    			printf("So phan tu le: %d\n", le);
				break;
			}
			case 4: {
				if (size < 2) {
       				printf("Mang khong du phan tu de tim gia tri lon thu hai.\n");
        			return 1;
   				}
    			int largest = INT_MIN, secondLargest = INT_MIN;
    			for (int i = 0; i < size; ++i) {
        			if (arrayInt[i] > largest) {
            			secondLargest = largest;
            			largest = arrayInt[i];
        			}else if (arrayInt[i] > secondLargest && arrayInt[i] < largest) {
            				secondLargest = arrayInt[i];
        				}
    				}
    				if (secondLargest == INT_MIN) {
        				printf("Khong co gia tri lon thu hai.\n");
    				} else {
        			printf("Gia tri lon thu hai la: %d\n", secondLargest);
    			}			
				break;
			}
			case 5: {
				int value, *size;
   	 			printf("Nhap gia tri can them vao dau mang: ");
    			scanf("%d", &value);
    			for (int i = *size; i > 0; --i) {
        			arrayInt[i] = arrayInt[i - 1];
    			}
    			arrayInt[0] = value;
    			(*size)++;
				break;
			}
			case 6: {
                int deleteIndex;
                printf("Hay nhap vi tri can xoa: ");
                scanf("%d", &deleteIndex);

                if (deleteIndex < 0 || deleteIndex >= size) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }

                for (int i = deleteIndex; i < size - 1; ++i) {
                    arrayInt[i] = arrayInt[i + 1];
                }
                size--;
                printf("Da xoa phan tu thanh cong.\n");
				break;
			}
			case 7: {
				for (int i = 1; i < size; ++i) {
        			int key = arrayInt[i];
        			int j = i - 1;
        			while (j >= 0 && arrayInt[j] < key) {
            			arrayInt[j + 1] = arrayInt[j];
            			j--;
        			}
        			arrayInt[j + 1] = key;
    			}
    			printf("Mang da duoc sap xep giam dan.\n");
				break;
			}
			case 8: {
				int target;
    			printf("Nhap phan tu can tim: ");
    			scanf("%d", &target);

    			int left = 0, right = size - 1;
    			while (left <= right) {
        			int mid = left + (right - left) / 2;
        			if (arrayInt[mid] == target) {
            			printf("Phan tu %d ton tai trong mang tai vi tri %d.\n", target, mid);
            			return 1;
        			} else if (arrayInt[mid] < target) {
            			left = mid + 1;
        				} else {
            				right = mid - 1;
        			}
    			}			
    			printf("Phan tu %d khong ton tai trong mang.\n", target);
				break;
			}
			case 9: {
				int found = 0;
			    printf("Cac so nguyen to sau khi binh phuong:\n");
			    for (int i = 0; i < size; ++i) {
			        if (isPrime(arrayInt[i])) {
			            found = 1;
			            printf("%d^2 = %d\n", arrayInt[i], arrayInt[i] * arrayInt[i]);
			        }
			    }
			    if (!found) {
			        printf("Khong co so nguyen to nao trong mang.\n");
			    }
				break;
			}
			case 10: {
				for (int i = 0; i < size - 1; ++i) {
        			for (int j = 0; j < size - i - 1; ++j) {
            			if (arrayInt[j] < arrayInt[j + 1]) {
                			int temp = arrayInt[j];
                			arrayInt[j] = arrayInt[j + 1];
                			arrayInt[j + 1] = temp;
            			}
        			}
    			}
    			printf("Mang da duoc sap xep giam dan.\n");
				break;
			}
			default :
				printf("Lua chon khong hop le!");
		}
	}
}
