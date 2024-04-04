//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "belson2TestApp.h"
#include "belson2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
belson2TestApp::validParams()
{
  InputParameters params = belson2App::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

belson2TestApp::belson2TestApp(InputParameters parameters) : MooseApp(parameters)
{
  belson2TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

belson2TestApp::~belson2TestApp() {}

void
belson2TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  belson2App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"belson2TestApp"});
    Registry::registerActionsTo(af, {"belson2TestApp"});
  }
}

void
belson2TestApp::registerApps()
{
  registerApp(belson2App);
  registerApp(belson2TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
belson2TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  belson2TestApp::registerAll(f, af, s);
}
extern "C" void
belson2TestApp__registerApps()
{
  belson2TestApp::registerApps();
}
