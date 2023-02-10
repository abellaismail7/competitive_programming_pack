/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ay.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:01:48 by iait-bel          #+#    #+#             */
/*   Updated: 2022/09/27 19:05:57 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <cmath>
#define float double

float findX(float a, float b, float c, float small, float heigh)
{
    float x;
    x = (small + heigh) / 2;
    if (((a * x) + (b * sin(x))) == c)
        return (x);
    if (((a * x) + (b * sin(x))) > c)
    {
        std::cout << "bigger" << x << " small " << small << " heigh " << heigh << '\n';
        return findX(a, b, c, small, x);

    }
    else if (((a * x) + (b * sin(x))) < c)
    {
        std::cout << "smaller" << x << " small " << small << " heigh " << heigh << '\n';
        return findX(a, b, c, x, heigh);
    }
    return (0);
}

float findX_while(float a, float b, float c, float small, float heigh)
{
    float x;
    // x = (small + heigh) / 2;
    while (1)
    {
        x = (small + heigh)/2.0;
		if (std::abs((a * x) + (b * sin(x)) - c) <=  1e-6)
			break;
		else if (((a * x) + (b * sin(x))) > c)
            heigh = x;
        if (((a * x) + (b * sin(x))) < c)
            small = x;
    }
    return (x);
}

int main()
{
    int t;
    float a, b, c;

    std::cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        std::cin >> a >> b >> c;
        printf("%.6f\n", findX_while(a, b, c, 0, c));
    }
    
}

