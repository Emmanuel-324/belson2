#include "belson2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
belson2App::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

belson2App::belson2App(InputParameters parameters) : MooseApp(parameters)
{
  belson2App::registerAll(_factory, _action_factory, _syntax);
}

belson2App::~belson2App() {}

void 
belson2App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<belson2App>(f, af, s);
  Registry::registerObjectsTo(f, {"belson2App"});
  Registry::registerActionsTo(af, {"belson2App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
belson2App::registerApps()
{
  registerApp(belson2App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
belson2App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  belson2App::registerAll(f, af, s);
}
extern "C" void
belson2App__registerApps()
{
  belson2App::registerApps();
}
