#ifndef SFML_COLOR_HPP
#define SFML_COLOR_HPP

   // Headers
   #include <SFML/Graphics/Export.hpp>


   namespace sf
   {
   class SFML_GRAPHICS_API Color
    {
    public :
    Color();

    Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);

    // Static member data
    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Yellow;
    static const Color Magenta;
    static const Color Cyan;
    static const Color Transparent;

    // Member data
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
};

SFML_GRAPHICS_API bool operator ==(const Color& left, const Color& right);

SFML_GRAPHICS_API bool operator !=(const Color& left, const Color& right);

SFML_GRAPHICS_API Color operator +(const Color& left, const Color& right);

SFML_GRAPHICS_API Color operator *(const Color& left, const Color& right);

SFML_GRAPHICS_API Color& operator +=(Color& left, const Color& right);

SFML_GRAPHICS_API Color& operator *=(Color& left, const Color& right);

} // namespace sf

#endif // SFML_COLOR_HPP
