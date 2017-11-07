#include "tigercubTestApp.h"
#include "tigercubApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<tigercubTestApp>()
{
  InputParameters params = validParams<tigercubApp>();
  return params;
}

tigercubTestApp::tigercubTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  tigercubApp::registerObjectDepends(_factory);
  tigercubApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  tigercubApp::associateSyntaxDepends(_syntax, _action_factory);
  tigercubApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    tigercubTestApp::registerObjects(_factory);
    tigercubTestApp::associateSyntax(_syntax, _action_factory);
  }
}

tigercubTestApp::~tigercubTestApp() {}

// External entry point for dynamic application loading
extern "C" void
tigercubTestApp__registerApps()
{
  tigercubTestApp::registerApps();
}
void
tigercubTestApp::registerApps()
{
  registerApp(tigercubApp);
  registerApp(tigercubTestApp);
}

// External entry point for dynamic object registration
extern "C" void
tigercubTestApp__registerObjects(Factory & factory)
{
  tigercubTestApp::registerObjects(factory);
}
void
tigercubTestApp::registerObjects(Factory & /*factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
tigercubTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  tigercubTestApp::associateSyntax(syntax, action_factory);
}
void
tigercubTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
