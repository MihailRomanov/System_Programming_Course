# Практическая работа #1

В этой работе нам предстоит познакомиться со следующими механизмами:
- разбор аргументов командной строки
- запуск программ (процессов)
- работа с переменными окружения (среды)

## Задание
Создайте программу, которая будет запускать указанное число экземпляров другой программы

Синтаксис запуска программы следующий:
```
<your program> [-w] [-i <N>] [-a <arguments>] <run> 
```
где:
- \<your program\> - ваша программа
- \<run\> - программа которую нужно запустить
- -a \<arguments\> - аргументы, которые нужно передать запускаемой программе
- -i \<N\> - число (N) экземпляров программы, которое нужно запустить
- -w - ждать ли завершения всех запущенных экземпляров

Требования к реализации:
- должны быть созданы версии программы для **Linux** и **Windows** (если получится - можно сделать единую версию для обеих систем)
  - для запуска программ можно использовать как специфические для каждой системы API ([CreateProcess()](https://docs.microsoft.com/en-us/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessw), [fork()](https://linux.die.net/man/2/fork)/[exec()](https://linux.die.net/man/2/fork)) так и библиотеку C ([system()](https://linux.die.net/man/3/system))
  - в зависимости от выбранного способа запуска для ожидания завершения можно использовать [wait()/waitpid()](https://linux.die.net/man/2/waitpid) (аналог в Windows [_cwait()](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/cwait)) или [WaitForSingleObject](https://docs.microsoft.com/en-us/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject)/[WaitForMultipleObjects](https://docs.microsoft.com/en-us/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjects) (хэндл запущенного процесса можно получить из структуры [PPROCESS_INFORMATION](https://docs.microsoft.com/en-us/windows/desktop/api/processthreadsapi/ns-processthreadsapi-_process_information),)
- помимо короткой версии имен параметров, должны поддерживаться также и длинные имена:
  - -a == --arguments
  - -i == --instances
  - -w == --wait
- для облегчения разбора аргументов можно использовать готовые библиотеки:
  - [getopt()/getopt_long()](https://www.gnu.org/software/libc/manual/html_node/Getopt.html)
  - [Boost Program Options](https://www.boost.org/doc/libs/1_68_0/doc/html/program_options.html)
  - [gengetopt()](https://www.gnu.org/software/gengetopt/gengetopt.html)
  - ...
- программа должна также проверять наличие переменной среды **MAX_INSTANCES** и использовать её, как максимальное количество запущенных экземпляров приложения. Если параметр *-i (--instances)* превышает значение, указанное в **MAX_INSTANCES**, то запускается только столько экземпляров, сколько указано в **MAX_INSTANCES**

