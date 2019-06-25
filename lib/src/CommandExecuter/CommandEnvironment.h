/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#pragma once

#include <CommandExecuter/ExecuterState.h>

#include <string>
#include <vector>

namespace uibot {

class Scene;

using CommandError = std::string;

class CommandEnvironment {
public:
    CommandEnvironment(Scene& scene, ExecuterState& state);

    Scene& scene();
    ExecuterState& state();

private:
    Scene& m_scene;
    ExecuterState& m_state;
};

} // namespace uibot
