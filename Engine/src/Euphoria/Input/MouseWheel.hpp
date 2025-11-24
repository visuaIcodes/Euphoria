#pragma once

namespace Euphoria::Input {
    // This is taken from the SFML::Mouse::Wheel enum, since I would like some kind of control over the wheel stuff for if we switch in the future.
    enum MouseWheel {
        Left,   //!< The left mouse button
        Right,  //!< The right mouse button
        Middle, //!< The middle (wheel) mouse button
        Extra1, //!< The first extra mouse button
        Extra2  //!< The second extra mouse button
    };
}