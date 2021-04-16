/*
** EPITECH PROJECT, 2020
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <iostream>
#include <exception>

class Exception : public std::exception
{
    public:
        Exception(const std::string &msg) noexcept
            : _msg(msg) {}
		const char *what() const noexcept override { return this->_msg.data();}

    protected:
        std::string _msg;
};

#endif /* !EXCEPTION_HPP_ */