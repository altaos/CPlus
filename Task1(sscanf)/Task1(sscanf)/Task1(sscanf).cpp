#include "stdafx.h"
#include <iostream>
#include <stdarg.h>
#include <string>
#include <tchar.h>

int my_sscanf(const _TCHAR *buffer, const _TCHAR *format, ...)
{
	int i = 0, start = 0, tmp;
	int count = 0;

	va_list p;
	va_start(p, format);

	while(format[i] != '\0')
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

					while(buffer[tmp] != '\0' && (buffer[tmp] < '0' || buffer[tmp] > '9' || buffer[tmp] == '-')) tmp++;

					if(buffer[tmp] != '\0')
					{
						*d = 0;
						if(buffer[tmp - 1] == '-') s = -1;
						while(buffer[tmp] >= '0' && buffer[tmp] <= '9')
						{
							*d = *d * 10 + (buffer[tmp] - '0');
							tmp++;
						}
						if(buffer[tmp] == ' ' || buffer[tmp] == '\n' || buffer[tmp] == '\n' || buffer[tmp] == '\0')
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
					if(buffer[tmp] != '\0')
					{
						int j = 0;
						while(buffer[tmp] != '\0' && buffer[tmp] != ' ' && buffer[tmp] != '\n' && buffer[tmp] != '\r')
						{
							str[j++] = buffer[tmp++];
						}
						str[j] = '\0';
						start = tmp;
						count++;
					}
					break;
				}
			case 'c' :
				{
					_TCHAR *ch = va_arg(p, _TCHAR *);
					if(buffer[tmp] != '\0')
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
	_TCHAR buf[30] = L"\n Something\n -123";
	_TCHAR form[10] = L"%s %d";
	_TCHAR rr[30];
	int d = 0;
	int res = my_sscanf(buf, form, rr, &d); 
	std::wcout<<"string = "<<rr<<" integer = "<<d<<" count = "<<res<<std::endl;

	_TCHAR frm[10] = L"%c %d";
	_TCHAR ch;
	d = 0;
	res = my_sscanf(buf, frm, &ch, &d);
	std::wcout<<"char = "<<ch<<" integer = "<<d<<" count = "<<res<<std::endl;

	/*int d1 = 0;
	sscanf("Something -123hg", "%d", d1);
	std::cout<<d1<<std::endl;*/

	_TCHAR fr[10] = L"%d %s";
	_TCHAR rr1[30];
	d = 0;
	res = my_sscanf(buf, fr, &d, rr1);
	std::wcout<<"integer = "<<d<<" string = "<<rr1<<" count = "<<res<<std::endl;


	std::cin.ignore();
	std::cin.ignore();
	return 0;
}

