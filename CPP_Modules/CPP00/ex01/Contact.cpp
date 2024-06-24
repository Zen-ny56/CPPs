/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:51:37 by naadam            #+#    #+#             */
/*   Updated: 2024/06/20 14:39:29 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact(){ };

Contact::~Contact(){};

std::string Contact::get_firstname() const{return (firstname);}
std::string Contact::get_lastname() const{return (lastname);}
std::string Contact::get_nickname() const{return (nickname);}
std::string Contact::get_phone_number() const{return (phone_number);}
std::string Contact::get_darkest_secret() const{return (darkest_secret);}

void    Contact::set_firstname(std::string firstname){this->firstname = firstname;}
void    Contact::set_lastname(std::string lastname){this->lastname = lastname;}
void    Contact::set_nickname(std::string nickname){this->nickname = nickname;}
void    Contact::set_phone_number(std::string phone_number){this->phone_number = phone_number;}
void    Contact::set_darkest_secret(std::string darkest_secret){this->darkest_secret = darkest_secret;}



