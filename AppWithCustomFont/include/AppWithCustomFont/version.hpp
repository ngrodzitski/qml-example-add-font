// clang-format off
#pragma once

#define APP_WITH_CUSTOM_FONT_VERSION_CODE( major, minor, patch ) \
    ( ( ( major ) << 16UL ) + ( ( minor ) << 8UL ) + ( ( patch ) << 0UL ))

#define APP_WITH_CUSTOM_FONT_VERSION_MAJOR 0ull
#define APP_WITH_CUSTOM_FONT_VERSION_MINOR 1ull
#define APP_WITH_CUSTOM_FONT_VERSION_PATCH 0ull

// Consider to insert real revision here on CI:
#define APP_WITH_CUSTOM_FONT_VCS_REVISION "n/a"

#define APP_WITH_CUSTOM_FONT_VERSION \
    APP_WITH_CUSTOM_FONT_VERSION_CODE( APP_WITH_CUSTOM_FONT_VERSION_MAJOR, APP_WITH_CUSTOM_FONT_VERSION_MINOR, APP_WITH_CUSTOM_FONT_VERSION_PATCH )

