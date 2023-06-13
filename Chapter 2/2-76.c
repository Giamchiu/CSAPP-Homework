#include <stdio.h>

void* another_calloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0)
        return NULL;
    
    size_t check = nmemb * size;
    if (check / nmemb == size) {
        void* ptr = malloc(check);
        if (ptr != NULL) {
            memset(ptr, 0, check);
        }
        return ptr;
    }
    
    return NULL;
}

int main() {
    void* ptr;
    ptr = another_calloc(100, 200);
    printf("%d\n", ptr == NULL);
    free(ptr);
  
    ptr = another_calloc(0xffffffff, 100);
    printf("%d\n", ptr == NULL);
  
    system("pause");
    return 0;
}
