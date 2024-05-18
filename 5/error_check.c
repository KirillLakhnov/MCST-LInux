#include "error_check.h"

void error_check()
{
    printf("The value of the variable \"errno\": %d\n", errno);

    printf("The message corresponding to this error is from \"sys_errlist[]\": %s\n", strerror(errno));

    perror("Error information from \"perror\"");
}