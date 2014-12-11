#include <iostream>
#include <string>
#include "tinyxml2.h"
#include <stdio.h>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace tinyxml2;


float getTemperatura_Value(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* elemento = doc.FirstChildElement("current");
    XMLElement* temp = elemento->FirstChildElement("temperature");

    float temp_value = atof(temp->Attribute("value"));
    return temp_value;
}

float getTemperatura_Min(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* elemento = doc.FirstChildElement("current");
    XMLElement* temp = elemento->FirstChildElement("temperature");

    float temp_minim = atof(temp->Attribute("min"));
    return temp_minim;
}

float getTemperatura_Max(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* elemento = doc.FirstChildElement("current");
    XMLElement* temp = elemento->FirstChildElement("temperature");


    return atof(temp->Attribute("max"));
}

string getCloudsName(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* elemento = doc.FirstChildElement("current");
    XMLElement* temp = elemento->FirstChildElement("clouds");

    return temp->Attribute("name");
}

string getArchivo(string ciudad)
{
    char completo[250];
    strcpy(completo,"bin\\wget.exe -N \"http://api.openweathermap.org/data/2.5/weather?q=");
    strcat(completo, ciudad.c_str());
    strcat(completo, "&mode=xml");

    system(completo);
    return completo;
}

string Nombre(string ciudad)
{
    char completo[200];
    strcpy(completo,"weather@q=");
    strcat(completo,ciudad.c_str());
    strcat(completo,"&mode=xml");

    return completo;
}

    string Convert1(float numero)
    {
        stringstream temp;
        temp<<"Temperature: "<<numero<<" K";
        return temp.str();
    }

    string Convert2(float numero)
    {
        stringstream temp;
        temp<<"Max: "<<numero<<" K";
        return temp.str();
    }

    string Convert3(float numero)
    {
        stringstream temp;
        temp<<"Min: "<<numero<<" K";
        return temp.str();
    }

int main()
{
    string ciudad;
    cout<<"Ingrese el nombre de la Ciudad que desea buscar el Clima: ";
    getline(cin,ciudad);

    getArchivo(ciudad);
    float temp_value = getTemperatura_Value(Nombre(ciudad));
    float temp_min = getTemperatura_Min(Nombre(ciudad));
    float temp_max = getTemperatura_Max(Nombre(ciudad));
    string clouds = getCloudsName(Nombre(ciudad));

    string value = Convert1(temp_value);
    string max_temp = Convert2(temp_max);
    string min_temp = Convert3(temp_min);


    sf::RenderWindow window(sf::VideoMode(500, 350), "CLIMADOX");

    sf::Texture fondo1;
    fondo1.loadFromFile("Fondo1.png");
    sf::Sprite fondo;
    fondo.setTexture(fondo1);
    fondo.setPosition(0, 0);

    sf::Texture text_nublado;
    text_nublado.loadFromFile("nublado.png");
    sf::Sprite sp_nublado;
    sp_nublado.setTexture(text_nublado);
    sp_nublado.setPosition(210, 10);

    sf::Texture text_dispersas;
    text_dispersas.loadFromFile("dispersas.png");
    sf::Sprite sp_dispersas;
    sp_dispersas.setTexture(text_dispersas);
    sp_dispersas.setPosition(210, 10);

    sf::Texture text_lluvia;
    text_lluvia.loadFromFile("lluvia.png");
    sf::Sprite sp_lluvia;
    sp_lluvia.setTexture(text_lluvia);
    sp_lluvia.setPosition(210, 10);

    sf::Texture text_cielo_azul;
    text_cielo_azul.loadFromFile("cielo_azul.png");
    sf::Sprite sp_cielo_azul;
    sp_cielo_azul.setTexture(text_cielo_azul);
    sp_cielo_azul.setPosition(210, 10);

    sf::Texture text_nubes_rotas;
    text_nubes_rotas.loadFromFile("nubes_rotas.png");
    sf::Sprite sp_nubes_rotas;
    sp_nubes_rotas.setTexture(text_nubes_rotas);
    sp_nubes_rotas.setPosition(210, 10);

    //sf::Text text;
    sf::Font font;
    font.loadFromFile("COMICATE.ttf");
    sf::Text text(ciudad, font);
    text.setCharacterSize(30);
    text.setPosition(10,160);
    text.setStyle(sf::Text::Bold);
    text.setColor(sf::Color::Green);

    sf::Text text1(value, font);
    text1.setCharacterSize(30);
    text1.setPosition(10,190);
    text1.setStyle(sf::Text::Bold);
    text1.setColor(sf::Color::Green);

    sf::Text text2(max_temp, font);
    text2.setCharacterSize(30);
    text2.setPosition(20,220);
    text2.setStyle(sf::Text::Bold);
    text2.setColor(sf::Color::Green);

    sf::Text text3(min_temp, font);
    text3.setCharacterSize(30);
    text3.setPosition(20,250);
    text3.setStyle(sf::Text::Bold);
    text3.setColor(sf::Color::Green);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }

        window.clear();
        window.draw(fondo);

        if(clouds == "overcast clouds")
        {
            window.draw(sp_nublado);
        }
        if(clouds == "clear sky")
        {
            window.draw(sp_cielo_azul);
        }
        if(clouds == "broken clouds")
        {
            window.draw(sp_nubes_rotas);
        }
        if(clouds == "scattered clouds")
        {
            window.draw(sp_dispersas);
        }
        window.draw(text);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.display();
    }
   return 0;

}
