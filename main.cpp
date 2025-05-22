#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "cube.hpp"
/* when t = 0
front (uno):		3 2 <- right
			left->	1 0

left (dos):		 |->	3 6 <-.behind
		in front |->	1 4 <-

back (tres):		 |-> 6 7 <-| right 
				left |-> 4 5 <-|

right (cuatro):			 |-> 2 7 <-| behind
				in front |-> 0 5 <-|

top (cinco):		left behind	-> 6 7 <- right behind
					 left front -> 3 2 <- right front

bottom (seis):		left behind	-> 4 5 <- right behind
					 left front -> 1 0 <- right front
*/
void update(sf::VertexArray* square, float* x_uno, float* x_dos)
{
	(*square)[0].position = sf::Vector2(*x_uno, pos_bottom_y);
	(*square)[1].position = sf::Vector2(*x_dos, pos_bottom_y);
	(*square)[2].position = sf::Vector2(*x_uno, pos_top_y);
	(*square)[3].position = sf::Vector2(*x_dos, pos_top_y);
}

int main()
{
	// initialize the six squares of the cube
	sf::VertexArray square_uno(sf::PrimitiveType::TriangleStrip, 4);
	sf::VertexArray square_dos(sf::PrimitiveType::TriangleStrip, 4);
	sf::VertexArray square_tres(sf::PrimitiveType::TriangleStrip, 4);
	sf::VertexArray square_cuatro(sf::PrimitiveType::TriangleStrip, 4);
	//sf::VertexArray square_cinco(sf::PrimitiveType::TriangleStrip, 4);
	//sf::VertexArray square_seis(sf::PrimitiveType::TriangleStrip, 4);

	// define the vertexes
	sf::Vector2f vertex_zero = sf::Vector2f(pos_right_x, pos_bottom_y);
	sf::Vector2f vertex_one = sf::Vector2f(pos_left_x, pos_bottom_y);
	sf::Vector2f vertex_two = sf::Vector2f(pos_right_x, pos_top_y);
	sf::Vector2f vertex_three = sf::Vector2f(pos_left_x, pos_top_y);
	sf::Vector2f vertex_four = sf::Vector2f(pos_right_x, pos_bottom_y);
	sf::Vector2f vertex_five = sf::Vector2f(pos_left_x, pos_bottom_y);
	sf::Vector2f vertex_six = sf::Vector2f(pos_right_x, pos_top_y);
	sf::Vector2f vertex_seven = sf::Vector2f(pos_left_x, pos_top_y);;
	
	// define the position of the vertices for each square
	// format:
	// square[0]: bottom-right
	// square[1]: bottom-left
	// square[2]: top-right
	// square[3]: top-left

	
	square_uno[0].position = vertex_zero;
	square_uno[1].position = vertex_one;
	square_uno[2].position = vertex_two;
	square_uno[3].position = vertex_three;

	square_dos[0].position = vertex_one;
	square_dos[1].position = vertex_four;
	square_dos[2].position = vertex_three;
	square_dos[3].position = vertex_six;

	square_tres[0].position = vertex_four;
	square_tres[1].position = vertex_five;
	square_tres[2].position = vertex_six;
	square_tres[3].position = vertex_seven;

	square_cuatro[0].position = vertex_seven;
	square_cuatro[1].position = vertex_zero;
	square_cuatro[2].position = vertex_five;
	square_cuatro[3].position = vertex_two;

	/*square_cinco[0].position = vertex_two;
	square_cinco[1].position = vertex_three;
	square_cinco[2].position = vertex_seven;
	square_cinco[3].position = vertex_six;

	square_seis[0].position = vertex_zero;
	square_seis[1].position = vertex_one;
	square_seis[2].position = vertex_five;
	square_seis[3].position = vertex_four;*/



	// define the colors
	square_uno[0].color = sf::Color::Magenta;
	square_uno[1].color = sf::Color::Green;
	square_uno[2].color = sf::Color::Magenta;
	square_uno[3].color = sf::Color::Green;

	square_dos[0].color = sf::Color::Green;
	square_dos[1].color = sf::Color::Green;
	square_dos[2].color = sf::Color::Green;
	square_dos[3].color = sf::Color::Green;

	square_tres[0].color = sf::Color::Magenta;
	square_tres[1].color = sf::Color::Green;
	square_tres[2].color = sf::Color::Magenta;
	square_tres[3].color = sf::Color::Green;

	square_cuatro[0].color = sf::Color::Magenta;
	square_cuatro[1].color = sf::Color::Magenta;
	square_cuatro[2].color = sf::Color::Magenta;
	square_cuatro[3].color = sf::Color::Magenta;

	/*square_cinco[0].color = sf::Color::Magenta;
	square_cinco[1].color = sf::Color::Green;
	square_cinco[2].color = sf::Color::Green;
	square_cinco[3].color = sf::Color::Magenta;

	square_seis[0].color = sf::Color::Magenta;
	square_seis[1].color = sf::Color::Green;
	square_seis[2].color = sf::Color::Green;
	square_seis[3].color = sf::Color::Magenta;*/

	// set up the wack pointer thing


	// get to drawing
	float timer = 0.f; //timer. i think this is self-explanatory
	sf::Clock clock;
	sf::VertexArray* square_first; //will be either square_uno or square_tres
	float* first_uno; //first x-pos for square_first
	float* first_dos; //second x-pos for square_first

	sf::VertexArray* square_second; //will be either square_dos or square_cuatro
	float* second_uno; //first x-pos for square_second
	float* second_dos; //second x-pos for square_second

	float pos_x_vertex_zero_two; //x-pos for vertices zero and two
	float pos_x_vertex_one_three; //x-pos for vertices one and three
	
	float pos_x_vertex_four_six; //x-pos for vertices four and six
	float pos_x_vertex_five_seven; //x-pos for vertices five and seven
	
	long int result_uno; //for skipping an if/else statement when comparing (pos_x_vertex_zero_two < pos_x_vertex_one_three)
	long int result_dos; //for skipping an if/else statement when comparing (pos_x_vertex_one_three < pos_x_vertex_four_six)

	// i'm sorry
	long int evil_pointer_math_uno = (long int)(&pos_x_vertex_zero_two)-(long int)(&pos_x_vertex_five_seven);
	long int evil_pointer_math_dos = (long int)(&pos_x_vertex_one_three)-(long int)(&pos_x_vertex_four_six);
	long int evil_pointer_math_tres = (long int)(&square_uno)-(long int)(&square_tres);

	long int evil_pointer_math_cuatro = (long int)(&pos_x_vertex_one_three)-(long int)(&pos_x_vertex_zero_two);
	long int evil_pointer_math_cinco = (long int)(&pos_x_vertex_four_six)-(long int)(&pos_x_vertex_five_seven);
	long int evil_pointer_math_seis = (long int)(&square_dos)-(long int)(&square_cuatro);

	//window
	sf::RenderWindow window(sf::VideoMode({ window_size_x, window_size_y }), "why does this work");
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
				clock.stop();
			}
		}

		window.clear();


		pos_x_vertex_zero_two = cos(timer) * offset_from_midpoint_x + window_middle_x; 
		pos_x_vertex_one_three = cos(timer + half_pi) * offset_from_midpoint_x + window_middle_x;

		pos_x_vertex_four_six = cos(timer + pi) * offset_from_midpoint_x + window_middle_x;
		pos_x_vertex_five_seven = cos(timer - half_pi) * offset_from_midpoint_x + window_middle_x;

		// Forgive me Dennis Ritchie, for I have sinned
		// I wanted to skip using any if statements here, so I used some unholy bit-level pointer math
		// I also scared myself while testing the program several times. 
		// Let's just say on several occasions I had to close the program VERY QUICKLY and pray I didn't just kill my laptop

		//if pos_x_vertex_zero_two is less than pos_x_vertex_one_three, result_uno will equal 0xFFFFFFFFFFFFFFFF after this. otherwise, it will equal 0x0000000000000000
		result_uno = ((((long int)(pos_x_vertex_zero_two < pos_x_vertex_one_three)) << 31) >> 31);
		//if pos_x_vertex_one_three is less than pos_x_vertex_four_six, result_dos will equal 0xFFFFFFFFFFFFFFFF after this. otherwise, it will equal 0x0000000000000000
		result_dos = ((((long int)(pos_x_vertex_one_three < pos_x_vertex_four_six)) << 31) >> 31);

		//if (pos_x_vertex_zero_two < pos_x_vertex_one_three), use pos_x_vertex_zero_two. otherwise, use pos_x_vertex_five_seven
		first_uno = (float*)((result_uno & evil_pointer_math_uno) + (long int)(&pos_x_vertex_five_seven));
		//if (pos_x_vertex_zero_two < pos_x_vertex_one_three), use pos_x_vertex_one_three. otherwise, use pos_x_vertex_four_six
		first_dos = (float*)((result_uno & evil_pointer_math_dos) + (long int)(&pos_x_vertex_four_six));
		//if (pos_x_vertex_zero_two < pos_x_vertex_one_three), display square_uno. otherwise, display square_tres
		square_first = (sf::VertexArray*)((result_uno & evil_pointer_math_tres) + (long int)(&square_tres));
		
		//if (pos_x_vertex_one_three < pos_x_vertex_four_six), use pos_x_vertex_one_three. otherwise, use pos_x_vertex_zero_two
		second_uno = (float*)((result_dos & evil_pointer_math_cuatro) + (long int)(&pos_x_vertex_zero_two));
		//if (pos_x_vertex_one_three < pos_x_vertex_four_six), use pos_x_vertex_four_six. otherwise, use pos_x_vertex_five_seven
		second_dos = (float*)((result_dos & evil_pointer_math_cinco) + (long int)(&pos_x_vertex_five_seven));
		//if (pos_x_vertex_one_three < pos_x_vertex_four_six), display square_dos. otherwise, display square_cuatro
		square_second  = (sf::VertexArray*)((result_dos & evil_pointer_math_seis) + (long int)(&square_cuatro));


		/*if (pos_x_vertex_zero_two < pos_x_vertex_one_three)
		{
			square_first = &square_uno;
			first_uno = pos_x_vertex_zero_two;
			first_dos = pos_x_vertex_one_three;
		}
		else
		{
			square_first = &square_tres;
			first_uno = pos_x_vertex_five_seven;
			first_dos = pos_x_vertex_four_six;
		}
		if (pos_x_vertex_one_three < pos_x_vertex_four_six)
		{
			square_second = &square_dos;
			second_uno = pos_x_vertex_one_three;
			second_dos = pos_x_vertex_four_six;
		}
		else
		{
			square_second = &square_cuatro;
			second_uno = pos_x_vertex_zero_two; 
			second_dos = pos_x_vertex_five_seven;
		}*/
		update(square_first, first_uno, first_dos);
		update(square_second, second_uno, second_dos);

		window.draw(*square_first);
		window.draw(*square_second);
		
		window.display();
		timer += (clock.restart().asSeconds());
		// one complete rotation in two seconds
		// cos(0) = 1, cos(pi) = -1, cos(2pi) = 1
		
	}
}