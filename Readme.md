# Вступительные задания на летнюю практику в АО «МЦСТ»

В этом репозитории представлены решения задач вступительных задач для МЦСТ по направлению «Ядро Linux» и «РБВ».

Всего реализовано 10 задача, каждая из которых описана ниже.

## Задача 1

В этой задаче реализован алгоритм сортировки слиянием с импользованием многопоточности.

## Задача 2

В этой задаче реализован чат между двумя процессами через
именованные каналы (FIFO), используя системные вызовы.

## Задача 3



## Задача 4

В этой задаче было необходимо реализовать парсер аргументов командной строки.

Программа принимает опции ``-m -c -s -t``, а также ``--elbrus=[1c+, 2c+, 2c3, 4c, 8c, 16c]`` и любое количество строк не-опций (без символов - и -- перед ними).

## Задача 5

Данная программа выполняет системный вызов ``open`` затем выводит возвращаемую ошибку, используя значение переменной ``errno``, функцию ``perror`` и из системный массив сообщений об ошибках ``sys_errlist[]``.

## Задача 6

Данная программа выводит справочную информацию о файле с помощью системного вызова ``stat``.

## Задача 7

Было необходимо реализовать программу: 
```
Открыть файл (произвольного размера без ограничений), доступный для чтения. Имя файла передается из командной строки. После открытия файла создать параллельный процесс с помощью fork. В обоих процессах создать свои файлы для записи, читать информацию из общего файла и копировать ее в собственные выходные файлы (не на экран). Вывести на экран содержимое полученных файлов из порожденного процесса по окончании записи в файл и из родительского процесса, дождавшись завершения порожденного процесса.
```

В данной программе продемонстрированы базовые умения работы с процессами на языке Си.

## Задача 8

## Задача 9

В данной задаче реализован алгоритм поиска максимальной непрерывной подпоследовательности чисел с максимальной суммой элементов. Задача решена с помощью алгоритма Кадана.

## Задача 10

Данная программа парсит логические выражения и вычисляет их значения. Алгоритм парсера реализован с помощью рекурсивного спуска. 