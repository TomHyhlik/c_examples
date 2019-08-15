/* strtof example */
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* strtof */
#include <string.h>
#include <stdbool.h>
#include <stdint.h>


bool json_getVal(char* buffer_out, const char* buffer_in, const char* name);
const char jsonSplitFactors[] = ",{}";

const char ident_temp[] = "temperature";
const char ident_press[] = "pressure";


////////////////////////////////////////////////////////////////////
int main ()
{
    /* sample data */
    char data[] = "{\"temperature\": 27.74,\"pressure\": 1000.51}";


    printf("data: %s\n", data);

    if (json_getVal(temp_str, data, ident_temp)) {
        float temperature = strtof(temp_str, NULL);
        printf("Float temp: %.2f\n", temperature);
    }

    if (json_getVal(press_str, data, ident_press)) {
        float pressure = strtof(press_str, NULL);
        printf("Float temp: %.2f\n", pressure);
    }

    return 0;
}
////////////////////////////////////////////////////////////////////
/*
 * @brief search in the @param buffer_in for the @param name and the
 *  found value string put in the buffer_out and return true if found
 * @note all the strings must have the ending character '\0'
 */
bool json_getVal(char* buffer_out, const char* buffer_in, const char* name)
{
    char *msgStart, *pch;

    char* data_in = malloc(strlen(buffer_in)+1);
    if (data_in != NULL) {

        memcpy(data_in, buffer_in, strlen(buffer_in));
        msgStart = strstr (data_in, name);
        if (msgStart != NULL) {
            msgStart += strlen(name) + 2;
            pch = strtok(msgStart, jsonSplitFactors);

            strcpy(buffer_out, pch);
            free(data_in);
            return true;
        } 
    }
    free(data_in);
    return false;
}

