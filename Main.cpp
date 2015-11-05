#include "Main.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace LightShow;

STAThreadAttribute;
int CALLBACK WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Main());
}