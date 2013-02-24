// Task1(sscanf).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdarg.h>

int my_sscanf(char *buffer, char *format, ...)
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
					//ищем первый символ цифры в строке
					while((buffer[tmp] < '0' || buffer[tmp] > '9') && buffer[tmp] != '\0') tmp++;

					if(buffer[tmp] != '\0')
					{
						*d = 0;
						while(buffer[tmp] >= '0' && buffer[tmp] <= '9')
						{
							*d = *d * 10 + (buffer[tmp] - '0');
							tmp++;
						}
						start = tmp;
						count++;
					}
					break;
				}
			case 's' :
				{
					char *str = va_arg(p, char *);
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
					char *ch = va_arg(p, char *);
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
	char buf[30] = "\n Something\n 123";
	char form[10] = "%s %d";
	char rr[30];
	int d = 0;
	int res = my_sscanf(buf, form, rr, &d);
	printf("string = %s  integer = %d count = %d\n", rr, d, res);

	char fr[10] = "%d %s";
	char rr1[30];
	d = 0;
	res = my_sscanf(buf, fr, &d, rr1);
	printf("string = %s  integer = %d count = %d\n", rr1, d, res);

	char frm[10] = "%c %d";
	char ch;
	d = 0;
	res = my_sscanf(buf, frm, &ch, &d);
	printf("char  = %c  integer = %d count = %d\n", ch, d, res);
	std::cin.ignore();
	std::cin.ignore();
	return 0;
}

