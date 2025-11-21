#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <ctime>
#include <thread>
#include <mutex>

namespace Euphoria::Global {

#define ENGINE_NAME "Euphoria"

    // -------------------------
    // ARCHITECTURE
    // -------------------------
#if defined(_M_X64) || defined(__x86_64__) || defined(__amd64__)
#define EUPHORIA_X64
#elif defined(_M_IX86) || defined(__i386__)
#define EUPHORIA_X86
#elif defined(_M_ARM64) || defined(__aarch64__)
#define EUPHORIA_ARM64
#elif defined(_M_ARM) || defined(__arm__)
#define EUPHORIA_ARM
#else
#define EUPHORIA_UNKNOWN_ARCH
#endif

#if defined(EUPHORIA_X64)
#define EUPHORIA_ARCH_STRING "x64"
#elif defined(EUPHORIA_X86)
#define EUPHORIA_ARCH_STRING "x86"
#elif defined(EUPHORIA_ARM64)
#define EUPHORIA_ARCH_STRING "ARM64"
#elif defined(EUPHORIA_ARM)
#define EUPHORIA_ARCH_STRING "ARM"
#else
#define EUPHORIA_ARCH_STRING "Unknown Arch"
#endif

// -------------------------
// BUILD CONFIGURATION
// -------------------------
#if defined(_DEBUG) || !defined(NDEBUG)
#define EUPHORIA_DEBUG
#define EUPHORIA_CONFIGURATION_STRING "Debug"
#else
#define EUPHORIA_RELEASE
#define EUPHORIA_CONFIGURATION_STRING "Release"
#endif

#if defined(EUPHORIA_DEBUG) || defined(EUPHORIA_RELEASE)

// -------------------------
// COLORS
// -------------------------
#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_WHITE   "\x1b[37m"

// -------------------------
// LOGGING HELPERS
// -------------------------
    inline std::mutex& EuphoriaLogMutex() {
        static std::mutex mtx;
        return mtx;
    }

    inline void EuphoriaPrintTime(const char* color) {
        using namespace std::chrono;
        auto now = system_clock::now();
        auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;
        std::time_t t = system_clock::to_time_t(now);
        std::tm tm_info;
#if defined(_WIN32)
        localtime_s(&tm_info, &t);
#else
        localtime_r(&t, &tm_info);
#endif
        char buffer[13]; // HH:MM:SS.mmm
        std::strftime(buffer, sizeof(buffer), "%H:%M:%S", &tm_info);
        printf("[%s.%03lld]", buffer, static_cast<long long>(ms.count()));
    }

    inline const char* EuphoriaFileName(const char* path) {
        const char* file = strrchr(path, '/'); // UNIX-style
        if (!file) file = strrchr(path, '\\'); // Windows-style
        return file ? file + 1 : path;
    }

#define EUPHORIA_LOG_BASE(color, fmt, ...) \
    do { \
        std::lock_guard<std::mutex> lock(Euphoria::Global::EuphoriaLogMutex()); \
        printf(color); \
        Euphoria::Global::EuphoriaPrintTime(color); \
        printf(" [Euphoria] [%s:%s]: " fmt "\n" COLOR_RESET, \
               Euphoria::Global::EuphoriaFileName(__FILE__), __func__, ##__VA_ARGS__); \
    } while (0)

#define EUPHORIA_LOG(fmt, ...)     EUPHORIA_LOG_BASE(COLOR_WHITE, fmt, ##__VA_ARGS__)
#define EUPHORIA_WARNING(fmt, ...) EUPHORIA_LOG_BASE(COLOR_YELLOW, fmt, ##__VA_ARGS__)
#define EUPHORIA_ERROR(fmt, ...)   EUPHORIA_LOG_BASE(COLOR_RED, fmt, ##__VA_ARGS__)
#define EUPHORIA_ASSERT(cond, fmt, ...) \
    do { \
        if (!(cond)) { \
            EUPHORIA_ERROR("ASSERT FAILED: " fmt, ##__VA_ARGS__); \
            abort(); \
        } \
    } while (0)

#else
#define EUPHORIA_LOG(fmt, ...)
#define EUPHORIA_WARNING(fmt, ...)
#define EUPHORIA_ERROR(fmt, ...)
#define EUPHORIA_ASSERT(cond, fmt, ...)
#endif

    enum StackEvent { Update = 0, Render = 1, Quit = 2 };
    enum RenderingBackend { SFML };
    enum SpriteType { Circle, Rectangle };

    struct WindowCreationData {
        const char* WindowTitle;
        int WindowWidth;
        int WindowHeight;
    };

    struct ClearColourData {
        uint8_t r = 255, g = 255, b = 255, a = 255;
        ClearColourData() = default;
        ClearColourData(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_)
            : r(r_), g(g_), b(b_), a(a_) {
        }
    };

    struct RendererCreationData {
        ClearColourData BackgroundData;
    };

    struct EuphoriaPathsData {
        const char* ResourcesDirectory;
    };

    struct EuphoriaRuntimeInfo {
        bool HeadlessMode = false;
    };

    struct ApplicationCreationData {
        WindowCreationData WindowCreationData;
        RendererCreationData RendererCreationData;
        EuphoriaPathsData PathData;
        EuphoriaRuntimeInfo RuntimeInfo;
    };
}