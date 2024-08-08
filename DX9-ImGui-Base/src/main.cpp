#include "gui.h"
#include <thread>


// This is the entry point for the windows application
int __stdcall wWinMain(HINSTANCE instance, HINSTANCE previousInstance, PWSTR arguments, int commandShow) {

	// makes da gui
	gui::CreateHWindow("Zeus Menu", "Zeus Menu Class");
	gui::CreateDevice();
	gui::CreateImGui();

	// render loop which will keep it running as long as gui::exit is true
	while (gui::exit) {

		gui::BeginRender();
		gui::Render();
		gui::EndRender();

		// to stop the loop from noming cpu, we sleep it for 10 milliseconds
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	// kills da gui
	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();

	return EXIT_SUCCESS;
}