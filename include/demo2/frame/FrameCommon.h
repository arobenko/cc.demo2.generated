// Generated by commsdsl2comms v3.6.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    fields used in definition of @ref demo2::frame::Frame frame.

#pragma once

#include <cstdint>

namespace demo2
{

namespace frame
{

/// @brief Common types and functions of fields using in definition of
///     @ref demo2::frame::Frame frame.
/// @see demo2::frame::FrameLayers
struct FrameLayersCommon
{
    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref demo2::frame::FrameLayers::SyncMembers struct.
    struct SyncMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo2::frame::FrameLayers::SyncMembers::Sync field.
        struct SyncCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo2::frame::FrameLayers::SyncMembers::Sync field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref demo2::frame::FrameLayers::SyncMembers::Sync field.
            static const char* name()
            {
                return "Sync";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref demo2::frame::FrameLayers::ChecksumMembers struct.
    struct ChecksumMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo2::frame::FrameLayers::ChecksumMembers::Checksum field.
        struct ChecksumCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo2::frame::FrameLayers::ChecksumMembers::Checksum field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref demo2::frame::FrameLayers::ChecksumMembers::Checksum field.
            static const char* name()
            {
                return "Checksum";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref demo2::frame::FrameLayers::SizeMembers struct.
    struct SizeMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo2::frame::FrameLayers::SizeMembers::Size field.
        struct SizeCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo2::frame::FrameLayers::SizeMembers::Size field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref demo2::frame::FrameLayers::SizeMembers::Size field.
            static const char* name()
            {
                return "Size";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref demo2::frame::FrameLayers::VersionMembers struct.
    struct VersionMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo2::frame::FrameLayers::VersionMembers::Version field.
        struct VersionCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo2::frame::FrameLayers::VersionMembers::Version field.
            using ValueType = std::uint8_t;
        
            /// @brief Name of the @ref demo2::frame::FrameLayers::VersionMembers::Version field.
            static const char* name()
            {
                return "Version";
            }
            
        };
        
    };
    
};
} // namespace frame

} // namespace demo2


