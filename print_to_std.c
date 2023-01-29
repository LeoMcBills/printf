#include "main.h"
/**
 * writer - function to wriie a character
 * @character : character to output
 * Return: 1 on success -1 other wise
 */

int writer(char character)
{
	return (write(1, &character, 1));
}
