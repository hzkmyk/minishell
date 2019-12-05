/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:28:20 by hmiyake           #+#    #+#             */
/*   Updated: 2018/05/05 18:28:35 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_do_op(int num1, char op, int num2)
{
	if (op == '+')
		return (num1 + num2);
	else if (op == '-')
		return (num1 - num2);
	else if (op == '*')
		return (num1 * num2);
	else if (op == '/')
	{
		if (num2 == 0)
			return (0);
		else
			return (num1 / num2);
	}
	else if (op == '%')
	{
		if (num2 == 0)
			return (0);
		else
			return (num1 % num2);
	}
	else
		return (0);
}
