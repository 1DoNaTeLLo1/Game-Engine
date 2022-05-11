#include "app.h"

int main(int argc, char* args[])
{
	App *app = new App();
	app->Run();
	delete app;
	app = nullptr;

	return 0;
}