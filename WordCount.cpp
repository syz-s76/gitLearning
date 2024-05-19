#include <stdio.h>    
#include <stdbool.h>    
#include <ctype.h> // �������һ��������isspace�����Ķ���  
  
int main() {    
    FILE *file = fopen("input.txt", "r"); // �ı��ļ���Ϊ input.txt    
    if (file == NULL) {    
        perror("Error opening file");    
        return 1;    
    }    
    
    int char_count = 0;    
    int word_count = 0;    
    bool in_word = false; // ��־λ�������ж��Ƿ��ڵ�����    
    
    int ch;    
    while ((ch = fgetc(file)) != EOF) {    
        char_count++; // ��ȡ��ÿ���ַ��������ַ���    
    
        // �ж��Ƿ�Ϊ���ʵĿ�ͷ���β    
        if (isspace(ch) || ch == ',') {    
            if (in_word) {    
                word_count++; // ����һ�����ʵĽ�β    
                in_word = false;    
            }    
        } else {    
            if (!in_word) {    
                in_word = true; // ����һ�����ʵĿ�ͷ    
            }    
        }    
    }    
    
    // �����ļ�ĩβ�ĵ��ʣ�����еĻ���    
    if (in_word) {    
        word_count++;    
    }    
    
    fclose(file);    
    
    printf("Character count: %d\n", char_count);    
    printf("Word count: %d\n", word_count);    
    
    return 0;    
}

