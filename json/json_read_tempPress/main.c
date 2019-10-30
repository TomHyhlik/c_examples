/* strtof example */
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* strtof */
#include <string.h>
#include <stdbool.h>
#include <stdint.h>


bool json_getFloat(float* f, const char* searchedVarName,const char* buffer, size_t buffer_len);
const char jsonSplitFactors[] = ",{}";

const char* ident_temp = "temperature";
const char* ident_press = "pressure";


////////////////////////////////////////////////////////////////////
int main (void)
{
    /* sample data */
    char processingData[] = "{\"temperature\": 27.74,\"pressure\": 1000.51}";
    printf("Processing data: %s\n", processingData);

    float temp, press;

    if (json_getFloat(&temp, ident_temp, processingData, strlen(processingData))) {
        printf("Temp: %.2f\n", temp);
    } else {
        printf("ERROR:1\n");
    }
    if (json_getFloat(&press, ident_press, processingData, strlen(processingData))) {
        printf("Press: %.2f\n", press);
    } else {
        printf("ERROR:2\n");
    }
    
    return 0;
}

////////////////////////////////////////////////////////////////////
bool json_getFloat(float* f, const char* searchedVarName,const char* buffer, size_t buffer_len)
{
    char *msgStart, *pch;
    char data[20];
    char buff[buffer_len];
    memcpy(buff, buffer, buffer_len);

    msgStart = strstr (buff, searchedVarName);
    if (msgStart != NULL) {
        msgStart += strlen(searchedVarName) + 2;
        pch = strtok(msgStart, jsonSplitFactors);
        *f = strtof(pch, NULL);
        return true;
    } 
    return false;
}
////////////////////////////////////////////////////////////////////
