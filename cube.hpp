#ifndef CUBE_H
#define CUBE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

const int width = sf::VideoMode::getDesktopMode().size.x;
const int height = sf::VideoMode::getDesktopMode().size.y;

const int window_size_x = 1000; // width of the window
const int window_size_y = 1000; // height of the window
const float window_middle_x = window_size_x / 2.f; // x position of the middle of the window
const float window_middle_y = window_size_y / 2.f; // y position of the middle of the window
const float pos_left_x = 300.f; // x position of top-left vertex if (0, 0) is the top-left corner of the window
const float pos_top_y = 300.f; // y position of top-left vertex if (0, 0) is the top-left corner of the window
const float pos_right_x = window_size_x - pos_left_x; // x position of bottom-right vertex if (0, 0) is the top-left corner of the window
const float pos_bottom_y = window_size_y - pos_top_y; // y position of bottom-right vertex if (0, 0) is the top-left corner of the window
const float offset_from_midpoint_x = window_middle_x - pos_left_x; // distance from a vertex to a midpoint that is to the left or the right of it
const float offset_from_midpoint_y = window_middle_y - pos_top_y; // distance from a vertex to a midpoint that is above or below it

const float pi = 3.14159265f;
const float two_pi = pi * 2;
const float half_pi = pi / 2;
const float three_halves_pi = pi + half_pi;

void update(sf::VertexArray* square, float* x_uno, float* x_dos);

#endif