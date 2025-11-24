#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

namespace Euphoria::Systems {

    class System {
    public:
        virtual ~System() = default;

        static void RegisterBaseSystems();

        template <typename T, typename... Args>
        static void Add(Args&&... args) {
            auto system = std::make_shared<T>(std::forward<Args>(args)...);
            RegisteredSystems.push_back(system);
        }

        template <typename T>
        static void Remove() {
            RegisteredSystems.erase(
                std::remove_if(
                    RegisteredSystems.begin(),
                    RegisteredSystems.end(),
                    [](const std::shared_ptr<System>& sys) {
                        return std::dynamic_pointer_cast<T>(sys) != nullptr;
                    }
                ),
                RegisteredSystems.end()
            );
        }

        template<typename T>
        static std::shared_ptr<T> Get() {
            for (auto& sys : RegisteredSystems) {
                if (auto casted = std::dynamic_pointer_cast<T>(sys)) {
                    return casted;
                }
            }
            return nullptr;
        }

    private:
        static inline std::vector<std::shared_ptr<System>> RegisteredSystems;
        static inline bool RegisteredBaseSystems = false;
    };

}