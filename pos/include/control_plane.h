#pragma once

#include <iostream>
#include <vector>

#include <stdint.h>

#include "pos/include/common.h"
#include "pos/include/log.h"

enum pos_control_plane_role_id_t : uint8_t {
    kPOS_ControlPlane_RoleId_Server = 0,
    kPOS_ControlPlane_RoleId_Client
};

tempale<pos_control_plane_role_id_t T_Role>
class POSControlPlane {
    POSControlPlane(){}
    ~POSControlPlane() = default;  
    
};
