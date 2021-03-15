/* File: interface.i */
%module image
%{
   #include "image/clip.hpp"
   #include "image/pixel.hpp"
%}
%include "image/clip.hpp"
%include "image/pixel.hpp"
%rename(__add__) pixel::operator +;
%rename(__sub__) pixel::operator -;
%rename(__mul__) pixel::operator *;
%rename(__truediv__) pixel::operator /;
%rename(__pow__) pixel::operator ^;
%rename(__GT__) pixel::operator >;
%rename(__LT__) pixel::operator <;
%rename(__and__) pixel::operator &;
%rename(__or__) pixel::operator |;
%rename(__IADD__) pixel::operator +=;
%rename(__INVERT__) pixel::operator !;