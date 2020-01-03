#include "monty.h"
#include <stdio.h>
int countCommands(char *buffer)
{
        int len = 0, i = 0;
        while (buffer[i] != '\0')
        {
                if (buffer[i] == '\n')
                {
                        len++;
                }
                i++;
        }
        return (len);
}

/**
 *  * _atoi - of string to integer
 *   * @s: convert
 *    * Return: s
 *     */
int _atoi(char *s)
{
        int a = 0, b = 0, c;
        for (c = 0; s[c] != '\0'; c++)
        {
                if (s[c] == '-')
                        b++;
                if (s[c] > 47 && s[c] < 58)
                {
                        while (s[c] > 47 && s[c] < 58)
                                a = a * 10 - (s[c++] - 48);
                        break;
                        
                }
                
        }
        return (a *= b % 2 == 0 ? -1 : 1);
}
/**
 * free_dlistint - Free list
 * @head: Head
*/
void free_dlistint(stack_t *head)
{
        while (head != NULL)
        {
                free(head);
                head = head->next;                                                                
        }
        free(head);
}
