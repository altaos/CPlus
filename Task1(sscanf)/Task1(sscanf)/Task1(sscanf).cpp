#include "stdafx.h"
#include <iostream>
#include <stdarg.h>
#include <string>
#include <tchar.h>

using namespace std;

#define _UNICODE

#ifdef _UNICODE
#define tcout wcout
#else 
#define tcout cout
#endif

int my_sscanf(const _TCHAR *buffer, const _TCHAR *format, ...)
{
	int i = 0, start = 0, tmp;
	int count = 0;

	va_list p;
	va_start(p, format);

	while(format[i] != _TCHAR('\0'))
	{
		if(format[i++] == '%')
		{
			while(buffer[start] == ' ' ||  buffer[start] == '\n' || buffer[start] == '\r') start++;
			tmp = start;

			switch(format[i])
			{
			case 'd': 
				{
					int *d = va_arg(p, int *);
					int t = *d;
					int s = 1;

					while(buffer[tmp] != _TCHAR('\0') && (buffer[tmp] < _TCHAR('0') || buffer[tmp] > _TCHAR('9') || buffer[tmp] == _TCHAR('-'))) tmp++;

					if(buffer[tmp] != _TCHAR('\0'))
					{
						*d = 0;
						if(buffer[tmp - 1] == _TCHAR('-')) s = -1;
						while(buffer[tmp] >= _TCHAR('0') && buffer[tmp] <= _TCHAR('9'))
						{
							*d = *d * 10 + (buffer[tmp] - _TCHAR('0'));
							tmp++;
						}
						if(buffer[tmp] == _TCHAR(' ') || buffer[tmp] == _TCHAR('\n') || buffer[tmp] == _TCHAR('\n') || buffer[tmp] == _TCHAR('\0'))
						{
							*d *= s;
							start = tmp;
							count++;
						}
						else
						{
							*d = t;
						}
					}
					break;
				}
			case 's' :
				{
					_TCHAR *str = va_arg(p, _TCHAR *);
					if(buffer[tmp] != _TCHAR('\0'))
					{
						int j = 0;
						while(buffer[tmp] != _TCHAR('\0') && buffer[tmp] != ' ' && buffer[tmp] != _TCHAR('\n') && buffer[tmp] != _TCHAR('\r'))
						{
							str[j++] = buffer[tmp++];
						}
						str[j] = _TCHAR('\0');
						start = tmp;
						count++;
					}
					break;
				}
			case 'c' :
				{
					_TCHAR *ch = va_arg(p, _TCHAR *);
					if(buffer[tmp] != _TCHAR('\0'))
					{
						*ch = buffer[tmp++];
						start = tmp;
						count++;
					}
					break;
				}
			default :
				return -1;
			}
		}
	}

	va_end(p);

	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	_TCHAR buf[3000] = _T("\n Something\n -123 3 4");
	_TCHAR form[1000] = _T("%s %d %d %d");
	_TCHAR rr[30];
	int d = 0;
	int res = my_sscanf(buf, form, rr, &d, &d, &d); 
	tcout<<_T("string = ")<<rr<<_T(" integer = ")<<d<<_T(" count = ")<<res<<std::endl;

	_TCHAR frm[10] = _T("%c %d %c");
	_TCHAR ch;
	_TCHAR ch2;
	d = 0;
	res = my_sscanf(_T("f 45345 z"), frm, &ch, &d, &ch2);
	tcout<<_T("char = ")<<ch<<_T(" integer = ")<<d<<_T("Char2: ")<<ch2<<_T(" count = ")<<res<<std::endl;

	std::cin.ignore();
	std::cin.ignore();
	return 0;
}

