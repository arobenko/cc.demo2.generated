// Generated by commsdsl2comms v3.6.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo2::Message interface fields.

#pragma once

#include <cstdint>

namespace demo2
{

/// @brief Common types and functions for fields of 
///     @ref demo2::Message interface.
/// @see demo2::MessageFields
struct MessageFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref demo2::MessageFields::Version field.
    struct VersionCommon
    {
        /// @brief Re-definition of the value type used by
        ///     demo2::MessageFields::Version field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref demo2::MessageFields::Version field.
        static const char* name()
        {
            return "Version";
        }
        
    };
    
};
} // namespace demo2


