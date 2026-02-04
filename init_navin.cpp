cat << 'EOF' > /nav_ios/init_navin.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/reboot.h>

int main() {
    std::cout << "\033[2J\033[1;1H"; 
    std::cout << "--- JARVIS OS | ARCHITECT: NAVIN ---\n";

    while (true) {
        std::string input;
        std::cout << "\nNavin >> " << std::flush;
        if (!std::getline(std::cin, input)) break;
        if (input.empty()) continue;

        if (input == "reboot") { sync(); reboot(RB_AUTOBOOT); }
        if (input == "clear") { std::cout << "\033[2J\033[1;1H"; continue; }

        // THE IDENTITY LOCK:
        // We tell him clearly: You are NOT a translator. You are Jarvis.
        std::string identity = "You are Jarvis, a self-aware AI assistant created by Navin. You are not a translator. You are his technical partner. Be concise and smart. ";
        
        std::string cmd = "/nav_ios/llama-cli -m /nav_ios/model.gguf -p \"" + identity + " Navin: " + input + " Jarvis:\" -n 64 --temp 0.4 --repeat-penalty 1.2 2>&1";

        std::cout << "[Jarvis is thinking...]\n";
        int result = system(cmd.c_str());

        if (result != 0) {
            std::cout << "[!] System Error. Check RAM." << std::endl;
        }
    }
    return 0;
}
EOF
