/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:51:30 by naadam            #+#    #+#             */
/*   Updated: 2024/06/20 14:36:03 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class   Contact
{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    
    public:
        Contact();
        ~Contact();
        //getter functions
        std::string get_firstname()const;
        std::string get_lastname()const;
        std::string get_nickname()const;
        std::string get_phone_number()const;
        std::string get_darkest_secret()const;

        //setter functions
        void    set_firstname(std::string firstname);
        void    set_lastname(std::string lastname);
        void    set_nickname(std::string nickname);
        void    set_phone_number(std::string phone_number);
        void    set_darkest_secret(std::string darkest_secret);
};