#pragma once

namespace Euphoria::Input {
    // This is taken from the SFML::Mouse::Button enum, since I would like some kind of control over the mouse btuton for if we switch in the future.
	enum MouseButton {
        MouseLeft,   //!< The left mouse button
        MouseRight,  //!< The right mouse button
        MouseMiddle, //!< The middle (wheel) mouse button
        MouseExtra1, //!< The first extra mouse button
        MouseExtra2  //!< The second extra mouse button
	};
}