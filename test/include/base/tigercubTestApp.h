#ifndef TIGERCUBTESTAPP_H
#define TIGERCUBTESTAPP_H

#include "MooseApp.h"

class tigercubTestApp;

template <>
InputParameters validParams<tigercubTestApp>();

class tigercubTestApp : public MooseApp
{
public:
  tigercubTestApp(InputParameters parameters);
  virtual ~tigercubTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* TIGERCUBTESTAPP_H */
