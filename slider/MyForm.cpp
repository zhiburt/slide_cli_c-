#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttibute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	slider::MyForm form;
	Application::Run(% form);
}