// Copyright 2020 ros2_control Development Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef HARDWARE_INTERFACE__COMPONENTS__ACTUATOR_INTERFACE_HPP_
#define HARDWARE_INTERFACE__COMPONENTS__ACTUATOR_INTERFACE_HPP_

#include <memory>

#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "hardware_interface/types/hardware_interface_status_values.hpp"
#include "hardware_interface/visibility_control.h"

namespace hardware_interface
{
namespace components
{

/**
  * \brief Virtual Class to implement when integrating a 1 DoF actuator into ros2_control.
  * The typical examples are conveyors or motors.
  */
class ActuatorInterface
{
public:
  ActuatorInterface() = default;

  virtual
  ~ActuatorInterface() = default;

  /**
   * \brief Configuration of the actuator from data parsed from the robot's URDF.
   *
   * \param actuator_info structure with data from URDF.
   * \return return_type::OK if required data are provided and can be parsed,
   * return_type::ERROR otherwise.
   */
  HARDWARE_INTERFACE_PUBLIC
  virtual
  return_type configure(const HardwareInfo & actuator_info) = 0;

  /**
   * \brief Start exchange data with the hardware.
   *
   * \return return_type:OK if everything worked as expected, return_type::ERROR otherwise.
   */
  HARDWARE_INTERFACE_PUBLIC
  virtual
  return_type start() = 0;

  /**
   * \brief Stop exchange data with the hardware.
   *
   * \return return_type:OK if everything worked as expected, return_type::ERROR otherwise.
   */
  HARDWARE_INTERFACE_PUBLIC
  virtual
  return_type stop() = 0;

  /**
   * \brief Get current state of the system hardware.
   *
   * \return status current status.
   */
  HARDWARE_INTERFACE_PUBLIC
  virtual
  status get_status() const = 0;
};

}  // namespace components
}  // namespace hardware_interface
#endif  // HARDWARE_INTERFACE__COMPONENTS__ACTUATOR_INTERFACE_HPP_