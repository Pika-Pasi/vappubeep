#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <cstdio>
#include <string>

int main(void) {
	int i, noise, len, del, col1, col2;
	char str[255];
	std::string stdstr;
	srand(time(NULL));
	std::string colors[8];
	colors[0] = "black";
	colors[1] = "red";
	colors[2] = "green";
	colors[3] = "yellow";
	colors[4] = "blue";
	colors[5] = "magenta";
	colors[6] = "cyan";
	colors[7] = "white";

	sprintf(str, "setterm -bold on -reverse on");

	while(1) {noise = (rand() % 2300 ) + 700;
		len = (rand() % 139) + 1;
		del = (rand() % 14) + 1;
		sprintf(str, "beep -f %d -l %d -d %d", noise, len, del);
		system(str);
		sprintf(str, "%d", noise);
		stdstr.assign(str);
		for (i = 0; i < stdstr.length(); i++) {
			col1 = (rand() % 8);
			col2 = col1;
			while (col1 == col2) col2 = (rand() % 8);
			sprintf(str, "setterm -foreground %d -background %d", col1, col2);
			system(str);
			sprintf(str, "echo -n %c", stdstr[i]);
			system(str);
		}
		//usleep(del);
	}
	return 0;
}
