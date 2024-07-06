/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:52:42 by naadam            #+#    #+#             */
/*   Updated: 2024/06/22 15:53:03 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>

class   Phonebook
{
    private: 
        Contact contacts[8];
        int     ccount;
    public:
        //Constructor and Deconstructor
        Phonebook();
        ~Phonebook();
        //Contact count
        //Methods
        void    welcome();
        int    add_contact(int *index);
        int    add_details(std::string uinput, int *index, int *d_index);
        int    verification(std::string uinput);
        void   display(int *index, int overflow);
        int    search_contact(int *overflow);
        bool   is_digit(const std::string& str);
        int    ver(std::string uinput);
        void   increment_ccount(int ccount);
        int    get_ccount();
};