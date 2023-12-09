#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Kiểm tra xem một chuỗi có chứa đủ 26 chữ cái từ a đến z không
int hasAllAlphabets(const char *str);

int main(void)
{
    char inputString[100];

    // Nhập chuỗi từ người dùng
    printf("Nhập một chuỗi: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Loại bỏ ký tự xuống dòng nếu có
    size_t len = strlen(inputString);
    if (len > 0 && inputString[len - 1] == '\n') {
        inputString[len - 1] = '\0';
    }

    // Kiểm tra và hiển thị kết quả
    if (hasAllAlphabets(inputString)) {
        printf("Chuỗi chứa đủ 26 chữ cái từ a đến z.\n");
    } else {
        printf("Chuỗi không chứa đủ 26 chữ cái từ a đến z.\n");
    }

    return 0;
}

// Hàm kiểm tra xem chuỗi có chứa đủ 26 chữ cái từ a đến z không
int hasAllAlphabets(const char* str)
{
    int alphabetCount[26] = {0}; // Mảng để đếm số lần xuất hiện của mỗi chữ cái
    int totalAlphabets = 0; // Biến để đếm tổng số chữ cái xuất hiện

    // Đếm số lần xuất hiện của mỗi chữ cái
    for (size_t i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            int index = tolower(str[i]) - 'a'; // Chuyển đổi chữ cái thành số từ 0 đến 25
            if (alphabetCount[index] == 0) {
                totalAlphabets++;
            }
            alphabetCount[index]++;
        }
    }

    // Kiểm tra xem có đủ 26 chữ cái hay không
    return totalAlphabets == 26;
}
