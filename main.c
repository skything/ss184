#include<stdio.h>
#include<stdlib.h>

void* SaferMalloc(size_t size);
void SaferFree(void** ptr);
#define SafeMalloc(size) SaferMalloc((size_t)size)
#define SafeFree(ptr) SaferFree((void ** )&ptr)
#ifdef _WIN32
unsigned char* W2C(wchar_t lz[2]);
#else
unsigned char* W2C(wchar_t lz[2]);
#endif

int main(int argc, char* argv[])
{
    wchar_t lz[] = {0x1234,0x5678};

    unsigned char* buf = SafeMalloc(3);
    buf = W2C(lz);

    printf("%d\n", buf[0]);

    SafeFree(buf);

    printf("All done.\n");
    return 0;
}

#ifdef _WIN32
unsigned char* W2C(wchar_t lz[2])
{
    static unsigned char buf[3] = { 0 };

    buf[0] = lz[0] >> 8;
    buf[1] = lz[0] >> 0;
    buf[2] = '\0';

    return buf;
}
#else
unsigned char* W2C(wchar_t lz[2])
[
    static unsigned char buf[3] = { 0 };

    buf[0] = lz[0] & 0xff;
    buf[1] = lz[1] & 0xff;
    buf[2] = '\0';

    return buf;
]
#endif
void* SaferMalloc(size_t size)
{
    void** ptr = NULL;

    ptr = (void**)malloc(16);

    if (ptr == NULL)
        return NULL;

    *ptr = malloc(size);

    if (*ptr == NULL)
        return NULL;
    return *ptr;
}

void SaferFree(void** ptr)
{
    if (ptr == NULL || *ptr == NULL)
        return;

    free(*ptr);
    *ptr = NULL;
}
