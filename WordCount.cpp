#include <stdio.h>    
#include <stdbool.h>    
#include <ctype.h> // 添加了这一行来包含isspace函数的定义  
  
int main() {    
    FILE *file = fopen("input.txt", "r"); // 文本文件名为 input.txt    
    if (file == NULL) {    
        perror("Error opening file");    
        return 1;    
    }    
    
    int char_count = 0;    
    int word_count = 0;    
    bool in_word = false; // 标志位，用于判断是否在单词中    
    
    int ch;    
    while ((ch = fgetc(file)) != EOF) {    
        char_count++; // 读取的每个字符都计入字符数    
    
        // 判断是否为单词的开头或结尾    
        if (isspace(ch) || ch == ',') {    
            if (in_word) {    
                word_count++; // 遇到一个单词的结尾    
                in_word = false;    
            }    
        } else {    
            if (!in_word) {    
                in_word = true; // 遇到一个单词的开头    
            }    
        }    
    }    
    
    // 处理文件末尾的单词（如果有的话）    
    if (in_word) {    
        word_count++;    
    }    
    
    fclose(file);    
    
    printf("Character count: %d\n", char_count);    
    printf("Word count: %d\n", word_count);    
    
    return 0;    
}

