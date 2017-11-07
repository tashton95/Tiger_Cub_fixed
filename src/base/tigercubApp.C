#include "tigercubApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<tigercubApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

tigercubApp::tigercubApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  tigercubApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  tigercubApp::associateSyntax(_syntax, _action_factory);
}

tigercubApp::~tigercubApp() {}

// External entry point for dynamic application loading
extern "C" void
tigercubApp__registerApps()
{
  tigercubApp::registerApps();
}
void
tigercubApp::registerApps()
{
  registerApp(tigercubApp);
}

void
tigercubApp::registerObjectDepends(Factory & /*factory*/)
{
}

// External entry point for dynamic object registration
extern "C" void
tigercubApp__registerObjects(Factory & factory)
{
  tigercubApp::registerObjects(factory);
}
void
tigercubApp::registerObjects(Factory & /*factory*/)
{
}

void
tigercubApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
tigercubApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  tigercubApp::associateSyntax(syntax, action_factory);
}
void
tigercubApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
