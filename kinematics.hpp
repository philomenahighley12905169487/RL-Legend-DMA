#pragma once
#include <vector>

namespace Kinematics {
    struct Vector3 { float x, y, z; };
    
    bool HookSimulation();
    void RenderOverlay(const std::vector<Vector3>& path);

    // Advanced reflection logic
    inline Vector3 CalculateBounce(Vector3 velocity, Vector3 surface_normal) {
        float dot = velocity.x * surface_normal.x + velocity.y * surface_normal.y + velocity.z * surface_normal.z;
        return { velocity.x - 2 * dot * surface_normal.x, 
                 velocity.y - 2 * dot * surface_normal.y, 
                 velocity.z - 2 * dot * surface_normal.z };
    }
}