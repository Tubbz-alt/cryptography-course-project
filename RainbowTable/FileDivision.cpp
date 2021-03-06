#include "Rainbow_Table_head.hpp"

bool openRainbowTableFile(char *filename, Tree_Node_ptr &T){
    // 先打开彩虹表文件
    FILE *fo = fopen(filename, "r");
    if (fo == NULL) {
        printf("file can not open!\n");
        return false;
    }
    printf("file is loading.....\n");
    while (true){
        bool taller = 0;
        unsigned char * head= (unsigned char*)malloc(sizeof(unsigned char) * stringlength);
        unsigned char * tail= (unsigned char*)malloc(sizeof(unsigned char) * stringlength);
        // 当读到文件尾时，跳出循环
        if (fgets((char *)head, stringlength+1, fo) == NULL)
            break;
        getc(fo);
        fgets((char *)tail, stringlength+1, fo);
        getc(fo);
        Tree_insert_AVL(T, head, tail, taller);
    }
    printf("file extract succeed！");
    return true;
}
