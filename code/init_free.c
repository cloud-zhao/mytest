#include <string.h>   
#include <stdio.h>   
#include <malloc.h>  
  
#define BOOL int  
#define FALSE  0  
#define TRUE   1  
  
BOOL GetStrBuf(char **ppBuf, int nLen)  
{  
    (*ppBuf) = (char *)malloc(nLen * sizeof(char));  
      
    return ((NULL == (*ppBuf)) ? FALSE : TRUE);  
}  
  
void FreeStrBuf(char **ppBuf)  
{  
    if (NULL != (*ppBuf))  
    {  
        free((*ppBuf));  
        (*ppBuf) = NULL;  
    }  
}  
  
int main(void)   
{   
    char *pBuf  = NULL;  
    char *pData = "Hello, wrold !";  
    int  nLen;  
    BOOL bRet;  
  
    nLen = strlen(pData);  
      
    // get buf for pBuf  
    bRet = GetStrBuf(&pBuf, nLen+1);  
      
    // if get buffer fail  
    if (!bRet)  
    {  
        printf("malloc for string buf fail !/n");  
        return -1;  
    }  
    // clear the buffer for copy  
    memset(pBuf, 0, nLen+1);  
      
    strncpy(pBuf, pData, nLen);  
    printf("pData is: %s/n", pData);  
    printf("pBuf  is: %s/n", pBuf);  
  
    // free had malloc mem buf  
    FreeStrBuf(&pBuf);  
    // then the pBuf = NULL, 0x0  
  
    return 0;   
}  
