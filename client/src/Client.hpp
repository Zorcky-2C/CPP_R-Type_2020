/*
** EPITECH PROJECT, 2023
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** Created by valentinbreiz,
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_CLIENT_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_CLIENT_HPP

#include <memory>
#include "Network/TcpClient.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Font.hpp>

class Client
{
    public:
        Client();
        ~Client();
        std::shared_ptr<TcpClient> _tcpclient;
        void setColor(std::string color) { _color = color; }
        std::string getColor() { return (this->_color); }
        void setReady(bool status) { _ready = status; }
        bool getReady() { return (this->_ready); }
        void setRoomName(std::string room) { _room = room; }
        std::string getRoomName() { return (this->_room); }
        int getVolume();
        void volumeUp();
        void volumeDown();
        float getSliderPos();
        void setSliderPos(float position);
        sf::Music _music;
        sf::Font _font;
    private:
        bool _ready;
        std::string _color;
        std::string _room;
        int _volume;
        float _position;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_CLIENT_HPP
