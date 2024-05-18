#include "error_check.h"

void error_check()
{
    printf("Значение переменной \"errno\": %d\n", errno);

    printf("Сообщение, соответствующее этой ошибке, из \"sys_errlist[]\": %s\n", strerror(errno));

    perror("Информация об ошибке из \"perror\"");
}