#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					glTranslatef(0.0f, 1.0f, 0.0f);
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					glTranslatef(0.0f, -1.0f, 0.0f);
				}
				else if (event.key.code == sf::Keyboard::Left)
				{
					glTranslatef(-1.0f, 0.0f, 0.0f);
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					glTranslatef(1.0f, 0.0f, 0.0f);
				}
				else if (event.key.code == sf::Keyboard::Q)
				{
					glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
				}
				else if (event.key.code == sf::Keyboard::W)
				{
					glRotatef(rotationAngle, 0.0f, 0.0f, -1.0f);
				}
				else if (event.key.code == sf::Keyboard::E)
				{
					glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
				}
				else if (event.key.code == sf::Keyboard::R)
				{
					glRotatef(rotationAngle, 0.0f, -1.0f, 0.0f);
				}
				else if (event.key.code == sf::Keyboard::T)
				{
					glRotatef(rotationAngle, 1.0f, 0.0f, 0.0f);
				}
				else if (event.key.code == sf::Keyboard::Y)
				{
					glRotatef(rotationAngle, -1.0f, 0.0f, 0.0f);
				}
				else if (event.key.code == sf::Keyboard::A)
				{
					glScalef(1.005f, 1.005f, 1.0f);
				}
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	{
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(0.0,-2.0, -50.0);
		glVertex3f(-2.0, -6.0, -50.0);
		glVertex3f(2.0,-6.0, -50.0);
	}

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	{
		glColor3f(1.0,0.0,0.0);
		glVertex3f(10.0, -2.0, -50.0);
		glVertex3f(6.0, -6.0, -50.0);
		glVertex3f(12.0, -6.0, -50.0);
		glVertex3f(14.0, -2.0, -50.0);
		glVertex3f(10.0, -2.0, -50.0);

	}

	glEnd();

	glBegin(GL_POLYGON);
	{
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(10.0, 12.0, -50.0);
		glVertex3f(14.0, 12.0, -50.0);
		glVertex3f(17.0, 15.0, -50.0);
		glVertex3f(14.0, 18.0, -50.0);
		glVertex3f(10.0, 18.0, -50.0);
		glVertex3f(7.0, 15.0, -50.0);
	}
	glEnd();


	glBegin(GL_QUADS);
	{
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-10.0, 12.0, -50.0);
		glVertex3f(-6.0, 20.0, -50.0);
		glVertex3f(-12.0, 20.0, -50.0);
		glVertex3f(-14.0, 14.0, -50.0);

	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	{
		glColor3f(0.5, 0.5, 1.0);
		glVertex3f(0.0, 20.0, -50.0);
		glVertex3f(2.0, 20.0, -50.0);
		glVertex3f(-1.0, 16.0, -50.0);
		glVertex3f(3.0, 16.0, -50.0);
		glVertex3f(-4.0, 14.0, -50.0);
		glVertex3f(6.0, 14.0, -50.0);
	
	}
	glEnd();

	glBegin(GL_POINTS);
	{
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(0.0, -20.0, -50.0);
		glVertex3f(20.0, -20.0, -50.0);
		glVertex3f(-10.0, -16.0, -50.0);
		glVertex3f(13.0, -16.0, -50.0);
		glVertex3f(-14.0, -14.0, -50.0);
		glVertex3f(16.0, -14.0, -50.0);
	}
	glEnd();
	

	glBegin(GL_LINES);
	{
		glColor3f(1.0, 0.0, 1.0);
		glVertex3f(-10.0, 0.0, -50.0);
		glVertex3f(-12.0, 0.0, -50.0);
		glVertex3f(-10.0, 1.0, -50.0);
		glVertex3f(-12.0, 1.0, -50.0);
		glVertex3f(-10.0, 2.0, -50.0);
		glVertex3f(-12.0, 2.0, -50.0);
	}

	glEnd();

	glBegin(GL_LINE_LOOP);
	{
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-8.0, 2.0, -50.0);
		glVertex3f(-8.0, -2.0, -50.0);
		glVertex3f(-7.0, 2.0, -50.0);
		glVertex3f(-8.5, 0.0, -50.0);
		
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	{
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-8.0, -4.0, -50.0);
		glVertex3f(-8.0, -8.0, -50.0);
		glVertex3f(-7.0, -4.0, -50.0);
		glVertex3f(-6.5, -6.0, -50.0);

	}
	

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, 0.0, -50.0);
		glVertex3f(-2.0, 2.5, -50.0);
		glVertex3f(-0.75, 1.5, -50.0);
		glVertex3f(0.0, 3.0, -50.0);
		glVertex3f(0.75, 1.5, -50.0);
		glVertex3f(2.0, 2.5, -50.0);


	}

	glEnd();

	//glBegin(GL_LINES);
	//{
	//	glColor3f(0.0, 1.0, 0.0);
	//	glVertex3f(5.0, 7.0, -50.0);
	//	glVertex3f(3.0, 8.5, - 50.0);
	//	glVertex3f(4.0, 6.0, -50.0);
	//	glVertex3f(5.0, 9.0, -50.0);
	//	glVertex3f(6.0, 10.0, -50.0);
	//	glVertex3f(8.0, 10.5, -50.0);
	//
	//
	//}

	//glEnd();

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}




 
 



