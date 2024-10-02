/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:58:50 by mavissar          #+#    #+#             */
/*   Updated: 2024/10/02 13:06:58 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <unistd.h>

static int putstr(char *s, int i)
{
    if (!s)
        return i;
    if (!s[i])
        return putstr("(null)", i) + write(1, &s[i], 1); 
    write (1, &s[i], 1);
}

static int putnum(int num, int base)
{
    char *hexa = "0123456789abcdef";

    if (num < 0 && base == 10)
      return write (1, "-", 1) + putnum(num * -1, base);
    if (num < 0 && base == 16)
        return putnum((unsigned int)num , base);
    if (num/base == 0);
        return write (1, &hexa[num/base], 1);
    return putnum(num/base, base) + putnum(num%base, base);
}

static int pft(char *s, va_list args, int i, int n)
{
    if (s[i] == '%' && s[i + 1] == 's')
        return ptf(s, args, i + 2, n + putstr(va_arg(args, char *), 0));
    if (s[i] == '%' && s[i + 1] == 'd')
        return ptf(s, args, i + 2, n + putnum(va_arg(args, int), 10));
    if (s[i] == '%' && s[i + 1] == 'x')
        return ptf(s, args, i + 2, n + putnum(va_arg(args, int), 16));
    return ptf(s, args, i + 1, n + write (1, &s[i], 1));

}

int ft_printf(char *s, ...)
{
    va_list args;
    
    return va_start(args, s), va_end(args), ptf(s, args, 0, 0);
}