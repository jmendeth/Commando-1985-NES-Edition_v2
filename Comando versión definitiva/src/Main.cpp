#include <stdlib.h>
#include "Application.h"
#include "Globals.h"
#include "MemLeaks.h"
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

enum main_states
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};

Application* App = nullptr;
main_states state = MAIN_CREATION;
int main_return = EXIT_FAILURE;

int loop_tick() {
		switch (state)
		{
			case MAIN_EXIT:
				delete App;
				LOG("Bye :)\n");
				return -1;

			case MAIN_CREATION:
			{
				LOG("Application Creation --------------");
				App = new Application();
				state = MAIN_START;
			}	break;

			case MAIN_START:
			{
				LOG("Application Init --------------");
				if(App->Init() == false)
				{
					LOG("Application Init exits with error -----");
					state = MAIN_EXIT;
				}
				else
				{
					state = MAIN_UPDATE;
					LOG("Application Update --------------");
				}

			}	break;

			case MAIN_UPDATE:
			{
				int update_return = App->Update();

				if (update_return == UPDATE_ERROR)
				{
					LOG("Application Update exits with error -----");
					state = MAIN_EXIT;
				} else if (update_return == UPDATE_STOP)
					state = MAIN_FINISH;
			}
				break;

			case MAIN_FINISH:
			{
				LOG("Application CleanUp --------------");
				if(App->CleanUp() == false)
				{
					LOG("Application CleanUp exits with error -----");
				}
				else
					main_return = EXIT_SUCCESS;

				state = MAIN_EXIT;

			} break;

		}
		return 0;
}

#ifdef __EMSCRIPTEN__
void em_main_loop() {
	if (loop_tick() == 0) return;
	emscripten_cancel_main_loop();
	EM_ASM( gameExit() );
}
#endif

int main(int argc, char* argv[])
{
	ReportMemoryLeaks();
#ifdef __EMSCRIPTEN__
	EM_ASM( gameReady() );
	emscripten_set_main_loop(&em_main_loop, -1, 0);
	return 0;
#else
	while (loop_tick() == 0);
	return main_return;
#endif
}
