

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew AirportDesktopApplication::MainForm());
	return 0;
}