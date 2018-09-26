# ������������ ������ #1

� ���� ������ ��� ��������� ������������� �� ���������� �����������:
- ������ ���������� ��������� ������
- ������ �������� (���������)
- ������ � ����������� ��������� (�����)

## �������
�������� ���������, ������� ����� ��������� ��������� ����� ����������� ������ ���������

��������� ������� ��������� ���������:
```
<your program> [-w] [-i <N>] [-a <arguments>] <run> 
```
���:
- \<your program\> - ���� ���������
- \<run\> - ��������� ������� ����� ���������
- -a \<arguments\> - ���������, ������� ����� �������� ����������� ���������
- -i \<N\> - ����� (N) ����������� ���������, ������� ����� ���������
- -w - ����� �� ���������� ���� ���������� �����������

���������� � ����������:
- ������ ���� ������� ������ ��������� ��� **Linux** � **Windows** (���� ��������� - ����� ������� ������ ������ ��� ����� ������)
  - ��� ������� �������� ����� ������������ ��� ������������� ��� ������ ������� API ([CreateProcess()](https://docs.microsoft.com/en-us/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessw), [fork()](https://linux.die.net/man/2/fork)/[exec()](https://linux.die.net/man/2/fork)) ��� � ���������� C ([system()](https://linux.die.net/man/3/system))
  - � ����������� �� ���������� ������� ������� ��� �������� ���������� ����� ������������ [wait()/waitpid()](https://linux.die.net/man/2/waitpid) (������ � Windows [_cwait()](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/cwait)) ��� [WaitForSingleObject](https://docs.microsoft.com/en-us/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject)/[WaitForMultipleObjects](https://docs.microsoft.com/en-us/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjects) (����� ����������� �������� ����� �������� �� ��������� [PPROCESS_INFORMATION](https://docs.microsoft.com/en-us/windows/desktop/api/processthreadsapi/ns-processthreadsapi-_process_information),)
- ������ �������� ������ ���� ����������, ������ �������������� ����� � ������� �����:
  - -a == --arguments
  - -i == --instances
  - -w == --wait
- ��� ���������� ������� ���������� ����� ������������ ������� ����������:
  - [getopt()/getopt_long()](https://www.gnu.org/software/libc/manual/html_node/Getopt.html)
  - [Boost Program Options](https://www.boost.org/doc/libs/1_68_0/doc/html/program_options.html)
  - [gengetopt()](https://www.gnu.org/software/gengetopt/gengetopt.html)
  - ...
- ��������� ������ ����� ��������� ������� ���������� ����� **MAX_INSTANCES** � ������������ �, ��� ������������ ���������� ���������� ����������� ����������. ���� �������� *-i (--instances)* ��������� ��������, ��������� � **MAX_INSTANCES**, �� ����������� ������ ������� �����������, ������� ������� � **MAX_INSTANCES**

