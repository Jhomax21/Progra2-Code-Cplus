#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include<ctime>
#include<cstdlib>
using namespace Untitled12;
int main() {
	bool s;
	int v,a,f;
	srand(time(0));
	Application::Run(gcnew MyForm1());
	Application::Run(gcnew MyForm3());
	Application::Run(gcnew MyForm(s,v,a,f));
	Application::Run(gcnew MyForm2());
	return 0;
}
