#ifndef TIGERCUBAPP_H
#define TIGERCUBAPP_H

#include "MooseApp.h"

class tigercubApp;

template <>
InputParameters validParams<tigercubApp>();

class tigercubApp : public MooseApp
{
public:
  tigercubApp(InputParameters parameters);
  virtual ~tigercubApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* TIGERCUBAPP_H */
