#include "stentApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
stentApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

stentApp::stentApp(InputParameters parameters) : MooseApp(parameters)
{
  stentApp::registerAll(_factory, _action_factory, _syntax);
}

stentApp::~stentApp() {}

void
stentApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"stentApp"});
  Registry::registerActionsTo(af, {"stentApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
stentApp::registerApps()
{
  registerApp(stentApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
stentApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  stentApp::registerAll(f, af, s);
}
extern "C" void
stentApp__registerApps()
{
  stentApp::registerApps();
}
