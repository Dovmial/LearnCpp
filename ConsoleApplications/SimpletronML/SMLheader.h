#pragma once
//input\output
const int READ = 10;
const int WRITE = 11;
//load\store
const int LOAD = 20;
const int STORE = 21;
//Ariphmetics
const int ADD = 30;
const int SUBSTRUCT = 31;
const int DIVINE = 32;
const int MULTIPLY = 33;
//manegment
const int BRANCH = 40; //������� � ���������� ������
const int BRANCHNEG = 41;
const int BRANCHZERO = 42;
const int HALT = 43; // ����������


/*
�������� ���� (����������� ������ ������������
��������)��� ����� 10 ������������� �����, 
���������� ����� ���� ����� � �� ������.
1011
2011
1012
3012
4107 (��� ���������� ������ -9999)
2113
4002
1113
4300
*/

/*
��������� ����������� ��������� ����, �������
���� �����, ������������� � �������������,
� ����� ��������� � �������� �� ������� ��������.

0007 ����������
0001 �������
0001 ���
0000 �����
0000 �����
2004 �������� �����
1003 ���� �����
3003 1+2
2104 ������ �����
2001 �������� ��������
3002 ���������� ��������
2101 �������� ��������
2000 
3101 
4116
4005
2004
3200
2104
1104
4300
*/


/*
������� ��� �����, ���������� ������� ����� ���
� �������� ��������� ��������. � ������ ��������
����� ����������� ���������� �����, �������
������ ���� ����������.

0000 ���������� �����
0001 ���
0001 �������
0000 ������� �����
0000 �������� �����
1000 ���� ����������
2003 
1004
3104
4111
4013
2004
2103
2002
3001
2102
2000
3102
4120
4006
1103
4300
*/