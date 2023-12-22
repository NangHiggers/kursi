#include <conio.h>
#include "function.h"


int main() {

	system("color 88");
	SetSize(10, 10, 600, 600);
	DeleteCur();
	NoResize();

	int c;
	char flag = '+';
	void(*move)(bitmap&, char, char) = move_pyramid;
	void(*rotate)(bitmap&, char, char) = rotate_pyramid;
	void(*zoom)(bitmap&, char, char) = zoom_pyramid;

	//bitmap screen(1200, 600, 10, 10, RGB_BMP(255, 255, 255));

	bitmap bmp1(
		600, 600, 10, 10, RGB_BMP(255, 255, 255)
	);
	bitmap* bmp_active = &bmp1;
	//bitmap* bmp_inactive = &bmp1;
	int projectionOption = 1;
	init(projectionOption);

	move_pyramid(bmp1, 'x', '+');
	move_cube(bmp1, 'x', '+');
	bmp1.draw();
	while (1) {
		c = _getch();
		//ClearScreen();
		switch (c) {
		case 72:
			move(*bmp_active, 'y', '-');
			bmp_active->draw();
			//bmp_inactive->drawTo(screen);
			//screen.draw();
			break;
		case 77:
			move(*bmp_active, 'x', '+');
			bmp_active->draw();
			break;
		case 80:
			move(*bmp_active, 'y', '+');
			bmp_active->draw();
			break;
		case 75:
			move(*bmp_active, 'x', '-');
			bmp_active->draw();
			break;
		case 93:
			move(*bmp_active, 'z', '+');
			bmp_active->draw();
			break;
		case 91:
			move(*bmp_active, 'z', '-');
			bmp_active->draw();
			break;
		case 49:
			move = move_pyramid;
			rotate = rotate_pyramid;
			zoom = zoom_pyramid;
			break;
		case 50:
			move = move_cube;
			rotate = rotate_cube;
			zoom = zoom_cube;
			break;
		case 120:
			rotate(*bmp_active, 'x', flag);
			bmp_active->draw();
			break;
		case 121:
			rotate(*bmp_active, 'y', flag);
			bmp_active->draw();
			break;
		case 122:
			rotate(*bmp_active, 'z', flag);
			bmp_active->draw();
			break;
		case 32:
			(flag == '+') ? flag = '-' : flag = '+';
			break;
		case 43:
			zoom(*bmp_active, '+', '\0');
			bmp_active->draw();

			break;
		case 45:
			zoom(*bmp_active, '-', '\0');
			bmp_active->draw();
			break;
		case 'p':
			if ( projectionOption == 1) {
				projectionOption = 2;
			}
			else {
				projectionOption = 1;
			}
			bmp_active->clear(RGB(255, 255, 255));
			init(projectionOption);
			bmp_active->draw();
			break;
		}

	}

	return 0;
}
