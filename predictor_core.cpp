#include <iostream>
#include <cmath>
#include "include/kinematics.hpp"

// RPP: Physics Prediction Entry Point
int main() {
    std::cout << "[SYSTEM] Rocket Physics Predictor v2.6.0" << std::endl;
    std::cout << "[*] Initializing Kinematic Analysis Engine..." << std::endl;
    
    if (!Kinematics::HookSimulation()) {
        std::cerr << "[!] Error: Physics buffer not found." << std::endl;
        return 1;
    }

    std::cout << "[SUCCESS] Telemetry synchronized. Monitoring ball vectors..." << std::endl;

    while (true) {
        auto trajectory = Kinematics::PredictBallPath(5.0f); // Predict 5 seconds ahead
        Kinematics::RenderOverlay(trajectory);
        Sleep(1);
    }
    return 0;
}