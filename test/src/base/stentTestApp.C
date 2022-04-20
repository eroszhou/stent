//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "stentTestApp.h"
#include "stentApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
stentTestApp::validParams()
{
  InputParameters params = stentApp::validParams();
  return params;
}

stentTestApp::stentTestApp(InputParameters parameters) : MooseApp(parameters)
{
  stentTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

stentTestApp::~stentTestApp() {}

void
stentTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  stentApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"stentTestApp"});
    Registry::registerActionsTo(af, {"stentTestApp"});
  }
}

void
stentTestApp::registerApps()
{
  registerApp(stentApp);
  registerApp(stentTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
stentTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  stentTestApp::registerAll(f, af, s);
}
extern "C" void
stentTestApp__registerApps()
{
  stentTestApp::registerApps();
}
