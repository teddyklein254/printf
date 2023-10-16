#include "main.h"

void print_array(char array[], int *array_ist);

/**
 * printf - Printf function for the array
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int a, num1 = 0, characters = 0;
	int flags, width, precision, size, array_index = 0;
	va_list list;
	char array[BUFF_SIZE];

	if (format == ((void *)0))
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[a] != '%')
		{
			array[array_index++] = format[a];
			if (array_index == BUFF_SIZE)
				print_array(array, &array_index);
			characters++;
		}
		else
		{
			print_array(array, &array_index);
			flags = get_flags(format, &a);
			width = get_width(format, &a, list);
			precision = get_precision(format, &a, list);
			size = get_size(format, &a);
			++a;
			num1 = handle_print(format, &a, list, array,
				flags, width, precision, size);
			if (num1 == -1)
				return (-1);
			characters += num1;
		}
	}

	print_array(array, &array_index);

	va_end(list);

	return (characters);
}
void print_array(array[], int *array_index)
/**
 * print_array - prints Array containing data 
 * @array: list of data in array
 * @array_index: data length
 * Return: 0
 */
{
	if (*array_index > 0)
		write(1, &array[0], *array_index);

	*array_index = 0;
}
