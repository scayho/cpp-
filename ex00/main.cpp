/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:58:28 by abelahce          #+#    #+#             */
/*   Updated: 2023/02/25 00:21:50 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (0);
    std::string data(av[1]);
    if (data == "-inff" || data == "+inff" || data == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << data << std::endl;
        std::cout << "float: " << data.substr(0,data.length() - 1) << std::endl;
    }
    if ( data == "-inf" || data == "+inf" || data == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << data << "f" << std::endl;
        std::cout << "float: " << data<< std::endl;
    }
    try
    {
        ScalarConverter::parsing(data);
        ScalarConverter::convert(data);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}