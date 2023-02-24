/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:36:46 by abelahce          #+#    #+#             */
/*   Updated: 2023/02/25 00:26:42 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    ScalarConverter::parsing(std::string& data)
{
    if (data.length() == 1)
        return ;
    else if (data.length() > 1)
    {
        size_t signe = 0;
        int point = 0;
        if (data[0] == '+' || data[0] == '-')
            signe++;
        for (size_t i = signe; i < data.length() - 1; i++)
        {
            if (data[i] == '.' || std::isdigit(data[i]))
            {
                if (data[i] == '.')
                    point++;
                if (point > 1)
                    throw False_Arg();
                continue ;
            }
            else
                throw False_Arg();
        }
        if ((std::isdigit(data[data.length() - 2]) && data[data.length() - 1] == 'f' && data.find('.') != std::string::npos ) || std::isdigit(data[data.length() - 1]))
            return ;
        else
            throw False_Arg();
    }
    else
        throw False_Arg();
}

void    ScalarConverter::convert(std::string& data)
{
    if (data.length() == 1)
    {
        int data_number = data[0];
        std::cout << data_number << std::endl;
    }
    else
    {
        float data_float;
        double data_double;
        int data_number;
        if (data.find('.') == std::string::npos)
        {
            data_number = std::stoi(data);
            std::cout << data_number << std::endl;
            // convertion procidure
        }
        else if (data.find('.') != std::string::npos && data.find('f') == std::string::npos)
        {
            data_double = stod(data);
            std::cout << std::fixed << std::setprecision(1) <<  data_double << std::endl;
        }
        else if (data.find('.') != std::string::npos && data.find('f') != std::string::npos)
        {
            data_float = std::stof(data);
            std::cout << std::setprecision(1500) <<  data_float << std::endl;
        }
    }
}
